#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to;
    int va;
    int wi;
    edge *next;
}edg[10010],*vert[102];
int total,n,m,cnt[102],in[102];
struct QN {
    int u;
    int d;
    int wi;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};

void Add_Edge(int x,int y,int va,int wi,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->va=va;
    p->wi=wi;
    p->next=vert[x];    vert[x]=p;
}
int A_Star()
{
    QN now,next;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++)cnt[i]=0;
    now.u=1;    now.d=0;    now.wi=0;
    Q.push(now);    in[1]=1;
    while(!Q.empty())
    {
        now=Q.top();Q.pop();
        int k=now.u;
        if(k==n&&now.wi<=total)return now.d;
        if(cnt[k]>in[k])continue;
        for(edge *p=vert[k];p;p=p->next)
        {
            next.u=p->to;
            next.d=p->va+now.d;
            next.wi=p->wi+now.wi;
            Q.push(next);
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d",&total)!=EOF)
    {
        int x,y,va,wi,top=-1;
        scanf("%d%d",&n,&m);
        memset(in,0,sizeof(in));
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&x,&y,&va,&wi);
            in[y]++;    Add_Edge(x,y,va,wi,top);
        }
        printf("%d\n",A_Star());
    }
    return 0;
}
