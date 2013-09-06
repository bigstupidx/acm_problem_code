#include<iostream>
#include<queue>
#define N 502
using namespace std;
struct nod{
    int to;
    int dis;
    nod *next;
}edge[1002],*vert[N];
int dist[502],n,aa[N],ans[N],top;
struct xx{
    int u;
    int dis;
    bool operator<(const xx a)const 
    {
        return a.dis>dis;
    }
};
void add_edge(int u,int v,int va)
{
    nod *p=&edge[top++];
    p->to=v;
    p->dis=va;
    p->next=vert[u];
    vert[u]=p;
    return ;
}
void dijskar(int s)
{
    xx now,next;
    priority_queue<xx>Q;
    for(int i=1;i<=n;i++)
        dist[i]=100000000;
    dist[s]=0;
    now.u=s;now.dis=0;
    Q.push(now);
    while(!Q.empty())
    {
        now=Q.top();Q.pop();
        for(nod *p=vert[now.u];p;p=p->next)
        {
            if(dist[p->to]>dist[now.u] + p->dis)
            {
                dist[p->to]=dist[now.u]+p->dis;
                next.u=p->to;
                next.dis=dist[p->to];
                Q.push(next);
            }
        }
    }
}
int main()
{
    int m,c,t;
    while(scanf("%d%d%d%d",&n,&m,&c,&t)!=EOF)
    {
        int count=0;
        top=0;
        for(int i=1;i<=n;i++)
            vert[i]=NULL;
        for(int i=0;i<m;i++)
        {
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            add_edge(u,v,va);
            add_edge(v,u,va);
        }
        for(int i=1;i<=c;i++)
            scanf("%d",aa+i);
        dijskar(1);
        for(int i=1;i<=c;i++)
            if(dist[aa[i]]<=t)ans[count++]=i;
        printf("%d\n",count);
        for(int i=0;i<count;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
