#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int st;
    int d;
    edge *next;
}edg[10010],*vert[202];
int s,t,n,m;
const int inf = 1000000000;
struct QN{ int u, st, d; };

void Add_Edge(int x,int y,int st,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->st=st;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
int BFS()
{
    QN now,next;
    queue<QN>Q;
    for(edge *p=vert[s];p;p=p->next)
    {
        now.u=p->to;
        now.st=p->st;
        now.d=p->st+p->d;
        Q.push(now);
    }
    int mini=inf;
    while(!Q.empty())
    {
        now=Q.front();Q.pop();
        int k=now.u;
        if( k == t && mini > now.d - now.st )
            mini = now.d - now.st;
        for(edge *p=vert[k];p;p=p->next)
        {
            if( now.d <= p->st )
            {
                next.st=now.st;
                next.u=p->to;
                next.d=p->st+p->d;
                Q.push(next);
            }
        }
    }
    return mini;
}
int main()
{
    while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF)
    {
        int top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            int x,y,st,ed,d;
            scanf("%d%d%d%d%d",&x,&y,&st,&ed,&d);
            if(ed-st<d)continue;
            Add_Edge(x,y,st,d,top);
        }
        int temp=BFS();
        if(temp==inf)puts("Impossible");
        else printf("%d\n",temp);
    }
    return 0;
}
