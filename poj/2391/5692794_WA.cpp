#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1000000000
using namespace std;

int n,dp[220][220],c[500][500],f[500][500],cow[220],p[220],Y,pre[500];
int bb[200000];
void Floyd_Short_Path()
{
    int u,v,w;
    for(v=1;v<=n;v++)
        for(u=1;u<=n;u++)
            for(w=1;w<=n;w++)
                if(dp[w][u]>dp[w][v]+dp[v][u])
                    dp[w][u]=dp[v][u]+dp[w][v];
}
int Max_Flow(int s,int t)
{
    int flow=0;
    memset(f,0,sizeof(f));
    while(1)
    {
        int i,mini=inf;
        memset(pre,-1,sizeof(pre));
        queue<int>Q;
        Q.push(s);pre[s]=-2;
        while(!Q.empty()&&pre[t]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=0;j<=2*n+1;j++)
            {
                if(pre[j]==-1&&c[i][j]>f[i][j])
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return flow;
        for(i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i]-f[pre[i]][i])
                mini=c[pre[i]][i]-f[pre[i]][i];
        for(i=t;i!=s;i=pre[i])
        {
            f[pre[i]][i]+=mini;
            f[i][pre[i]]-=mini;
        }
        flow+=mini;
    }
}
bool solve(int mid)
{
    int i,j;
    for(i=1;i<=n;i++)c[i][i+n]=inf;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(dp[i][j]<inf&&dp[i][j]<=mid)
                c[i][j+n]=c[j][i+n]=inf;
            else c[i][j+n]=c[j][i+n]=0;
    return Max_Flow(0,2*n+1)==Y;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        Y=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dp[i][j]=inf;
        for(i=1;i<=n;i++)dp[i][i]=0;

        for(i=1;i<=n;i++){
            scanf("%d%d",cow+i,p+i);
            Y+=cow[i];
        }
        
        while(m--)
        {
            int d;
            scanf("%d%d%d",&i,&j,&d);
            if(d<dp[i][j])
                dp[i][j]=dp[j][i]=d;
        }
        Floyd_Short_Path();
        for(i=1;i<=n;i++){c[0][i]=cow[i];c[i+n][2*n+1]=p[i];}
        int cnt=0;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                if(dp[i][j] < inf)
                    bb[cnt++]=dp[i][j];
        sort(bb,bb+cnt);
        int l=0,r=cnt-1,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            //printf("try %d: ",mid);
            if(solve(bb[mid])){
                //puts("success");
                r=mid-1;
            }
            else{
                //puts("failure");
                l=mid+1;
            }
        }
        if(l==cnt)bb[l]=-1;
        printf("%d\n",bb[l]);
    }
    return 0;
}
