#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
int n,R,xx[25],yy[25],mark[25];
double map[25][25],dis[25],pi;
struct QN{
    int u;
    double d,deg;//d表示距离，deg表示当前角度 
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
const double inf = 1000000000;
double ABS(double x){return x>0?x:-x;}
double Distance(int i,int j)
{
    double ax=xx[i]-xx[j];
    double by=yy[i]-yy[j];
    return sqrt(ax*ax+by*by);
}
void Dij_BFS()
{
    QN now,next;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++){dis[i]=inf;mark[i]=0;}
    now.u=1;    now.d=0;    dis[1]=0;
    now.deg=atan2((yy[n]-yy[1])*1.0,(xx[n]-xx[1])*1.0);
    Q.push(now);
    for(int k,i=1;i<n;i++)
    {
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(int i=1;i<=n;i++)
        {
            if(!mark[i]&&map[k][i]>0)
            {
                double ang1=now.deg;
                double ang2=atan2((yy[i]-yy[k])*1.0,(xx[i]-xx[k])*1.0);
                double ang=min(fabs(ang1-ang2),2*pi-fabs(ang1-ang2));
                ang=180*ang/pi;
                if(dis[i]>dis[k]+map[k][i]+ang)
                {
                    dis[i]=dis[k]+map[k][i]+ang;
                    next.u=i;
                    next.d=dis[i];
                    next.deg=ang2;
                    Q.push(next);
                }
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    pi=acos(-1.0);
    while(scanf("%d%d",&R,&n),n!=-1||R!=-1)
    {
        for(int i=1;i<=n;i++){
            map[i][i]=0;
            scanf("%d%d",xx+i,yy+i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++){
                double tem=Distance(i,j);
                if(tem>R){
                    map[i][j]=map[j][i]=-1;
                    continue;
                }
                map[i][j]=map[j][i]=tem;
            }
        }
        Dij_BFS();
        if(dis[n]==inf)puts("impossible");
        else printf("%.0lf\n",dis[n]);
    }
    return 0;
}
