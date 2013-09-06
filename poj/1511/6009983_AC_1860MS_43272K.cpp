#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[4000010],*vert[2][1000010];
struct QN{
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
int dis[2][1000010],mark[1000010],n,m;
const int inf = 1000000000;
void Add_Edge(int x,int y,int va,int &top)
{
    //printf("%d -> %d %d\n",x,y,va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[0][x]; vert[0][x]=p;
    
    p=&edg[++top];
    p->to=x;
    p->d=va;
    p->next=vert[1][y]; vert[1][y]=p;
}
void Dijkstra(int k)
{
    QN now;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++){dis[k][i]=inf;mark[i]=0;}
    now.u=1;    now.d=0;    dis[k][1]=0;
    Q.push(now);
    for(int i=1;i<n;i++)
    {
        int j;
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            j=now.u;
        }while(mark[j]);
        mark[j]=1;
        for(edge *p=vert[k][j];p;p=p->next)
        {
            if(!mark[p->to]&&dis[k][p->to]>dis[k][j]+p->d)
            {
                dis[k][p->to]=dis[k][j]+p->d;
                now.u=p->to;
                now.d=dis[k][p->to];
                Q.push(now);
            }
        }
    }
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--)
    {
        int x,y,va,top=-1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)vert[0][i]=vert[1][i]=NULL;
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&va);
            Add_Edge(x,y,va,top);
        }
        Dijkstra(0);Dijkstra(1);
        /*
        for(int i=1;i<=n;i++)
            printf("%d ",dis[0][i]);
        puts("");
        for(int i=1;i<=n;i++)
            printf("%d ",dis[1][i]);
        puts("");
        */
        long long ans=0;
        for(int i=1;i<=n;i++)
            ans+=dis[0][i]+dis[1][i];
        printf("%lld\n",ans);
    }
    return 0;
}
