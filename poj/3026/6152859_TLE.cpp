#include <queue>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct QN {int i,j,st;};
char str[60][60];
int dir[4][2]={0,1,1,0,-1,0,0,-1};
int r,c,dis[120][120],id[60][60],visit[60][60],closed[120];
void BFS(int i,int j)
{
    queue<QN>Q;
    QN now,next;
    now.i=i,now.j=j,now.st=0;
    Q.push(now);
    memset(visit,0,sizeof(visit));
    while(!Q.empty())
    {
        now=Q.front();Q.pop();
        visit[now.i][now.j]=1;
        for(int k=0;k<4;k++)
        {
            int ii=now.i+dir[k][0];
            int jj=now.j+dir[k][1];
            if(ii<r&&ii>=0&&jj>=0&&jj<c&&!visit[ii][jj]&&str[ii][jj]!='#')
            {
                next.i=ii;
                next.j=jj;
                next.st=now.st+1;
                Q.push(next);
                if(str[ii][jj]=='A')
                {
                    dis[id[i][j]][id[ii][jj]]=next.st;
                    dis[id[ii][jj]][id[i][j]]=next.st;
                }
            }
        }
    }
}
int prim(int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
        closed[i]=dis[0][i];
    for(int j=1;j<n;j++)
    {
        int k=0,mini=1000000;
        for(int i=1;i<n;i++)
            if(closed[i]&&mini>closed[i])
                mini=closed[i],k=i;
        ans+=mini;
        closed[k]=0;
        for(int i=1;i<n;i++)
            if(closed[i]&&closed[i]>dis[k][i])
                closed[i]=dis[k][i];
    }
    return ans;
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--)
    {
        int k=0;char cc[100];
        cin>>c>>r;gets(cc);
        for(int i=0;i<r;i++)
        {
            gets(str[i]);
            for(int j=0;j<c;j++)
            {
                if(str[i][j]=='S')
                    str[i][j]='A';
                if(str[i][j]=='A')
                    id[i][j]=k++;
            }
        }
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(str[i][j]=='A')
                    BFS(i,j);
//        for(int i=0;i<k;i++)
//        {
//            for(int j=0;j<k;j++)
//                printf("%d ",dis[i][j]);
//            puts("");
//        }
//        system("pause");
        printf("%d\n",prim(k));
    }
    return 0;
}
