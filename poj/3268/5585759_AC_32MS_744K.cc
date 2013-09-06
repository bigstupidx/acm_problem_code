#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000

using namespace std;

struct node{
    int to;
    int d;
    node *next;
}nod[2][100010],*vert[2][1010];

int dis[2][1010],top,n,mark[1010];

struct QN{
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
void Add_Edge(int u,int v,int va)
{
    node *p=&nod[0][top];
    p->to=v;
    p->d=va;
    p->next=vert[0][u];vert[0][u]=p;

    p=&nod[1][top++];
    p->to=u;
    p->d=va;
    p->next=vert[1][v];vert[1][v]=p;
}
void Dijskra(int s,int now)
{
    QN tem;
    priority_queue<QN>Q;
    memset(mark,0,sizeof(mark));
    dis[now][s]=0;
    tem.d=0;tem.u=s;
    Q.push(tem);
    while(!Q.empty())
    {
        int i;
        do{
            if(Q.empty())return ;
            tem=Q.top();Q.pop();
            i=tem.u;
        }while(mark[i]);
        mark[i]=1;
        for(node *p=vert[now][i]; p ;p=p->next)
        {
            if(!mark[p->to] && dis[now][p->to]>dis[now][i]+p->d)
            {
                dis[now][p->to]=dis[now][i]+p->d;
                tem.u=p->to;
                tem.d=dis[now][p->to];
                Q.push(tem);
            }
        }
    }
    return ;
}
int main()
{
    int m,s;
    while(scanf("%d%d%d",&n,&m,&s)!=EOF)
    {
        int u,v,va;
        top=0;
        for(int i=1;i<=n;i++){
            vert[0][i]=vert[1][i]=NULL;
            dis[0][i]=dis[1][i]=inf;
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&va);
            Add_Edge(u,v,va);
        }
        Dijskra(s,0);
        Dijskra(s,1);
        int ans=dis[1][1]+dis[0][1];
        for(int i=2;i<=n;i++)
            if(ans<dis[0][i]+dis[1][i])
                ans=dis[0][i]+dis[1][i];
        printf("%d\n",ans);
    }
    return 0;
}
