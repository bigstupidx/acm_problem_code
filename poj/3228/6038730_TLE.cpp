#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int pre[220],f[220][220],c[220][220];
int n,m,dis[220][220],va[220],wi[220],sum1,sum2;
const int inf = 1000000000;
void Build_G(int mid)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)
            if(dis[i][j]!=inf&&dis[i][j]<=mid)
                c[i][j]=c[j][i]=inf;
    }
}
bool solve()
{
    int ans=0;
    memset(f,0,sizeof(f));
    while(1)
    {
        int i,mini=inf;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(0);
        while(!Q.empty()&&pre[n+1]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=0;j<=n+1;j++)
            {
                if(pre[j]==-1&&c[i][j]>f[i][j])
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[n+1]==-1)break;
        for(i=n+1;i!=0;i=pre[i])
            if(mini>c[pre[i]][i]-f[pre[i]][i])
                mini=c[pre[i]][i]-f[pre[i]][i];
        ans+=mini;
        for(i=n+1;i!=0;i=pre[i])
        {
            f[pre[i]][i]+=mini;
            f[i][pre[i]]-=mini;
        }
    }
   // printf(" %d\n",ans);
    return ans==sum1;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        sum1=0; sum2=0;
        for(int i=1;i<=n;i++){
            scanf("%d",va+i);
            sum1+=va[i];
        }
        for(int i=1;i<=n;i++){
            scanf("%d",wi+i);
            sum2+=wi[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                dis[i][j]=inf;
            dis[i][i]=0;
        }
        int x,y,d,maxi=-1;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&d);
            if(maxi<d)maxi=d;
            if(dis[x][y]>d)
                dis[x][y]=dis[y][x]=d;
        }
        if(sum1>sum2)
        {
            puts("No Solution");
            continue;
        }
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            c[0][i]=va[i];
            c[i][n+1]=wi[i];
        }
        int l=0,r=maxi,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
           // printf("try %d ",mid);
            Build_G(mid);
            if(solve())
                r=mid-1;
            else l=mid+1;
        }
        if(l == maxi + 1)puts("No Solution");
        else printf("%d\n",l);
    }
    return 0;
}
