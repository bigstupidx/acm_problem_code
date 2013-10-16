#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[3000002],*vert[1002];
const int inf = 1000000000;
int n,mark[1002],cnt[1002],dis[1002];
struct QN{
    int u;
    int d;
    bool operator <(const QN &a)const{
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
    QN now;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++){dis[i]=inf;mark[i]=0;}
    now.u=s;    now.d=0;    dis[s]=0;   cnt[s]=1;
    Q.push(now);
    for(int k,i=1;i<n;i++){
        do{
            if(Q.empty())return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=vert[k];p;p=p->next){
            if(!mark[p->to]&&dis[p->to]>dis[k]+p->d){
                dis[p->to]=dis[k]+p->d;
                cnt[p->to]=cnt[k];
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
            else if(dis[p->to]==dis[k]+p->d)
                cnt[p->to]+=cnt[k];
        }
    }
}

int main()
{
//  printf("%I64d\n",inf);
    while(scanf("%d",&n),n){
        int m,top=-1;
        scanf("%d",&m);
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++){
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            add_edge(u,v,va,top);
            add_edge(v,u,va,top);
        }
        memset(cnt,0,sizeof(cnt));
        dijkstra(1);
        printf("%d\n",cnt[2]);
    }
    return 0;
}
