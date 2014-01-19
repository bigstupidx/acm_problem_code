#include<stdio.h>
#include<string.h>
#define MAX 30

int dir[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
int used[MAX][MAX],k;
char map1[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char map2[]="123456789";
char ans[200];
int m,n;

int place(int x,int y)
{
    if(x<=n&&x>=1&&y<=m&&y>=1)return 1;
    return 0;
}
int dfs(int x,int y,int unused)
{
    int i,xx,yy;
    if(unused==0){
                   ans[k]='\0';
                   return 1;
    }
    for(i=0;i<8;i++)
    {
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(place(xx,yy)&&!used[xx][yy]){
                         ans[k++]=map1[xx-1];
                         ans[k++]=map2[yy-1];
                         used[xx][yy]=1;
                         if(dfs(xx,yy,unused-1))return 1;
                         used[xx][yy]=0;
                         k-=2;
        }            
    }
    return 0;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
               scanf("%d%d",&m,&n);
               k=0;
               memset(used,0,sizeof(used));
               printf("Scenario #%d:\n",i);
               ans[k++]='A';ans[k++]='1';used[1][1]=1;
               if(dfs(1,1,m*n-1)) 
                   printf("%s\n\n",ans);
               else     
                   printf("impossible\n\n");             
    }
    return 0;
}
