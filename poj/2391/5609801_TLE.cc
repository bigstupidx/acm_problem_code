#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const long long inf = 1LL << 60;
long long dp[202][202],f[404][404],mm[40010];
int c[202],p[202],n,pre[404],Y;

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
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        f[0][i]=p[i];
        f[i+n][2*n+1]=c[i];
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dp[i][j]!=inf&&dp[i][j]<=mid)
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
long long Binary_Search()
{
    int top=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
//            printf("%d ",dp[i][j]);
            if(dp[i][j]!=inf)mm[top++]=dp[i][j];
        }
//        puts("");
    }

    sort(mm,mm+top);

    int h=top-1,l=0,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        Init_Flow( mm[mid] );
        int temp;
        temp=Max_Flow(0,2*n+1);
        if(temp==Y)
            h=mid-1;
        else
            l=mid+1;
    }
    if(l==top)return -1;
    return mm[l];
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Y=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",c+i,p+i);
            Y+=c[i];
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
        printf("%lld\n",Binary_Search());
    }
    return 0;
}
