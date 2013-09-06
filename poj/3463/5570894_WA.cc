
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000

using namespace std;
struct node{
    int to;
    int d;
    node *next;
}nod[2][10010],*vert[2][1010];
int n,top,c[2][1010],dis[2][1010];
bool mark[1010];
struct QN{
    int u,d;
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
    p->next=vert[0][u];
    vert[0][u]=p;

    p=&nod[1][top++];
    p->to=u;
    p->d=va;
    p->next=vert[1][v];
    vert[1][v]=p;
}
void Dijskra(int s,int i)
{
    QN now;
    priority_queue<QN>Q;
    memset(mark,false,sizeof(mark));
    memset(c[i],0,sizeof(c[i]));
    dis[i][s]=0;c[i][s]=1;
    now.u=s;now.d=0;
    Q.push(now);
    while(!Q.empty())
    {
        int k;
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=true;
        for(node *p=vert[i][k]; p ;p = p->next)
        {
            if(!mark[p->to]&&dis[i][p->to]>dis[i][k]+p->d)
            {
                c[i][p->to]=c[i][k];
                dis[i][p->to]=dis[i][k]+p->d;
                now.d=dis[i][p->to];
                now.u=p->to;
                Q.push(now);
            }
            else if(dis[i][p->to]==dis[i][k]+p->d)
            {
                c[i][p->to]+=c[i][k];
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
            vert[0][i]=NULL;
            vert[1][i]=NULL;
            dis[0][i]=inf;
            dis[1][i]=inf;
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&va);
            Add_Edge(u,v,va);
        }
        scanf("%d%d",&u,&v);
        Dijskra(u,0);Dijskra(v,1);
        /*for(int i=1;i<=n;i++)
            printf("%d ",dis[0][i]);
        puts("");
        for(int i=1;i<=n;i++)
            printf("%d ",c[0][i]);
        puts("");
        for(int i=1;i<=n;i++)
            printf("%d ",dis[1][i]);
        puts("");
        for(int i=1;i<=n;i++)
            printf("%d ",c[1][i]);
        puts("");*/
        int ans=c[0][v],temp=dis[0][v];
        for(int i=1;i<=n;i++)
            for(node *p=vert[0][i]; p ; p=p->next)
                if(p->d==1+dis[0][p->to]-dis[0][i]&&dis[0][p->to]+dis[1][p->to]==temp)
                {
                    //printf("%d %d\n",i,p->to);
                    ans++;
                }
        printf("%d\n",ans);
    }
    return 0;
}
