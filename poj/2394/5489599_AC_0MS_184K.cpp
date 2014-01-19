#include<iostream>
#include<queue>
#define N 502      /*¶¥µã×î´óÊý */
#define M 2010     /*±ßÊý×î´óÊý*/
#define INF 10000000
using namespace std;
 
struct nod{
    int to;
    int dis;
    nod *next;
}edges[M],*vert[N];

struct QN{
    int u;
    int dis;
    bool operator<(const QN a)const
    {
        return a.dis<dis;
    }
};

int top,n,m,dist[N],mark[N],aa[N],ans[N];

void add_edge(int u,int v,int va)
{
    nod *p=&edges[top++];
    p->to=v;
    p->dis=va;
    p->next=vert[u];
    vert[u]=p;
    return ;
}

void dijskra(int s)
{
    QN now;
    int i,k;
    priority_queue<QN> Q;
    memset(mark,0,sizeof(mark));
    for(i=1;i<=n;i++)
        dist[i]=INF;
    dist[s]=0;
    now.u=s;now.dis=0;
    Q.push(now);
    for(i=1 ;i<n;i++)
    {
        do{
            if(Q.size()==0)
                return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        /*¸üÐÂ¶¥µã*/
        for(nod *p=vert[k]; p ;p=p->next)
            if(!mark[p->to] && dist[p->to] > dist[k]+p->dis)
            {
                dist[p->to]=dist[k]+p->dis;
                now.u=p->to;
                now.dis=dist[p->to];
                Q.push(now);
            }
    }
    return ;
}
int main()
{
    int t,c;
    while(scanf("%d%d%d%d",&n,&m,&c,&t)!=EOF)
    {
        int i,u,v,va;
        for(int i=1;i<=n;i++)
            vert[i]=NULL;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&va);
            add_edge(u,v,va);
            add_edge(v,u,va);
        }
        dijskra(1);
        for(i=1;i<=c;i++)
            scanf("%d",aa+i);
        int count=0;
        for(i=1;i<=c;i++)
            if(dist[aa[i]]<=t)
                ans[count++]=i;
        printf("%d\n",count);
        for(int i=0;i<count;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
