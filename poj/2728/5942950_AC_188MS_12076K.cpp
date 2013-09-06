#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

double dis[1010][1010],closed[1010];
int n,cost[1010][1010],x[1010],y[1010],z[1010],pre[1010];

double Prim(double rr)
{
    double ans=0,sum=0;
    memset(pre,0,sizeof(pre));
    for(int i=0;i<n;i++)
        closed[i]=cost[0][i]-rr*dis[0][i];
    for(int i=1;i<n;i++)
    {
        int k=0;
        double mini=1e38;
        for(int j=1;j<n;j++)
        {
            if(pre[j]!=-1&&mini>closed[j])
            {
                mini=closed[j];k=j;
            }
        }
        ans+=cost[pre[k]][k];
        sum+=dis[pre[k]][k];
        pre[k]=-1;
        for(int j=1;j<n;j++)
            if(pre[j]!=-1&&(cost[k][j]-rr*dis[k][j]<closed[j]))
            {
                closed[j]=cost[k][j]-rr*dis[k][j];
                pre[j]=k;
            }
    }
    return ans/sum;
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
        double now=0,next;
        do{
            next=now;
            now=Prim(now);
        }while(fabs(next-now)>1e-5);
        printf("%.3lf\n",next);
    }
    return 0;
} 
