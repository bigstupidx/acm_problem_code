#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[200010],*vert[1002],*r_vert[1002];
const int inf = 1000000000;
int n,m,k,dis[1002],mark[1002],cnt[1002];
struct QN{
    int u;
    int d;
    bool operator <(const QN &a)const{
        return a.d<d;
    }
};
struct gnode{
    int u;
    int d;
    bool operator <(const gnode &a)const{
        return a.d+dis[a.u]<d+dis[u];
    }
};
void add_edge(int x,int y,int va,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
    
    p=&edg[++top];
    p->to=x;
    p->d=va;
    p->next=r_vert[y];  r_vert[y]=p;
}
void dijkstra(int s){
    QN now;
    priority_queue<QN>Q;
    for(int i=0;i<n;i++){dis[i]=inf;mark[i]=0;}
    now.u=s;    now.d=0;    dis[s]=0;
    Q.push(now);
    for(int k,i=1;i<n;i++){
        do{
            if(Q.empty())return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=r_vert[k];p;p=p->next){
            if(!mark[p->to]&&dis[p->to]>dis[k]+p->d){
                dis[p->to]=dis[k]+p->d;
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
}
int a_star(int s,int t){
    gnode now,next;
    priority_queue<gnode>Q;
    if(dis[s]==inf)return -1;
    now.u=s;    now.d=0;
    Q.push(now);
    memset(cnt,0,sizeof(cnt));
    while(!Q.empty()){
        now=Q.top();Q.pop();
        int u=now.u;
        cnt[u]++;
        if(cnt[u]>k)continue;
        if(cnt[t]==k)return now.d;
        for(edge *p=vert[u];p;p=p->next){
            next.u=p->to;
            next.d=now.d+p->d;
            Q.push(next);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        int s,t,top=-1;
        memset(vert,0,sizeof(vert));
        memset(r_vert,0,sizeof(r_vert));
        for(int i=0;i<m;i++){
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            u--;    v--;
            add_edge(u,v,va,top);
        }
        scanf("%d%d%d",&s,&t,&k);
        s--;    t--;
        dijkstra(t);
        if(s==t)k++;
        printf("%d\n",a_star(s,t));
    }
    return 0;
}
