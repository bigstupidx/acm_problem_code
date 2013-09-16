#include<queue>
#include<cstdio>
#define INF 1000000000
using namespace std;

struct node{
    int to;
    int d;
    node *next;
}nod[200010],*vert[1010];
struct gnode{
    int u;
    int d;
    bool operator<(const gnode a)const
    {
        return a.d<d;
    }
};
int n,dis[1010],top,flag[1010];

void Add_Edge(int u,int v,int va)
{
    node *p=&nod[top++];
    p->to=v;
    p->d=va;
    p->next=vert[u];
    vert[u]=p;
}
void Dijskra(int s)
{
    gnode now,next;
    priority_queue<gnode>Q;
    for(int i=1;i<=n;i++)
    {
        flag[i]=0;
        dis[i]=INF;
    }
    dis[s]=0;
    now.u=s;now.d=0;
    Q.push(now);
    for(int i=0;i<n;i++)
    {
        int k;
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(flag[k]);
        flag[k]=1;
        for(node *p=vert[k];p;p=p->next)
        {
            if(!flag[p->to] && dis[p->to]>p->d+dis[k])
            {
                dis[p->to]=p->d+dis[k];
                next.u=p->to;
                next.d=dis[p->to];
                Q.push(next);
            }
        }
    }
}
int A_Star(int s,int t,int k)
{
    gnode now,next;
    priority_queue<gnode>Q;
    if(dis[s]==INF)return -1;
    memset(flag,0,sizeof(flag));
    now.u=s;now.d=0;
    Q.push(now);
    while(!Q.empty())
    {
        now=Q.top();Q.pop();
        flag[now.u]++;
        if(flag[t]==k)return now.d;
        if(flag[now.u]>k)continue;
        for(node *p=vert[now.u];p;p=p->next)
        {
            next.u=p->to;
            next.d=p->d+now.d;
            Q.push(next);
        }
    }
    return -1;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int u,v,d;
        top=0;
        for(int i=1;i<=n;i++)
            vert[i]=NULL;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&d);
            Add_Edge(u,v,d);
        }
        int s,t,k;
        scanf("%d%d%d",&s,&t,&k);
        Dijskra(t);
        printf("%d\n",A_Star(s,t,k));
    }
    return 0;
}
