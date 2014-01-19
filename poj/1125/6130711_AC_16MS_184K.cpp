#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[10010],*vert[120];
int n,dis[120],mark[120];
const int inf = 1000000000;
struct QN{
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
void add_edge(int u,int v,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=v;
    p->d=va;
    p->next=vert[u];    vert[u]=p;
}
void dijkstra(int s)
{
    QN now;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++){dis[i]=inf;   mark[i]=0;}
    now.u=s;    now.d=0;    dis[s]=0;
    Q.push(now);
    for(int k, i=1;i<n;i++)
    {
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
    while(scanf("%d",&n),n)
    {
        int top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++)
        {
            int m,v,va;
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d%d",&v,&va);
                add_edge(i,v,va,top);
            }
        }
        int kk=-1,ans=-1;
        for(int i=1;i<=n;i++)
        {
            dijkstra(i);
            int maxi=-1,j;
            for(j=1;j<=n;j++)
            {
                if(dis[j]==inf)break;
                if(maxi<dis[j])maxi=dis[j];
            }
            if(j<=n)continue;
            //printf("%d %d\n",i,maxi);
            if(ans==-1||maxi<ans)
            {
                ans=maxi;   kk=i;
            }
        }
        if(ans==-1)puts("disjoint");
        else
            printf("%d %d\n",kk,ans);
    }
    return  0;
}
