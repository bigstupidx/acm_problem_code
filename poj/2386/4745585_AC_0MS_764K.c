#include<stdio.h>
#define max 150

char pond[max][max];
int m,n;

void trace(int i,int j)
{
     if(i<0||j<0||i==n||j==m||pond[i][j]=='.')return;
     else{
          pond[i][j]='.';
          trace(i-1,j-1);trace(i-1,j);trace(i-1,j+1);
          trace(i,j-1);trace(i,j+1);
          trace(i+1,j-1);trace(i+1,j);trace(i+1,j+1);
     }
}
int main()
{
    int i,j,flag,sum=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
          scanf("%s",pond[i]);
    while(1){
             flag=1;
             for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                   if(pond[i][j]=='W'){
                                       sum++;flag=0;
                                       trace(i,j);
                   }
             if(flag){printf("%d\n",sum);break;}
    }
    return 0;
}
