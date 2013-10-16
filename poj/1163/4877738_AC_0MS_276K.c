#include<stdio.h>
int arrey[101][101];
int sum[101][101];
int main()
{
  int i,j,max=0;
  int n;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
   sum[i][0]=0;
  for(i=1;i<=n;i++){
   for(j=1;j<=i;j++)
    scanf("%d",&arrey[i][j]);
   sum[i][n+1]=0;
  }
  sum[1][1]=arrey[1][1];
  for(i=2;i<=n;i++)
   for(j=1;j<=i;j++)
    sum[i][j]=(sum[i-1][j]>sum[i-1][j-1]?sum[i-1][j]:sum[i-1][j-1])+arrey[i][j];
  for(i=1;i<=n;i++)
   if(max<sum[n][i])max=sum[n][i];
  printf("%d\n",max);
  return 0;
}