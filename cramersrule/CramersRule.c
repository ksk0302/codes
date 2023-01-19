#include<stdio.h>

int main() {
  int i,j,k,l;  //カウンタ変数
  int N;  //行列の次数

  printf("クラメールの公式を用いて連立方程式 Ax=d の解を求めます．\n\n");
  printf("N×N行列 A の次数 N を入力してください：");  scanf("%d",&N);

  double detA=1.0, tmp;  //行列Aの行列式detA, detAの計算に使用する変数tmp
  double Adet[N][N],A[N][N];  //N×N行列 ( Adet は行列式の計算用，A はクラメールの式用)
  double x[N];  //方程式の解x1, x2, …, xN
  //計算に使用するために x を初期化
  for(i=0;i<N;i++) {
    x[i] = 1.0;
  }

  printf("\n");

  //行列の成分の入力
  printf("Aの成分をスペースで区切って入力してください\n");
  for(i=0;i<N;i++) {
    printf("第 %d 行目：",i+1);
    for(j=0;j<N;j++) {
      scanf("%lf",&Adet[i][j]);
    }
  }

  double vec[N];  //ベクトル d
  printf("\n\nベクトル d を入力してください．\n");
  for(i=0;i<N;i++) {
    printf("第 %d 行目：",i+1);  scanf("%lf",&vec[i]);
  }

  //行列式を求める前にクラメールの式の計算用の行列 A を複製
  for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
      A[i][j] = Adet[i][j];
    }
  }
  
  //上三角行列を生成
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(i<j){
	if(Adet[i][i]==0) {
	  for(k=i;k<N;k++) {
	    Adet[i][k]+=Adet[i+1][k];
	  }
	}
	tmp = Adet[j][i]/Adet[i][i];
	for(k=0;k<N;k++){
	  Adet[j][k] -= Adet[i][k]*tmp;
	}
      }
    }
  }

  //行列 A の対角成分の積をとって行列 A の行列式を計算
  for(i=0;i<N;i++) {
    detA *= Adet[i][i];
  }

  printf("\nA の行列式：%f\n\n",detA);
  
  if(detA == 0) {
    printf("解は存在しません．\n");
  }
  else {
    //クラメールの公式に使用する行列を生成する
    double A_including_vec[N][N][N];
    for(i=0;i<N;i++) {
      for(j=0;j<N;j++) {
        for(k=0;k<N;k++) {
  	  if(i==k) {
	    A_including_vec[i][j][k] = vec[j];
	  } else {
	    A_including_vec[i][j][k] = A[j][k];
  	  }
        }
      }
    }

    for(i=0;i<N;i++) {
      //上三角行列を生成
      for(j=0;j<N;j++) {
        for(k=0;k<N;k++) {
  	  if(j<k) {
	    if(A_including_vec[i][j][j]==0) {
	      for(l=j;l<N;l++) {
		A_including_vec[i][j][l]+=A_including_vec[i][j+1][l];
	      }
	    }
	    tmp = A_including_vec[i][k][j]/A_including_vec[i][j][j];
	    for(l=0;l<N;l++) {
	      A_including_vec[i][k][l] -= A_including_vec[i][j][l]*tmp;
	    }
  	  }
        }
      }
      //対角成分の積をとって行列式を計算
      for(j=0;j<N;j++) {
        x[i] *= A_including_vec[i][j][j];
      }
    }

    //求める解 x1,x2,…,xN を出力
    printf("連立方程式の解\n");
    for(i=0;i<N;i++) {
      printf("x%d = %.10f\n",i+1,x[i]/detA);
    }
  }
  
  return 0;
}
