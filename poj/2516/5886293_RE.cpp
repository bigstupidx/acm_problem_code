#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
int wi[102][102],dis[102],flag[102],c[102][102];
int n,pre[102],map[102][102];
const int inf=1000000000;

bool Spfa(int s,int t)
{
    queue<int>Q;
    for(int i=1;i<=t;i++){dis[i]=inf;flag[i]=0;}
    Q.push(s);  dis[s]=0;   flag[s]=1;
    while(!Q.empty())
    {
        int i=Q.front();Q.pop();
        for(int j=1;j<=t;j++)
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
                map[m*k+i*k+j][t]=d;
            }
        for(int i=0;i<m;i++)
            for(int j=1;j<=k;j++)
            {
                int d;
                scanf("%d",&d);
                map[s][i*k+j]=d;
            }
        int cost=0,flow=0;
        for(int x=1;x<=k;x++)
        {
            memset(c,0,sizeof(c));
            memset(wi,0,sizeof(wi));     
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    int d;
                    scanf("%d",&d);
                    wi[j][m+i]=d;
                    wi[m+i][j]=-d;
                    c[j][m+i]=inf;
                }
            }
            for(int i=1;i<=n;i++)
                c[i+m][n+m+2]=map[m*k+(i-1)*k+x][t];
            for(int i=1;i<=m;i++)
                c[m+n+1][i]=map[s][(i-1)*k+x];
            while(Spfa(m+n+1,m+n+2))
            {
                int mini=inf;
                for(int i=m+n+2;i!=m+n+1;i=pre[i])
                    if(mini>c[pre[i]][i])mini=c[pre[i]][i];
                
                cost+=mini*dis[m+n+2];  flow+=mini;
                for(int i=m+n+2;i!=m+n+1;i=pre[i])
                {
                    c[pre[i]][i]-=mini;
                    c[i][pre[i]]+=mini;
                }
            }
        }
        //printf("%d\n",flow);
        if(sum==flow)printf("%d\n",cost);
        else puts("-1");
    }
    return 0;
}
