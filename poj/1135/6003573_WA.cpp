#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[500010],*vert[502];
int n,m,dis[502],mark[502];
const int inf = 1000000000;
struct QN{
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
void Add_Edge(int x,int y,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
void Dijkstra()
{
    QN now;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++){dis[i]=inf;mark[i]=0;}
    dis[1]=0;
    now.u=1;    now.d=0;
    Q.push(now);
    while(!Q.empty())
    {
        int k;
        do{
            if(Q.empty())return ;
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
    int tt=0;
    while(scanf("%d%d",&n,&m),n||m)
    {
        int top=-1,x,y,va;  tt++;
        memset(vert,0,sizeof(vert));
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&va);
            Add_Edge(x,y,va,top);
            Add_Edge(y,x,va,top);
        }
        Dijkstra();
        double ans=0;
        int k=1,r=-1;
        //for(int i=1;i<=n;i++)
        //    printf("%d ",dis[i]);
        //puts("");
        for(int i=2;i<=n;i++)
            if(ans<dis[i]){k=i;ans=dis[i];}
        for(edge *p=vert[k];p;p=p->next)
        {
            if(ans<(p->d-(dis[k]-dis[p->to]))*1.0/2+dis[p->to]){
                ans=(p->d-(dis[k]-dis[p->to]))*1.0/2+dis[p->to];
                r=p->to;
            }
        }
        printf("System #%d\n",tt);
        if(r==-1)
            printf("The last domino falls after %.1lf seconds, at key domino %d.\n",ans,k);
        else{
            if(r<k){int tem;tem=r;r=k;k=tem;}
            printf("The last domino falls after %.1lf seconds, at key dominoes %d and %d.\n",ans,k,r);
        }
    }
    return 0;
}
