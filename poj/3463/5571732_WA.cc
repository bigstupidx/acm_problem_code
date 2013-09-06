
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000

using namespace std;

int n,top;
bool mark[1010];

struct node{
    int to;
    int d;
    node *next;
}nod[10010],*vert[1010];

struct QN{
    int u,d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
struct CC{
    int c1,c2;
    int d1,d2;
}c[1010];

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
    QN now;
    priority_queue<QN>Q;
    memset(mark,false,sizeof(mark));
    now.u=s;now.d=0;
    c[s].c1=1;c[s].c2=1;
    c[s].d1=0;c[s].d2=0;
    Q.push(now);
    for(int i=1;i<=2*n;i++)
    {
        int k;
        do{
            if(Q.empty())return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=true;
        for(node *p=vert[k]; p ;p=p->next)
        {
            if(c[p->to].d1>c[k].d1+p->d)
            {
                c[p->to].d2=c[p->to].d1;
                c[p->to].d1=c[k].d1+p->d;
                c[p->to].c2=c[p->to].c1;
                c[p->to].c1=c[k].c1;
                now.d=c[p->to].d1;
                now.u=p->to;
                Q.push(now);
            }
            else if(c[p->to].d1==c[k].d1+p->d)
            {
                c[p->to].c1+=c[k].c1;
            }
            else if(c[p->to].d2>c[k].d1+p->d)
            {
                c[p->to].d2=c[k].d1+p->d;
                c[p->to].c2=c[k].c1;
            }
            else if(c[p->to].d2==c[k].d1+p->d)
            {
                c[p->to].c2+=c[k].c1;
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int u,v,va,m;
        scanf("%d%d",&n,&m);
        top=0;
        for(int i=1;i<=n;i++)
        {
            vert[i]=NULL;
            c[i].c1=0;c[i].c2=0;
            c[i].d1=inf;c[i].d2=inf;
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&va);
            Add_Edge(u,v,va);
        }
        scanf("%d%d",&u,&v);
        Dijskra(u);
        printf("%d\n",c[v].c1+c[v].c2);
    }
    return 0;
}
