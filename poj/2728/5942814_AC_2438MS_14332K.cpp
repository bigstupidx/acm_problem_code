#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define MAXN 1200
double map[MAXN][MAXN],closed[MAXN];
int n,xx[MAXN],yy[MAXN],zz[MAXN],wi[MAXN][MAXN];
double Distance(int i,int j)
{
    double ax=xx[i]-xx[j],by=yy[i]-yy[j];
    return sqrt(ax*ax+by*by);
}
int ABS(int x)
{
    if(x<0)return -x;
    return x;
}
bool Prim(double ra)
{
    double ans=0;
    for(int i=1;i<=n;i++)
        closed[i]=wi[1][i]-ra*map[1][i];
    for(int i=1;i<n;i++)
    {
        double mini=1e35;
        int k=1;
        for(int j=1;j<=n;j++)
            if(closed[j]&&mini>closed[j])
            {
                k=j;mini=closed[j];
            }
        ans+=mini;  closed[k]=0;
        for(int j=1;j<=n;j++)
            if(closed[j]&&closed[j]>wi[k][j]-ra*map[k][j])
                closed[j]=wi[k][j]-ra*map[k][j];
    }
    if(ans<0)return false;
    return true;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++){map[i][i]=0;wi[i][i]=0;}
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&xx[i],&yy[i],&zz[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                map[i][j]=map[j][i]=Distance(i,j);
                wi[i][j]=wi[j][i]=ABS(zz[i]-zz[j]);
            }
        }
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                printf("%.2lf ",map[i][j]);
            puts("");
        }
        */
        double l=0,r=1e9,mid;
        while(r-l>1e-8)
        {
            mid=(l+r)/2;
            //printf("try mid %lf\n",mid);
            //system("pause");
            if(Prim(mid))
                l=mid;
            else r=mid;
        }
        printf("%.3lf\n",l);
    }
    return 0;
}
