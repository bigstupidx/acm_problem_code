#include <cstdio>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
char g[120][120];
int r,c,visit[120][120],dir[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
int arr[10010];
inline int ABS(int x)
{
    if(x<0)return -x;
    return x;
}
int BFS(int x,int y,int now,char ch)
{
    queue<int>Q;
    Q.push(x*c+y);
    int ans=0,top=0;
    if(now==0)visit[x][y]=1;
    while(!Q.empty())
    {
        int tem=Q.front();Q.pop();
        int i=tem/c,j=tem%c;
        if(now==0){
            for(int k=0;k<top;k++)
                ans+=ABS(i-arr[k]/c)+ABS(j-arr[k]%c);
            arr[top++]=tem;
        }
        else {
            visit[i][j]=2;
            g[i][j]=ch;
        }
        for(int k=0;k<8;k++)
        {
            int ii=i+dir[k][0];
            int jj=j+dir[k][1];
            if(ii>=0&&ii<r&&jj>=0&&jj<c)
            {
                if(now==0)
                {
                    if(!visit[ii][jj]&&g[ii][jj]=='1')
                    {
                        visit[ii][jj]=1;
                        Q.push(ii*c+jj);
                    }
                }
                else if(now==1)
                {
                    if(visit[ii][jj]==1)
                        Q.push(ii*c+jj);
                }
            }
        }
    }
    return ans;
}
void solve()
{
    int kk='a';
    map<int,int>mp;
    map<int,int>::iterator p;
    memset(visit,0,sizeof(visit));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(g[i][j]=='1'&&!visit[i][j])
            {
                int tem=BFS(i,j,0,0);
                p=mp.find(tem);
                //printf("%d %d %d\n",i,j,tem);
                if(p==mp.end())
                {
                    BFS(i,j,1,kk);
                    mp[tem]=kk++;
                }
                else
                {
                    char tt;
                    tt=p->second;
                    BFS(i,j,1,tt);
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
