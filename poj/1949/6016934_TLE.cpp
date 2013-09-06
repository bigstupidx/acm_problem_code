#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[1000000],*vert[10010];
int n,in[10010],tim[10010],dis[10010];
void Add_Edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int s)
{
    for(edge *p=vert[s];p;p=p->next)
    {
        if(dis[p->to]<dis[s]+tim[p->to])
        {
            dis[p->to]=dis[s]+tim[p->to];
            DFS(p->to);
        }
    }
}
int topsort()
{
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0){
            dis[i]=tim[i];DFS(i);
        }
    }
    //for(int i=1;i<=n;i++)
    //    printf("%d ",dis[i]);
    //puts("");
    int maxi=-1;
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
