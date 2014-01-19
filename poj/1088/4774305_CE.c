#include<stdio.h>
int xue[101][101],flag[101][101];
int m,n;

int jimmy(int i,int j)
{
    int temp,max;
    max=1;
    if(flag[i][j]!=-1)return flag[i][j];
    if(xue[i][j]>xue[i-1][j]&&i>1){
                                   temp=jimmy(i-1,j);
                                   if(temp+1>max)max=temp+1;
    }
    if(xue[i][j]>xue[i+1][j]&&i<n){
                                   temp=jimmy(i+1,j);
                                   if(temp+1>max)max=temp+1;
    }
    if(xue[i][j]>xue[i][j-1]&&j>1){
                                   temp=jimmy(i,j-1);
                                   if(temp+1>max)max=temp+1;
    }
    if(xue[i][j]>xue[i][j+1]&&j<m){
                                    temp=jimmy(i,j+1);
                                    if(temp+1>max)max=temp+1;
    }
    flag[i][j]=max;
    return max;
}
int main()
{
    int max,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          {scanf("%d",&xue[i][j]);
           flag[i][j]=-1;
    }
    for(i=1,max=0;i<=n;i++)
         for(j=1;j<=m;j++){
                           int temp;
                           temp=jimmy(i,j);
                           if(temp>max)max=temp;
    }
    printf("%d\n",max);
    getch();
    return 0;
}
