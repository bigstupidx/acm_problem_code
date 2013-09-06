#include<cstdio>
#include<cstring>
#include<queue>
#define inf 100000000000
using namespace std;

__int64 dp[202][202],f[404][404];
int c[202],p[202],n,pre[404],Y,X;

void Short_Path_Floyd()
{
    for(int u=1;u<n;u++)
        for(int v=1;v<=n;v++)
            for(int w=1;w<=n;w++)
                if(dp[v][w]>dp[v][u]+dp[u][w])
                    dp[v][w]=dp[v][u]+dp[u][w];
}
void Init_Flow(int mid)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dp[i][j]<=mid)
                f[i][j+n]=inf;
    return;
}
int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=1000000000;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);pre[s]=0;
        while(!Q.empty()&&pre[t]==-1)
        {
            int j=Q.front();Q.pop();
            for(int i=1;i<=2*n+1;i++)
                if(pre[i]==-1&&f[j][i]>0)
                {
                    pre[i]=j;
                    if(mini>f[j][i])mini=f[j][i];
                    Q.push(i);
                }
        }
        if(pre[t]==-1)return flow;
        for(int i=t;i!=s;i=pre[i])
        {
            f[pre[i]][i]-=mini;
            f[i][pre[i]]+=mini;
        }
        flow+=mini;
    }
}
__int64 Binary_Search()
{
    __int64 max=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //printf("%d ",dp[i][j]);
            if(max<dp[i][j])max=dp[i][j];
        }
        //puts("");
    }
    __int64 h=max,l=0,mid;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        f[0][i]=p[i];
        f[i+n][2*n+1]=c[i];
    }
    while(l<=h)
    {
        mid=(l+h)/2;
        Init_Flow(mid);
        int temp;
        temp=Max_Flow(0,2*n+1);
        //printf("Y: %d mid: %d  temp: %d\n",Y,mid,temp);
        if(temp==Y)
            h=mid-1;
        else
            l=mid+1;
    }
    return l;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Y=0;X=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",c+i,p+i);
            Y+=c[i];X+=p[i];
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i != j)dp[i][j]=inf;
                else dp[i][j]=0;
        while(m--)
        {
            int x,y,va;
            scanf("%d%d%d",&x,&y,&va);
            dp[x][y]=dp[y][x]=dp[x][y]>va?va:dp[x][y];
        }
        Short_Path_Floyd();
        printf("%I64d\n",Binary_Search());
    }
    return 0;
}
