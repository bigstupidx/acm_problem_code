#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
int wi[5002][5002],dis[5002],flag[5002],c[5002][5002];
int n,pre[5002];
const int inf=1000000000;

bool Spfa(int s,int t)
{
    queue<int>Q;
    for(int i=1;i<=n;i++){dis[i]=inf;flag[i]=0;}
    Q.push(s);  dis[s]=0;   flag[s]=1;
    while(!Q.empty())
    {
        int i=Q.front();Q.pop();
        for(int j=1;j<=n;j++)
        {
            if(c[i][j]>0&&dis[j]>dis[i]+wi[i][j])
            {
                dis[j]=dis[i]+wi[i][j];
                pre[j]=i;
                if(!flag[j])
                {
                    flag[j]=1;
                    Q.push(j);
                }
            }
        }
        flag[i]=0;
    }
    if(dis[t]==inf)return false;
    return true;
}
int main()
{
    int m,k;
    while(scanf("%d%d%d",&n,&m,&k),n||m||k)
    {
        int s=(n+m)*k+1,t=(n+m)*k+2,sum=0;
        memset(wi,0,sizeof(wi));
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
            for(int j=1;j<=k;j++)
            {
                int d;
                scanf("%d",&d);
                sum+=d;
                c[m*k+i*k+j][t]=d;
            }
        for(int i=0;i<m;i++)
            for(int j=1;j<=k;j++)
            {
                int d;
                scanf("%d",&d);
                c[s][i*k+j]=d;
            }
        for(int x=1;x<=k;x++)
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                {
                    int d;
                    scanf("%d",&d);
                    wi[j*k+x][m*k+i*k+x]=d;
                    wi[m*k+j*k+x][j*k+x]=-d;
                    c[j*k+x][m*k+i*k+x]=inf;
                }
        n=t;
        int cost=0,flow=0;
        while(Spfa(s,t))
        {
            int mini=inf;
            for(int i=t;i!=s;i=pre[i])
                if(mini>c[pre[i]][i])mini=c[pre[i]][i];
            cost+=mini*dis[t];  flow+=mini;
            for(int i=t;i!=s;i=pre[i])
            {
                c[pre[i]][i]-=mini;
                c[i][pre[i]]+=mini;
            }
        }
        if(sum==flow)printf("%d\n",cost);
        else puts("-1");
    }
    return 0;
}
