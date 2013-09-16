#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;
int n,top;
struct node{
    int to;
    int d;
    node *next;
}nod[200010],*vert[5010];
int dis[5010];
bool mark[5010];
struct QN{
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
struct gnode{
    int u;
    int d;
    bool operator<(const gnode a)const
    {
        return a.d+dis[a.u]<d+dis[u];
    }
};
void Add_Edge(int u,int v,int va)
{
    node *p=&nod[top++];
    p->to=v;
    p->d=va;
    p->next=vert[u];vert[u]=p;

    p=&nod[top++];
    p->to=u;
    p->d=va;
    p->next=vert[v];vert[v]=p;
}
void Dijskra(int s)
{
    QN tem;
    priority_queue<QN>Q;
    memset(mark,false,sizeof(mark));
    dis[s]=0;
    tem.d=0;tem.u=s;
    Q.push(tem);
    while(!Q.empty())
    {
        int i;
        do{
            if(Q.size()==0)return ;
            tem=Q.top();Q.pop();
            i=tem.u;
        }while(mark[i]);
        mark[i]=true;
        for(node *p=vert[i];p;p=p->next)
        {
            if(!mark[p->to]&&dis[p->to]>dis[i]+p->d)
            {
                dis[p->to]=dis[i]+p->d;
                tem.u=p->to;
                tem.d=dis[p->to];
                Q.push(tem);
            }
        }
    }
}
int A_Star(int s,int min)
{
    gnode tem;
    priority_queue<gnode>Q;
    tem.d=0;
    tem.u=s;
    Q.push(tem);
    while(!Q.empty())
    {
        tem=Q.top();Q.pop();
        int i=tem.u,d=tem.d;
        if(i==n&&d>min)return d;
        for(node *p=vert[i];p;p=p->next)
        {
            tem.u=p->to;
            tem.d=d+p->d;
            Q.push(tem);
        }
    }
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int u,v,va;
        top=0;
        for(int i=1;i<=n;i++)
        {
            dis[i]=inf;
            vert[i]=NULL;
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&va);
            Add_Edge(u,v,va);
        }
        Dijskra(n);
        printf("%d\n",A_Star(1,dis[1]));
    }
    return 0;
}
