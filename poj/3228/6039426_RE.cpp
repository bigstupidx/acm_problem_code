#include <cstdio>
#include <cstring>
const int inf = 1000000000;
int par[220],visit[220];
int n,m,dis[220][220],va[220],wi[220],s1,s2;
int Find(int x)
{
    if(par[x]==-1)return x;
    return par[x]=Find(par[x]);
}
bool solve(int mid)
{
    memset(par,-1,sizeof(par));
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(dis[i][j]<=mid){
                int ii=Find(i);
                int jj=Find(j);
                par[ii]=jj;
            }
        }
    }
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=n;i++)
    {
        if(va[i]==0||visit[i])continue;
        int sum1=0,sum2=0,ii=Find(i);
        for(int j=1;j<=n;j++)
            if(Find(j)==ii)
            {
                visit[j]=1;
                sum1+=va[j];
                sum2+=wi[j];
            }
        if(sum1>sum2)return false;
    }
    return true;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        s1=0;s2=0;
        for(int i=1;i<=n;i++){
            scanf("%d",va+i);
            s1+=va[i];
        }
        for(int i=1;i<=n;i++){
            scanf("%d",wi+i);
            s2+=wi[i];
        }
        int x,y,d,maxi=-1;
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                dis[i][j]=inf;
            dis[i][i]=0;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&d);
            if(maxi<d)maxi=d;
            if(dis[x][y]>d)
                dis[x][y]=dis[y][x]=d;
        }
        int l=0,r=maxi,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(solve(mid))
                r=mid-1;
            else l=mid+1;
        }
        if(l==maxi+1)puts("No Solution");
        else printf("%d\n",l);
    }
    return 0;
}
