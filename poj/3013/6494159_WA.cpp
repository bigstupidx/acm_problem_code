#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[50010],*vert[50010];
int dis[50010],cost[50010],mark[50010],n,m;
const int inf = 1000000000;
struct node{
    int u;
    int d;
    bool operator <(const node &a)const{
        return a.d<d;
    }
};
void add_edge(int x,int y,int va,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
void dijkstra(int s){
    node now;
    priority_queue<node>Q;
    now.u=s;    now.d=0;    dis[s]=0;
    Q.push(now);
    for(int i=1,k;i<n;i++){
        do{
            if(Q.empty())return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=vert[k];p;p=p->next){
            if(!mark[p->to]&&dis[p->to]>dis[k]+p->d){
                dis[p->to]=dis[k]+p->d;
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        int top=-1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            dis[i]=inf;
            mark[i]=0;
            vert[i]=NULL;
            scanf("%d",cost+i);
        }
        for(int i=0;i<m;i++){
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            add_edge(u,v,va,top);
        }
        dijkstra(1);
        __int64 sum=0;
        for(int i=1;i<=n;i++)
            sum+=cost[i]*dis[i];
        printf("%I64d\n",sum);
    }
    return 0;
}
