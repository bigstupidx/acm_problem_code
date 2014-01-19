#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int st;
    int d;
    edge *next;
}edg[1010],*vert[120];
int s,t,n,m,mark[120];
const int inf = 1000000000;
struct QN{
    int u;
    int st;
    int d;
};
void Add_Edge(int x,int y,int st,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->st=st;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
int solve()
{
    QN now,next;
    int maxi=inf;
    queue<QN>Q;
    for(edge *p=vert[s];p;p=p->next)
    {
        now.u=p->to;
        now.st=p->st;
        now.d=p->d;
        Q.push(now);
    }
    while(!Q.empty())
    {
        now=Q.front();Q.pop();
        int k=now.u,tim=now.d;
        if(k==t && maxi > tim-now.st)maxi = tim-now.st;
        for(edge *p=vert[k];p;p=p->next)
        {
            if( tim < p->st )
            {
                mark[p->to]=1;
                next.st=now.st;
                next.u=p->to;
                next.d=p->st+p->d;
                Q.push(next);
            }
        }
    }
    return maxi;
}
int main()
{
    while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF)
    {
        int top=-1,x,y,st,ed,d;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d%d",&x,&y,&st,&ed,&d);
            if(ed-st<d)continue;
            Add_Edge(x,y,st,d,top);
        }
        int temp=solve();
        if(temp==inf)puts("Impossible");
        else printf("%d\n",temp);
    }
    return 0;
}
