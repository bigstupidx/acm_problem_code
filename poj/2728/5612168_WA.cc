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
    for(int i=1;i<=n;i++)
        closed[i]=cost[0][i]-rr*dis[0][i];
    v[0]=1;
    for(int i=1;i<n;i++)
    {
        int k=0;
        double mini=1000000000;
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
    return ans;
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
                dis[i][j]=dis[j][i]=
                        sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            }
        }
        double r1=0,r2=1,mid,rate;
        while(r2-r1>0.0001)
        {
            mid=(r1+r2)/2;
            rate=Prim(mid);
            if(fabs(rate-0)<0.0001)break;
            if(rate>0)r1=mid;
            else r2=mid;
        }
        printf("%.3lf\n",mid);
    }
    return 0;
}
