
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000

using namespace std;

int n,top;
int mark[2][1010],c[2][1010],dis[2][1010];

struct node{
    int to;
    int d;
    node *next;
}nod[10010],*vert[1010];


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
    memset(c,0,sizeof(c));
    memset(mark,0,sizeof(mark));
    dis[0][s]=0;c[0][s]=1;
    for(int i=1;i<=2*n;i++)
    {
        int min=inf,k,sign;
        for(int j=1;j<=n;j++)
        {
            if(!mark[0][j]&&min>dis[0][j])
            {
                sign=0;k=j;
                min=dis[0][j];
            }
            else if(!mark[1][j]&&min>dis[1][j])
            {
                sign=1;k=j;
                min=dis[1][j];
            }
        }
        if(min==inf)return ;
        mark[sign][k]=1;
        for(node *p=vert[k]; p ;p=p->next)
        {
            if(dis[0][p->to]>min+p->d)
            {
                dis[1][p->to]=dis[0][p->to];
                dis[0][p->to]=min+p->d;
                c[1][p->to]=c[0][p->to];
                c[0][p->to]=c[sign][k];
            }
            else if(dis[0][p->to]==min+p->d)
                c[0][p->to]+=c[sign][k];
            else if(dis[1][p->to]>min+p->d)
            {
                c[1][p->to]=c[sign][k];
                dis[1][p->to]=min+p->d;
            }
            else if(dis[1][p->to]==min+p->d)
                c[1][p->to]+=c[sign][k];
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
        for(int i=1;i<=n;i++){
            vert[i]=NULL;
            dis[0][i]=inf;dis[1][i]=inf;
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&va);
            Add_Edge(u,v,va);
        }
        scanf("%d%d",&u,&v);
        Dijskra(u);
        if(dis[0][v]+1==dis[1][v])printf("%d\n",c[0][v]+c[1][v]);
        else printf("%d\n",c[0][v]);
    }
    return 0;
}
