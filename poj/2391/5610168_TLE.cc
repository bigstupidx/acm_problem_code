#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const long long inf=1LL <<60;
int cow[202],p[202],n,Y,pre[202],c[404][404];
long long dp[202][202],bb[40010];

int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=1000000000;
        memset(pre,-1,sizeof(pre));
        queue<int>Q;
        Q.push(s);pre[s]=0;
        while(!Q.empty()&&pre[t]==-1)
        {
            int j=Q.front();Q.pop();
            for(int i=1;i<=2*n+1;i++)
                if(pre[i]==-1&&c[j][i]>0)
                {
                    pre[i]=j;
                    if(c[j][i]<mini)mini=c[j][i];
                    Q.push(i);
                }
        }
        if(pre[t]==-1)
        {
            //printf("flow :%d\n",flow);
            return flow;
        }
        for(int i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
        flow+=mini;
    }
}

bool Exist_Path(int mid)
{
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
    {
        c[0][i]=p[i];
        c[i+n][2*n+1]=cow[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(dp[i][j]!=inf&&dp[i][j]<=mid)
                c[i][j+n]=c[j][i+n]=100000000;
    return Max_Flow(0,2*n+1)==Y;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Y=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",cow+i,p+i);
            Y+=cow[i];
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i==j)dp[i][j]=0;
                else dp[i][j]=inf;
        while(m--)
        {
            int x,y,va;
            scanf("%d%d%d",&x,&y,&va);
            dp[x][y]=dp[y][x]=dp[x][y]<va?dp[x][y]:va;
        }
        for(int w=1;w<=n;w++)
           for(int u=1;u<=n;u++)
               for(int v=1;v<=n;v++)
                   if(dp[u][v]>dp[u][w]+dp[w][v])
                       dp[u][v]=dp[u][w]+dp[w][v];
        int top=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(dp[i][j]!=inf)bb[top++]=dp[i][j];

        sort(bb,bb+top);
        
        int h=top-1,l=0,mid;
        long long ans=-1;
        while(l<=h)
        {
            mid=(h+l)/2;
            if(Exist_Path(bb[mid]))
            {
                ans=bb[mid];
                h=mid-1;
            }
            else
                l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
