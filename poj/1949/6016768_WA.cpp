#include <cstdio>
#include <cstring>
struct edge{
    int to;
    edge *next;
}edg[1000000],*vert[10010];
struct QN{
    int u;
    int tt;
}Q[10010];
int n,in[10010],tim[10010],dis[10010];
void Add_Edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
int topsort()
{
    QN now,next;
    int rr=0,ff=0;
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=n;i++)
        if(in[i]==0){
            now.u=i;now.tt=tim[i];
            dis[i]=tim[i];Q[rr++]=now;
        }
    while(ff!=rr)
    {
        now=Q[ff++];ff=ff%(n+2);
        int v=now.u;
        for(edge *p=vert[v];p;p=p->next)
        {
            int u=p->to;
            if(dis[u]<dis[v]+tim[u])
            {
                dis[u]=dis[v]+tim[u];
                next.u=u;
                next.tt=dis[u];
                Q[rr++]=next;   rr=rr%(n+2);
            }
        }
    }
    return dis[n];
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int top=-1;
        memset(in,0,sizeof(in));
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++)
        {
            int m,x;
            scanf("%d%d",&tim[i],&m);
            in[i]=m;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&x);
                Add_Edge(x,i,top);
            }
        }
        printf("%d\n",topsort());
    }
    return 0;
}
