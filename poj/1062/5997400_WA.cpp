#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[10010],*vert[120];

int n,dis[120],mark[120],pri[120],L[120];
int limit,tra[120][120],mon[120][120];
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
    printf("%d -> %d %d\n",x,y,va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
int ABS(int x)
{
    return x>0?x:-x;
}
void Build()
{
    int top=-1;
    memset(vert,0,sizeof(vert));
    for(int i=1;i<=n;i++)
    {
        if(ABS(L[1]-L[i])<=limit)
        {
            Add_Edge(0,i,pri[i],top);
            for(int j=1;j<=tra[i][0];j++)
                Add_Edge(tra[i][j],i,mon[i][j],top);
        }
    }
}
void Dijkstra()
{
    QN now;
    priority_queue<QN>Q;
    for(int i=0;i<=n;i++){dis[i]=inf;mark[i]=0;}
    dis[0]=0;
    now.u=0;    now.d=0;
    Q.push(now);
    while(!Q.empty())
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
    while(scanf("%d%d",&limit,&n)!=EOF)
    {
        int m;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&pri[i],&L[i],&m);
            tra[i][0]=m;
            for(int j=1;j<=m;j++)
            {
                int jj,money;
                scanf("%d%d",&jj,&money);
                tra[i][j]=jj;mon[i][j]=money;
            }
        }
        Build();
        Dijkstra();
        printf("%d\n",dis[1]);
    }
    return 0;
}
