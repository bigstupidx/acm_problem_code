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
    QN tem;
    queue<QN>Q;
    for(edge *p=vert[s];p;p=p->next)
    {
        tem.u=p->to;
        tem.st=p->st;
        tem.d=p->st+p->d;
        Q.push(tem);
    }
    int mini=inf;
    while(!Q.empty())
    {
        tem=Q.front();Q.pop();
        int k=tem.u;
        if( k == t && mini > tem.d - tem.st )
            mini = tem.d - tem.st;
        for(edge *p=vert[k];p;p=p->next)
        {
            if( tem.d <= p->st )
            {
                tem.u=p->to;
                tem.d=p->st+p->d;
                Q.push(tem);
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
        if(s==t)puts("0");
        else{
            int temp=BFS();
            if(temp==inf)puts("Impossible");
            else printf("%d\n",temp);
        }
    }
    return 0;
}
