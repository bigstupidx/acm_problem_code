#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[10010],*vert[120];

int n,dis[120],mark[120],pri[120],L[120],LL[120];
int limit,tra[120][120],mon[120][120];
const int inf= 1000000000 ;

struct QN{
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
void Add_Edge(int x,int y,int va,int &top)
{
    //printf("%d -> %d %d\n",x,y,va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
int ABS(int x){ return x>0?x:-x;}
void Build(int x)
{
    int top=-1;
    memset(vert,0,sizeof(vert));
    for(int i=1;i<=n;i++)
    {
        if(L[i]>=x&&L[i]-x<=limit){
            Add_Edge(0,i,pri[i],top);
            for(int j=1;j<=tra[i][0];j++){
                Add_Edge(tra[i][j],i,mon[i][j],top);
            }
        }
    }
}
void Dijkstra()
{
    QN now;
    priority_queue<QN>Q;
    for(int i=0;i<=n;i++){dis[i]=inf;mark[i]=0;}
    dis[0]=0;   L[0]=L[1];
    now.u=0;    now.d=0;
    Q.push(now);
    while(!Q.empty())
    {
        int i; 
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            i=now.u;
        }while(mark[i]);
        mark[i]=1;
        for(edge *p=vert[i];p;p=p->next)
        {
            if(!mark[p->to]&&dis[p->to]>dis[i]+p->d)
            {
                dis[p->to]=dis[i]+p->d;
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&limit,&n)!=EOF)
    {
        int m;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&pri[i],&L[i],&m);
            tra[i][0]=m;    LL[i]=L[i];
            for(int j=1;j<=m;j++)
            {
                int jj,money;
                scanf("%d%d",&jj,&money);
                tra[i][j]=jj;mon[i][j]=money;
            }
        }
        int mini=inf,i=1;
        sort(LL+1,LL+n+1);
        while(i<=n)
        {
            //printf("%d ",LL[i]);
            Build(LL[i]);
            Dijkstra();
            if(mini>dis[1])mini=dis[1];
            i++;
            if(LL[i]-L[1]>limit)break;
            //printf("%d\n",mini);
        }
        printf("%d\n",mini);
    }
    return 0;
}
