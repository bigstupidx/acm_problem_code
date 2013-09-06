#include <cstdio>
#include <cmath>
#include <cstring>
const int inf = 1000000000;
double wi[1010][1010],closed[1010];
int n,cost[1010][1010],xx[1010],yy[1010],zz[1010];
inline int ABS(int x){
    return x>0?x:-x;
}
double Distance(int i,int j){
    double ax=xx[i]-xx[j];
    double by=yy[i]-yy[j];
    return sqrt(ax*ax+by*by);
}
double Prim(double r){
    double ans=0;
    for(int i=0;i<n;i++)
        closed[i]=cost[0][i]-r*wi[0][i];
    for(int k,i=1;i<n;i++){
        double tem=inf;
        for(int j=1;j<n;j++){
            if(closed[j]!=-inf&&tem>closed[j]){
                k=j;
                tem=closed[j];
            }
        }
        ans+=tem;
        closed[k]=-inf;
        for(int j=1;j<n;j++){
            if(closed[j]!=-inf&&(tem=cost[k][j]-r*wi[k][j])<closed[j]){
                closed[j]=tem;
            }
        }
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&xx[i],&yy[i],&zz[i]);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cost[i][j]=cost[j][i]=ABS(zz[i]-zz[j]);
                wi[i][j]=wi[j][i]=Distance(i,j);
            }
        }
        double mid,lf=0,rt=inf;
        while(rt-lf>1e-6){
            mid=(lf+rt)/2;
            double tem=Prim(mid);
            if(tem<0)
                rt=mid;
            else
                lf=mid;
        }
        printf("%.3lf\n",mid);
    }
    return 0;
}
