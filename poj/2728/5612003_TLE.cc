#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

double dis[1010][1010],map[1010][1010];
int n,cost[1010][1010],x[1010],y[1010],z[1010],par[1010];
struct edge{
    int u,v;
    double d;
    bool operator<(const edge a)const
    {
        return a.d>d;
    }
}e[1000010];
int F(int s)
{
    int t=par[s];
    if(t==-1)return s;
    return par[s]=F(t);
}
double Kruskral(double x)
{
    int top=0;
    double sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            e[top].d=fabs(cost[i][j]-x*dis[i][j]);
            e[top].u=i;
            e[top++].v=j;
        }
    }
    sort(e,e+top);
    memset(par,-1,sizeof(par));
    int i=0,k=1;
    while(1)
    {
        int u,v;
        u=e[i].u;v=e[i++].v;
        int uu=F(u),vv=F(v);
        if(uu==vv)continue;
        par[uu]=vv;
        sum1+=cost[u][v];
        sum2+=dis[u][v];
        k++;
        if(k==n)break;
    }
    return sum1/sum2;
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
        double r1,r2;
        for(r1=0,r2=1;fabs(r2-r1)>=0.0001;)
        {
            r2=r1;
            r1=Kruskral(r1);
        }
        printf("%.3lf\n",r1);
    }
    return 0;
}
