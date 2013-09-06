#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[1000000],*vert[10010];
struct QN{
    int u;
    int tt;
};
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
    queue<QN>Q;
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=n;i++)
        if(in[i]==0){
            now.u=i;now.tt=tim[i];
            dis[i]=tim[i];Q.push(now);
        }
    while(!Q.empty())
    {
        now=Q.front();Q.pop();
        int k=now.u,tt=now.tt;
        for(edge *p=vert[k];p;p=p->next)
        {
            if(dis[p->to]<dis[k]+tim[p->to])
            {
                dis[p->to]=dis[k]+tim[p->to];
                next.u=p->to;
                next.tt=dis[p->to];
                Q.push(next);
            }
        }
    }
    int maxi=-1;
    //for(int i=1;i<=n;i++)
    //    printf("%d ",dis[i]);
    //puts("");
    for(int i=1;i<=n;i++)
        if(maxi<dis[i])maxi=dis[i];
    return maxi;
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
