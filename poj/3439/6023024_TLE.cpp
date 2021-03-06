#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[4000010],*vert[1010];
int n,dis[1010],mark[1010],xx[1010],yy[1010];
const int inf = 1000000000;
struct QN{
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
int ABS(int x){return x>0?x:-x;}
double Distance(int i,int j)
{
    double ax=ABS(xx[i]-xx[j]);
    double by=ABS(yy[i]-yy[j]);
    return sqrt(ax*ax+by*by);
}
void Add_Edge(int x,int y,int va,int &top)
{
   // printf("%d -> %d\n",x,y);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
void dijkstra(int s)
{
    QN now;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++){dis[i]=inf;mark[i]=0;}
    now.u=s;    now.d=0;    dis[s]=0;
    Q.push(now);
    for(int i=1;i<n;i++)
    {
        int k;
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=vert[k];p;p=p->next)
        {
            if(!mark[p->to]&&dis[p->to]>dis[k]+p->d)
            {
                dis[p->to]=dis[k]+p->d;
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
}
int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        int s,t,tot=-1;
        double len,l2,tem;
        scanf("%d%d%d%lf%lf",&n,&s,&t,&len,&l2);
        len+=l2;
        for(int i=1;i<=n;i++)scanf("%d%d",xx+i,yy+i);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                tem=Distance(i,j);
                if(len>=tem){
                    Add_Edge(i,j,1,tot);
                    Add_Edge(j,i,1,tot);
                }
            }
        }
        dijkstra(s);
        if(dis[t]==inf)puts("Impossible");
        else printf("%d\n",dis[t]);
    }
    //system("pause");
    return 0;
}
