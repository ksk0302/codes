#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define EMPTY (-1)
#define WHITE (0)
#define BLACK (1)

//盤面を表示する関数
void display_board(int N, int board[N+1][N+1]) {
  int i,j;
  printf("   ");
  for(i=0; i<N; i++) {
    printf(" %2d ",i+1);
  }
  printf("\n");
  for(i=0; i<N; i++) {
    printf("    ");
    for(j=0; j<N; j++) {
      printf(" ― ");
    }
    printf("\n");
    printf("%2d |",i+1);
    for(j=0; j<N; j++) {
      if(board[i][j] == WHITE) {
	printf(" ●|");
      } else if(board[i][j] == BLACK) {
	printf(" ○|");
      } else {
	printf("   |");
      }
    }
    printf("\n");
  }
  printf("    ");
  for(i=0; i<N; i++) {
    printf(" ― ");
  }
}

//指定されたマスに石を置けるかどうかを判断する関数
int Puttable(int x, int y, int N, int color, int opp_color, int board[N+1][N+1]) {
  int i,j,k;
  int count=0;

  if(board[x][y]!=EMPTY) {
    return 0;
  }

  for(i=-1; i<2; i++) {
    for(j=-1; j<2; j++) {
      if(i==0 && j==0) {
	continue;
      }
      if(board[x+i][y+j]!=opp_color) {
	continue;
      }
      for(k=2; k<N; k++) {
	if( (x+i*k>=0) && (x+i*k<N) && (y+j*k>=0) && (y+j*k<N) ) {
	  if(board[x+i*k][y+j*k]==EMPTY) {
	    break;
	  }
	  if(board[x+i*k][y+j*k]==color) {
	    count++;
	  }
	}
      }
    }
  }
  if(count == 0) {
    return 0;
  }
  return 1;
}

//COM1の関数
void COM1(int *x, int *y, int N, int color, int opp_color, int board[N+1][N+1]) {
  int a = *x;
  int b = *y;
  
  while(Puttable(a,b,N,color,opp_color,board) == 0) {
    a = 0 + (int)( rand()*( (N-1)-0+1.0 )/(1.0+RAND_MAX) );
    b = 0 + (int)( rand()*( (N-1)-0+1.0 )/(1.0+RAND_MAX) );
  }
  *x = a; *y = b;
}

//COM2の関数
void COM2(int N, int color, int opp_color, int board[N+1][N+1], int maximum_move[N][N]) {
  int i,j,k,l,m;
  int count,COUNT,max=-1; //石を返せる枚数を計算するのに使用

  //マスを全て探索
  for(l=0; l<N; l++) {
    for(m=0; m<N; m++) {
      COUNT=0;
      //周囲8方向を探索
      for(i=-1; i<2; i++) {
	for(j=-1; j<2; j++) {
	  //1,7行1,7列にいる場合範囲外の探索をする必要はない
	  if( (i==-1&&l==0) || (i==1&&l==N-1) || (j==-1&&m==0) || (j==1&&m==N-1) || (i==0&&j==0) ) {
	    continue;
	  }
	  if( board[l][m]!=EMPTY ) {
	    continue;
	  }
	  //隣のマスが違う色でない場合は探索をする必要はない
	  if( board[l+i][m+j]!=opp_color ) {
	    continue;
	  }
	  count=0;
	  //現在の方向において盤面の端まで探索
	  for(k=2; k<N; k++) {
	    //盤面の範囲を超えない範囲での探索のみ行う
	    if( (l+i*k >= 0) && (l+i*k < N) && (m+j*k >= 0) && (m+j*k < N) ) {
	      if(board[l+i*k][m+j*k]==EMPTY) {
		break;
	      }
	      if(board[l+i*k][m+j*k]==color) {
		//裏返せる石の数をカウント
		count++;
	      }
	    }
	  }
	  //8方向のカウント数を合計
	  COUNT+=count;
	}
      }
      if(COUNT>max) {
	max=COUNT;
      }
      maximum_move[l][m]=COUNT;
    }
  }
}
/*
void COM3() {
}*/

int main() {
  int i,j,k,l,m;                   //カウンタ
  int x,y;                         //石をどこに置くか
  int color,opp_color;             //色
  int step=0;                      //現在のターン数
  int possible_to_place_or_not=0;  //石を置けるかどうか
  int opponent;                    //相手の判別
  int N;                           //ボードの大きさ
  int end=0;                       //終了判定
  int level;                       //敵の強さ

  //ゲーム開始
  printf("Let's play othello (オセロをしよう！)\n");
  printf("Enter an board size(EVEN NUMBER) (ボードの大きさ(偶数)を入力してください)："); scanf("%d",&N);
  printf("Choose your opponent (COM：0 or HUMAN：1) (対戦相手を選択してください (コンピュータ：0 または 人間：1))："); scanf("%d",&opponent);
  if(opponent==0) {
    printf("Choose the strength of your opponent (EASY：1 or NORMAL：2 or HARD：3) (対戦相手の強さを選択してください (すごく弱い：1 または 弱い：2)："); scanf("%d",&level);
  }
  printf("\nYOU(あなた)：BLACK ( ○ )\n");
  printf("OPP  (相手)：WHITE ( ● )\n");
  printf("\nGAME START\n\n\n");

  //盤面の用意
  int board[N+1][N+1];
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      board[i][j] = -1;
    }
  }
  board[(N/2)-1][N/2] = BLACK;
  board[N/2][(N/2)-1] = BLACK;
  board[N/2][N/2] = WHITE;
  board[(N/2)-1][(N/2)-1] = WHITE;
  //用意終了

  //盤面表示
  display_board(N,board);

  do {
    
  if(step%2 == 0) {
    color = BLACK;
    opp_color = WHITE;
    printf( "\nBlack's turn (黒の番)\n" );
  } else {
    color = WHITE;
    opp_color = BLACK;
    printf( "\nWhite's turn (白の番)\n" );
  }

  //どこにも石を置けない場合を探索
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      for(k=-1; k<2; k++) {
	for(l=-1; l<2; l++) {
	  //余計な探索を減らす
	  if( (k==-1&&i==0) || (k==1&&i==N) || (l==-1&&j==0) || (l==1&&j==N) || (k==0&&l==0) ) {
	    continue;
	  }
	  if( board[i+k][j+l]!=opp_color ) {
	    continue;
	  }
	  if( board[i][j]!=EMPTY ) {
	    continue;
	  }
	  //現在の方向において盤面の端まで探索
	  for(m=1; m<N; m++) {
	    //盤面の範囲を超えない範囲での探索のみ行う
	    if( (i+k*m >= 0) && (i+k*m < N) && (j+l*m >= 0) && (j+l*m < N) ) {
	      if( board[i+k*m][j+l*m]==EMPTY ) {
	        break;
	      }
	      if( board[i+k*m][j+l*m]==color ) {
	        possible_to_place_or_not++;
	      }
	    }
	  }
	}
      }
    }
  }
  int black_turn,white_turn;  //終了条件の判定に使用
  if(possible_to_place_or_not==0) {
    printf("You cannot place a stone anywhere. (どこにも石を置けません) You pass. (パスします)\n\n");
    if(color==BLACK) {
      black_turn=step;
    } else {
      white_turn=step;
    }
  }
  //どこかに石を置ける場合
  else {
    //黒か人間の白のターンの場合
    if(color==BLACK || opponent==1) {
      printf( "Input cell (マスを選択してください) (x y)\n" );
      scanf( "%d %d", &x, &y );
      printf("\n\n");
      while(x<1 || x>N || y<1 || y>N) {
	printf("Enter a number within the range. (ボードの範囲内の数字を入力してください)\n");
	printf( "Input cell (マスを選択してください) (x y)\n" );
	scanf( "%d %d", &x, &y );
	printf("\n\n");
      }
      x--; y--;  /* 配列番号が0番から始まるため． */

      //指定されたマスに石を置けるかどうかの判定
      int put_flag=1;
      
      //マスが空白の場合は石を置けない
      if( board[x][y] != EMPTY ) {
	put_flag=0;
      }

      while(Puttable(x,y,N,color,opp_color,board)==0 || put_flag==0) {
	printf("You cannot place a stone in the cell.(そのマスには石を置けません) Please select the cell again.(もう一度マスを選択してください)\n\n");
	printf( "Input cell (マスを選択してください) (x y)\n" );
	scanf( "%d %d", &x, &y );
	printf("\n\n");
	x--; y--;
	if( board[x][y] == EMPTY ) {
	  put_flag=1;
	}
      }
    }

    //COMの場合
    else if(opponent==0) {
      if(level == 1) {
	int x1,y1;
	x1 = 0 + (int)( rand()*( (N-1)-0+1.0 )/(1.0+RAND_MAX) );
	y1 = 0 + (int)( rand()*( (N-1)-0+1.0 )/(1.0+RAND_MAX) );
	sleep(2);
	COM1(&x1,&y1,N,color,opp_color,board);
	x = x1;
	y = y1;
	printf("COM input cell (%d %d)\n\n\n",x+1,y+1);
      } else if(level == 2) {
	int maximum_move[N][N],max=-1;
	sleep(2);  //画面の切り替わりが速すぎるため間を置く
	COM2(N,color,opp_color,board,maximum_move);
	for(i=0;i<N;i++) {
	  for(j=0;j<N;j++ ) {
	  //カウント結果の最大値とその時の座標を得る
	    if( max<maximum_move[i][j] ) {
	      max=maximum_move[i][j];
	      x=i; y=j;
	    }
	  }
	}
	printf("COM input cell (%d %d)\n\n\n",x+1,y+1);
      } else {
      }
    }

    board[x][y] = color; /* 選んだマスに石を置く */

      //挟まれた石を裏返していく
      for(i=-1; i<2; i++) {
	for(j=-1; j<2; j++) {
	  if( (i==-1&&x==0) || (i==1&&x==N-1) || (j==-1&&y==0) || (j==1&&y==N-1) || (i==0&&j==0) ) {
	    continue;
	  }
	  if(board[x+i][y+j]!=opp_color) {
	    continue;
	  }
	  for(k=2; k<N; k++) {
	    if( (x+i*k >= 0) && (x+i*k < N) && (y+j*k >= 0) && (y+j*k < N) ) {
	      if(board[x+i*k][y+j*k]==EMPTY) {
		break;
	      }
	      if(board[x+i*k][y+j*k]==color) {
		for(l=1; l<k; l++) {
		  //裏返している途中違う色でなくなったらループを抜ける
		  if(board[x+i*l][y+j*l]!=opp_color) {
		    break;
		  }
		  //セルを裏返す
		  if(board[x+i*l][y+j*l]==opp_color) {
		    board[x+i*l][y+j*l]=color;
		  }
		}
	      }
	    }
	  }
	}
      }
    }

    //盤面の表示
    display_board(N,board);

    //黒，白，空白のセルの数を数える
    int count_of_black=0,count_of_white=0,count_of_empty=0;
    for(i=0; i<N; i++) {
      for(j=0; j<N; j++) {
	if(board[i][j]==BLACK) {
	  count_of_black++;
	} else if(board[i][j]==WHITE) {
	  count_of_white++;
	} else {
	  count_of_empty++;
	}
      }
    }
    //空白が0個なら終了
    if(count_of_empty==0) {
      if(count_of_black>count_of_white) {
	printf("\nRESULT\nBLACK = %d  WHITE = %d\n",count_of_black,count_of_white);
	printf("BLACK wins (黒の勝利！)\n\n");
	end=1;
      } else if(count_of_black<count_of_white) {
	printf("\nRESULT\nBLACK = %d  WHITE = %d\n",count_of_black,count_of_white);
	printf("WHITE wins (白の勝利！)\n\n");
	end=1;
      } else {
	printf("RESULT\nBLACK = %d  WHITE = %d\n",count_of_black,count_of_white);
	printf("draw (引き分け)\n\n");
	end=1;
      }
    }
    //黒の数が0個なら終了
    else if(count_of_black==0) {
      printf("RESULT\nBLACK = %d  WHITE = %d\n",count_of_black,count_of_white);
      printf("WHITE wins (白の勝利！)\n\n");
      end=1;
    }
    //白の数が0個なら終了
    else if(count_of_white==0) {
      printf("RESULT\nBLACK = %d  WHITE = %d\n",count_of_black,count_of_white);
      printf("BLACK wins (黒の勝利！)\n\n");
      end=1;
    }
    //黒も白も石を置けない状態で黒が多ければ黒の勝利
    else if((black_turn-white_turn==1 || white_turn-black_turn==1) && (count_of_black<count_of_white )) {
      printf("RESULT\nBLACK = %d  WHITE = %d\n",count_of_black,count_of_white);
      printf("WHITE wins (白の勝利！)\n\n");
      end=1;
    }
    //黒も白も石を置けない状態で白が多ければ白の勝利
    else if((black_turn-white_turn==1 || white_turn-black_turn==1) && (count_of_black>count_of_white )) {
      printf("RESULT\nBLACK = %d  WHITE = %d\n",count_of_black,count_of_white);
      printf("BLACK wins (黒の勝利！)\n\n");
      end=1;
    }

    //現在のターン数を更新
    step++;

  } while(end==0);

  return 0;
}