#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    int cost;
    edge *next;
}edg[10002],*vert[102];
int k,n,m;
struct QN{
    int u;
    int d;
    int cost;
    bool operator <(const QN &a)const{
        return a.d<d;
    }
};
void add_edge(int x,int y,int va,int ca,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->cost=ca;
    p->next=vert[x];    vert[x]=p;
}
int BFS(){
    QN now,next;
    priority_queue<QN>Q;
    now.u=1;    now.d=0;    now.cost=0;
    Q.push(now);
    while(!Q.empty()){
        now=Q.top();Q.pop();
        int u=now.u;
        if(u==n)return now.d;
        for(edge *p=vert[u];p;p=p->next){
            if(p->cost+now.cost<=k){
                next.u=p->to;
                next.d=now.d+p->d;
                next.cost=now.cost+p->cost;
                Q.push(next);
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d",&k)!=EOF){
        int top=-1;
        memset(vert,0,sizeof(vert));
        scanf("%d%d",&n,&m);
        while(m--){
            int u,v,va,ca;
            scanf("%d%d%d%d",&u,&v,&va,&ca);
            add_edge(u,v,va,ca,top);
        }
        printf("%d\n",BFS());
    }
    return 0;
}
