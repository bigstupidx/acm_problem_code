#include <cstdio>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
char g[120][120];
int r,c,visit[120][120],dir[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
int arr[200];
struct node{
    int x;
    long long y;
    int tt;
}nod[30];
inline int ABS(int x)
{
    if(x<0)return -x;
    return x;
}
void BFS(int x,int y,int now,char ch,int &ans,long long &sum)
{
    queue<int>Q;
    Q.push(x*c+y);
    int top=0;ans=0;sum=0;
    if(now==0)visit[x][y]=1;
    else visit[x][y]=2;
    while(!Q.empty())
    {
        int tem=Q.front();Q.pop();
        int i=tem/c,j=tem%c;
        if(now==0)
        {
            for(int k=0;k<top;k++)
            {
                int a=ABS(i-arr[k]/c);
                int b=ABS(j-arr[k]%c);
                ans+=a+b;sum+=a*a+b*b;
            }
            arr[top++]=tem;
        }
        else g[i][j]=ch;
        for(int k=0;k<8;k++)
        {
            int ii=i+dir[k][0];
            int jj=j+dir[k][1];
            if(ii>=0&&ii<r&&jj>=0&&jj<c)
            {
                if(now==0)
                {
                    if(visit[ii][jj]==0&&g[ii][jj]=='1')
                    {
                        visit[ii][jj]=1;
                        Q.push(ii*c+jj);
                    }
                }
                else if(now==1)
                {
                    if(visit[ii][jj]==1&&g[ii][jj]=='1')
                    {
                        visit[ii][jj]=2;
                        Q.push(ii*c+jj);
                    }
                }
            }
        }
    }
}
void solve()
{
    int kk='a';
    map<int,int>mp1;
    map<int,int>::iterator p;
    map<long long ,int>mp2;
    map<long long ,int>::iterator q;
    memset(visit,0,sizeof(visit));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(g[i][j]=='1'&&!visit[i][j])
            {
                long long tem2;
                int tem1,flag=0;
                BFS(i,j,0,0,tem1,tem2);
                for(int k=0;k<kk-'a';k++)
                {
                    if(nod[k].x==tem1&&nod[k].y==tem2)
                    {
                        BFS(i,j,1,nod[k].tt,tem1,tem2);
                        flag=1;break;
                    }
                }
                if(!flag)
                {
                    int k=kk-'a';
                    nod[k].x=tem1;nod[k].y=tem2;
                    BFS(i,j,1,kk,tem1,tem2);
                    nod[k].tt=kk++;
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&c,&r)!=EOF)
    {
        for(int i=0;i<r;i++)
            scanf("%s",g[i]);
        solve();
        for(int i=0;i<r;i++)
            printf("%s\n",g[i]);
    }
    return 0;
}
