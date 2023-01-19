#include<stdio.h>
#include<stdlib.h>   //rand関数を使用するために必要
#include<time.h>     //time関数を使用するために必要

#define MS_SIZE 8    //ゲームボードのサイズ(変更不可)

int main() {
  int mode;          //モードを保持（モード：セルを開く，フラグを立てる/除去する）
  int number_of_mines;                              //地雷数のデフォルト値は10
  int mine_map[MS_SIZE+2][MS_SIZE+2]={{0},{0}};     //地雷セルと数字セルを記録
  int game_board[MS_SIZE+2][MS_SIZE+2]={{0},{0}};   //ゲームの進行を記録するためのゲームボード
  int i,j;                                          //カウンタ変数
  int x,y;                                          //セルの値を記憶する変数
  int count_of_cell_with_no_mine=0;                 //地雷が無いセルの数を数える変数
  int continue_or_not=1;                            //終了条件（予め1を代入しておく）

  /*  地雷の数の入力を受け取る  */
  printf("設置する地雷の数を入力してください：");
  scanf("%d",&number_of_mines);
  //条件に反する数が入力された場合
  while(number_of_mines>MS_SIZE*MS_SIZE || number_of_mines<1) {
    printf("1以上%d以下の整数を入力してください：",MS_SIZE*MS_SIZE);
    scanf("%d",&number_of_mines);
  }
  
  do {
    srand((unsigned)time(NULL));  //time関数で現在時刻を取得し，乱数を初期化する．
    for(i=0;i<number_of_mines;i++) {
      do {
        x = rand()%(MS_SIZE-1)+0;
        y = rand()%(MS_SIZE-1)+0;
      } while(mine_map[x][y]!=0);
      mine_map[x][y]=-1;
    }

    for(i=0;i<MS_SIZE;i++) {
      for(j=0;j<MS_SIZE;j++) {
	//自身が地雷セルでなく，かつ8近傍のセルが地雷セルであった場合，インクリメント
        if(mine_map[i+1][j+1]==-1 && mine_map[i][j]!=-1) {
	  mine_map[i][j]++;
        }
        if(mine_map[i+1][j]==-1 && mine_map[i][j]!=-1) {
	  mine_map[i][j]++;
        }
        if(mine_map[i+1][j-1]==-1 && mine_map[i][j]!=-1) {
	  mine_map[i][j]++;
        }
        if(mine_map[i][j+1]==-1 && mine_map[i][j]!=-1) {
  	  mine_map[i][j]++;
        }
        if(mine_map[i][j-1]==-1 && mine_map[i][j]!=-1) {
	  mine_map[i][j]++;
        }
        if(mine_map[i-1][j+1]==-1 && mine_map[i][j]!=-1) {
	  mine_map[i][j]++;
        }
        if(mine_map[i-1][j]==-1 && mine_map[i][j]!=-1) {
	  mine_map[i][j]++;
        }
        if(mine_map[i-1][j-1]==-1 && mine_map[i][j]!=-1) {
 	  mine_map[i][j]++;
        }
      }
    }
    
    //初期状態の盤面を表示
    printf("\n[y]\n\n");
    for(i=0;i<MS_SIZE;i++) {
      printf("%2d|",i);
      for(j=0;j<MS_SIZE;j++) {
        printf("  x");
      }
      printf("\n");
    }
    printf("   ");
    for(i=0;i<2;i++) {
      for(j=0;j<MS_SIZE;j++) {
        if(i==0) {
	  printf("---");
        } else if(i==1 && j==0) {
	  printf("   %3d",j);
        } else {
	  if(j==MS_SIZE-1) {
	    printf("%3d  [x]",j);
  	  } else {
	    printf("%3d",j);
	  }
        }
      }
      printf("\n");
    }
    //盤面の表示終了
    
    do {
      printf("\nモードを選択してください：セルを開く（1），フラグ（F）を設置/除去する（2）：");
      scanf("%d",&mode);
      //1か2が入力されなかった場合
      while(mode!=1 && mode!=2) {
        printf("1か2を入力してください：");
        scanf("%d",&mode);
      }
      //取り扱うセルを指定
      printf("セルを指定してください：\n");
      printf("列番号x：");
      scanf("%d",&x);
      //範囲外の列が出力された場合を除く
      while(x<0 || x>MS_SIZE) {
	printf("0から%dまでの整数を入力してください：",MS_SIZE-1);
	scanf("%d",&x);
      }
      printf("行番号y：");
      scanf("%d",&y);
      //範囲外の行が出力された場合を除く
      while(y<0 || y>MS_SIZE) {
	printf("0から%dまでの整数を入力してください：",MS_SIZE-1);
	scanf("%d",&y);
      }
      if(mode==1) {
        if(mine_map[y][x]!=-1) {
	  //指定されたセルが地雷セルでない場合，そのセルと地雷セルでない8近傍のセルのgame_boardに1を与える
 	  for(i=y+1;i>=y-1;i--) {
	    for(j=x+1;j>=x-1;j--) {
	      if(mine_map[i][j]!=-1) {
	        game_board[i][j]=1;
	      }
	    }
  	  }
        }
	else {
	  //地雷セルを指定した場合
          printf("\nGame Over!\n");
          continue_or_not=0;
        }
      }
      else {
        if(game_board[y][x]==2) {
          game_board[y][x]=0;
	}
	else {
          game_board[y][x]=2;
	}
      }
      
      /*  開いた分とその8近傍のmine_mapの内容を出力  */
      printf("\n[y]\n\n");
      for(i=0;i<MS_SIZE;i++) {
        printf("%2d|",i);
        for(j=0;j<MS_SIZE;j++) {
          if(game_board[i][j]==1) {
	    printf("%3d",mine_map[i][j]);
          } else if(game_board[i][j]==2) {
	    printf("  F");
          } else {
            printf("  x");
          }
        }
        printf("\n");
      }
      printf("   ");
      for(i=0;i<2;i++) {
        for(j=0;j<MS_SIZE;j++) {
          if(i==0) {
	    printf("---");
          } else if(i==1 && j==0) {
  	    printf("   %3d",j);
          } else {
	    if(j==MS_SIZE-1) {
	      printf("%3d  [x]",j);
  	    } else {
	      printf("%3d",j);
 	    }
          }
        }
        printf("\n");
      }
      /*  mine_mapの内容の出力終了  */
      
      /*  現在いくつのセルが開かれたかを数える（終了条件に使用）  */
      count_of_cell_with_no_mine=0;  //終了条件を満たさなかった場合，次回も使用するため毎回0にしておく
      for(i=0;i<MS_SIZE;i++) {
        for(j=0;j<MS_SIZE;j++) {
	  if(game_board[i][j]==1 && mine_map[i][j]!=-1) {
	    count_of_cell_with_no_mine++;
  	  }
        }
      }
      /*  カウント終了  */
      
      //ゲームの成功条件を判定
      if(count_of_cell_with_no_mine==MS_SIZE*MS_SIZE-number_of_mines) {
        printf("\nCongratulation!\n");
      }
      //ゲームに成功または失敗場合，次のゲームを続けるかどうかを判定する
      if(count_of_cell_with_no_mine==MS_SIZE*MS_SIZE-number_of_mines || continue_or_not==0) {
        printf("ゲームを続けますか？ Yes（1）,No（0)：");
        scanf("%d",&continue_or_not);
	//0か1が入力されなかった場合
	while(continue_or_not!=0 && continue_or_not!=1) {
	  printf("0か1を入力してください：");
	  scanf("%d",&continue_or_not);
	}
	//ゲームを続けるときのためにgame_boradとmine_mapを初期状態に戻す
        for(i=0;i<=MS_SIZE;i++) {
	  for(j=0;j<=MS_SIZE;j++) {
	    game_board[i][j]=0;
	    mine_map[i][j]=0;
	  }
        }
	count_of_cell_with_no_mine=MS_SIZE*MS_SIZE-number_of_mines;  //ゲームを失敗した場合もループを抜け出すようにする
      }
    } while(count_of_cell_with_no_mine!=MS_SIZE*MS_SIZE-number_of_mines);

    if(continue_or_not==1) {
      printf("\n設置する地雷の数を入力してください：");
      scanf("%d",&number_of_mines);
      //条件に反する数が入力された場合
      while(number_of_mines>MS_SIZE*MS_SIZE || number_of_mines<1) {
        printf("1以上%d以下の整数を入力してください：",MS_SIZE*MS_SIZE);
        scanf("%d",&number_of_mines);
      }
    }
    
  } while(continue_or_not==1);
  return 0;
}
