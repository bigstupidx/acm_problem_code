#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[20010],*vert[1010];
struct node{
    int x,y,va;
    bool operator<(const node a)const
    {
        return a.va>va;
    }
}nod[10010];
int ans[10010],n,m,K,dis[1010],mark[1010];
const int inf = 1000000000;
struct QN {
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
void Add_Edge(int x,int y,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
int Dijkstra()
{
    QN now;
    int i,k;
    priority_queue<QN>Q;
    for(i=1;i<=n;i++){dis[i]=inf;   mark[i]=0;}
    now.u=1;    now.d=0;    dis[1]=0;
    Q.push(now);
    for(i=1;i<n;i++)
    {
        do{
            if(Q.size()==0)return dis[n];
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=vert[k];p;p=p->next)
        {
            if(!mark[p->to]&&dis[p->to]>dis[k]+p->d)
            {
                dis[p->to]=dis[k]+p->d;
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
    return dis[n];
}
void Build_G(int top)
{
    int tot=-1,i;
    memset(vert,0,sizeof(vert));
    for(i=0;i<=top;i++){
        Add_Edge(nod[i].x,nod[i].y,0,tot);
        Add_Edge(nod[i].y,nod[i].x,0,tot);
    }
    for(;i<m;i++){
        Add_Edge(nod[i].x,nod[i].y,1,tot);
        Add_Edge(nod[i].y,nod[i].x,1,tot);
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&K)!=EOF)
    {
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&nod[i].x,&nod[i].y,&nod[i].va);
        sort(nod,nod+m);
        //printf("%d ",nod[0].va);
        int l=0,r=m-1,mid,tem;
        while(l<=r)
        {
            mid=(l+r)/2;
            Build_G(mid);
            tem=Dijkstra();
            ans[mid]=tem;
            //printf("trye mid %d %d\n",nod[mid].va,tem);
            if(tem==inf||tem>K)
                l=mid+1;
            else
                r=mid-1;
        }
        if(l==m)puts("-1");
        else{
            if(ans[l]<=K)puts("0");
            else printf("%d\n",nod[l].va);
        }
    }
    return 0;
}
