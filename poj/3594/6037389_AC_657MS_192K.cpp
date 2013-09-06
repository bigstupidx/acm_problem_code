#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int st,ed;
    int d;
    edge *next;
}edg[10010],*vert[202];
int s,t,n,m,mark[202];
const int inf = 1000000000;
struct QN{
    int u, d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};

void Add_Edge(int x,int y,int st,int ed,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->st=st;
    p->ed=ed;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}

int Max(int x,int y){return x>y?x:y;}
int BFS(int tim)
{
    QN tem;
    priority_queue<QN>Q;
    memset(mark,0,sizeof(mark));
    tem.u=s,tem.d=tim;
    Q.push(tem);
    while(!Q.empty())
    {
        tem=Q.top();Q.pop();
        int k=tem.u,tt=tem.d;
        if(mark[k])continue;
        if(k==t)return  tt-tim;
        mark[k]=1; 
        for(edge *p=vert[k];p;p=p->next)
        {
            if(mark[p->to])continue;
            tem.d=Max(tt,p->st)+p->d;//关键 
            if(tem.d<=p->ed)
            {
                tem.u=p->to;
                Q.push(tem);
            }
        }
    }
    return inf;
}
int solve()
{
    int mini=inf,len=-1;
    for(edge *p=vert[s];p;p=p->next)
    {
        if(len<p->st)len=p->st;
    }
    for(int i=0;i<=len;i++)
    {
        int temp=BFS(i);
        if(temp<mini)mini=temp;
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
            Add_Edge(x,y,st,ed,d,top);
        }
        if(s==t)puts("0");
        else{
            int temp=solve();
            if(temp==inf)puts("Impossible");
            else printf("%d\n",temp);
        }
    }
    return 0;
}
