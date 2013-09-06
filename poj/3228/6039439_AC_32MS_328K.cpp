#include <cstdio>
#include <cstring>
int n,m,dis[220][220],va[220],wi[220],sum1,sum2;
int par[220],visit[220];
const int inf = 1000000000;
int Find(int x)
{
    if(par[x]==-1)return x;
    return par[x]=Find(par[x]);
}
bool solve(int mid)
{
    memset(par,-1,sizeof(par));
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(dis[i][j]<=mid)
            {
                int ii=Find(i);
                int jj=Find(j);
                if(ii!=jj)par[ii]=jj;
            }
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=n;i++)
    {
        if(va[i]==0||visit[i])continue;
        int s1=0,s2=0,ii=Find(i);
        for(int j=1;j<=n;j++)
        {
            int jj=Find(j);
            if(jj==ii)
            {
                s1+=va[j];
                s2+=wi[j];
                visit[j]=1;
            }
        }
        if(s1>s2)return false;
    }
    return true;
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
        int l=0,r=maxi,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
           // printf("try %d \n",mid);
            if(solve(mid))
                r=mid-1;
            else l=mid+1;
        }
        if(l == maxi + 1)puts("No Solution");
        else printf("%d\n",l);
    }
    return 0;
}
