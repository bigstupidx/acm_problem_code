#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

double dis[1010][1010],closed[1010];
int n,cost[1010][1010],x[1010],y[1010],z[1010],v[1010];

double Prim(double rr)
{
    double ans=0;
    memset(v,0,sizeof(v));
    for(int i=1;i<n;i++)
        closed[i]=cost[0][i]-rr*dis[0][i];
    v[0]=1;
    for(int i=1;i<n;i++)
    {
        int k=0;
        double mini=1e38;
        for(int j=1;j<n;j++)
        {
            if(!v[j]&&mini>closed[j])
            {
                mini=closed[j];k=j;
            }
        }
        v[k]=1;ans+=mini;
        for(int j=1;j<n;j++)
            if(!v[j]&&cost[k][j]-rr*dis[k][j]<closed[j])
                closed[j]=cost[k][j]-rr*dis[k][j];
    }
    if(ans<0)return false;
    return true;
}
double Distance(int i,int j)
{
    double ax=x[i]-x[j],by=y[i]-y[j];
    return sqrt(ax*ax+by*by);
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                cost[i][j]=cost[j][i]=abs(z[i]-z[j]);
                dis[i][j]=dis[j][i]=Distance(i,j);
            }
        }
        double l=0,r=1e8,mid;
        while(r-l>0.000001)
        {
            mid=(r+l)/2;
            if(Prim(mid))
                l=mid;
            else r=mid;
        }
        printf("%.3lf\n",l);
    }
    return 0;
} 
