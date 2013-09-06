#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
struct node{
    double x,y;
}nod[520];
double dis[520][520],closed[520];
int s,p,top,pre[520];
const int inf = 1000000000;
struct edge{
    int u,v;
    double d;
    bool operator<(const edge a)const
    {
        return a.d>d;
    }
}edg[520];
double Distance (int i,int j)
{
    double ax = nod[i].x - nod[j].x;
    double by = nod[i].y - nod[j].y;
    return sqrt(ax * ax + by * by);
}
void Prim(int s)
{
    memset(pre,0,sizeof(pre));
    for(int i=0;i<p;i++)
        closed[i]=dis[s][i];
    for(int i=1;i<p;i++)
    {
        int k;
        double mini=inf;
        for(int j=1;j<p;j++)
            if(closed[j]&&mini>closed[j])
            {
                k=j;
                mini=closed[j];
            }
        //printf("%d %.2lf %.2lf\n",k,mini,closed[k]);
        edg[top].u=pre[k];
        edg[top].v=k;
        edg[top++].d=closed[k];
        closed[k]=0;
        for(int j=1;j<p;j++)
            if(closed[j]&&closed[j]>dis[k][j])
            {
                closed[j]=dis[k][j];
                pre[j]=k;
            }
    }
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d",&s,&p);
        for(int i=0;i<p;i++)
            scanf("%lf%lf",&nod[i].x,&nod[i].y);
        for (int i = 0; i < p; i++)
            for (int j = i + 1; j < p; j++)
                dis[i][j] = dis[j][i] = Distance(i,j);
        top=0;
        Prim(0);
        std::sort(edg,edg+top);
        printf("%.2lf\n",edg[p-s-1].d);
    }
    return 0;
}
