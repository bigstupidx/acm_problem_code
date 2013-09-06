#include <cstdio>
#include <cmath>
#include <cstring>
int n;
double dis[202][202];
struct node{int x,y;}nod[202];
inline double Distance(int i,int j)
{
    double ax=nod[i].x-nod[j].x;
    double by=nod[i].y-nod[j].y;
    return sqrt(ax*ax + by*by);
}
int main()
{
    int nca=0;
    while(scanf("%d",&n),n!=0)
    {
        nca++;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&nod[i].x,&nod[i].y);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                dis[i][j]=dis[j][i]=Distance(i,j);
        for(int w=1;w<=n;w++){
            for(int u=1;u<=n;u++){
                for(int v=1;v<=n;v++){
                    double tem;
                    if(dis[u][w]>dis[w][v])
                        tem=dis[u][w];
                    else tem=dis[w][v];
                    dis[u][v]=dis[u][v]>tem?tem:dis[u][v];
                }
            }
        }
        printf("Scenario #%d\n",nca);
        printf("Frog Distance = %.3lf\n",dis[1][2]);
    }
    return 0;
}
