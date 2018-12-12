#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
int i,j,N,k;
double buf;

// ↓何元連立方程式かの指定
printf("何元？\n");
scanf("%d",&N);
N=N+1;
 double a[N][N],c[N][N],ans[N],b[N];
  
// ↓データ入力
for(i=0;i<N-1;i++){
for(j=0;j<N;j++){
    if(j==N-1) {
     printf("右辺=");
     scanf("%lf",&b[i]);
} 

else{
printf("左辺入力\n");
printf("x%d ",j+1);
scanf("%lf",&(a[i][j]));
    }
	
   }
 }

printf("\n");

// ↓単位行列作成
i=0;j=0;
do{
c[i][j]=1;
i++;j++;
}while(i!=N-1);


// ↓逆行列作成
for(i=0;i<N-1;i++){
 buf=1/a[i][i];
 for(j=0;j<N-1;j++){
 a[i][j]*=buf;
 c[i][j]*=buf;
}
for(j=0;j<N-1;j++){
 if(i!=j){
  buf=a[j][i];
  for(k=0;k<N-1;k++){
   a[j][k]-=a[i][k]*buf;
   c[j][k]-=c[i][k]*buf;
  }
 }
}
}

/*
//　↓逆行列作成過程で作成された単位行列
for(i=0;i<N-1;i++){
  for(j=0;j<N-1;j++){
    printf("%lf  ",a[i][j]);
    }
  printf("\n");
   }
printf("\n");
*/

// ↓逆行列表示
printf("逆行列\n");
for(i=0;i<N-1;i++){
  for(j=0;j<N-1;j++){
    printf("%lf  ",c[i][j]);
    }
  printf("\n");
   }
printf("\n");

// ↓解の計算（逆行列×連立方程式の右辺）
for(i=0;i<N-1;i++){
   for(j=0;j<N-1;j++){
   ans[i]+=c[i][j]*b[j];   
  }
}

//　↓解の表示
for(i=0;i<N-1;i++)
printf("x[%d]=%lf\n",i+1,ans[i]);
  
return 0;
}
