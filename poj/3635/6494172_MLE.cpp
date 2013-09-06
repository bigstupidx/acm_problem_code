#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[10010],*vert[1010];
int n,m,prc[1010],cap;
struct node{
    int u;
    int cost;
    int cap;
    bool operator <(const node &a)const{
        return a.cost<cost;
    }
};
void add_edge(int x,int y,int va,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
int BFS(int s,int t){
    node now,next;
    priority_queue<node>Q;
    now.u=s;    now.cost=0;     now.cap=0;
    Q.push(now);
    while(!Q.empty()){
        now=Q.top();Q.pop();
        int u=now.u;
        //printf("%d %d\n",u,now.cost);
        if(u==t)return now.cost;
        for(edge *p=vert[u];p;p=p->next){
            for(int i=now.cap;i<=cap;i++){
                if(i-p->d>=0){
                    next.u=p->to;
                    next.cost=now.cost+(i-now.cap)*prc[u];
                    next.cap=i-p->d;
                    Q.push(next);
                }
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        int top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<n;i++)scanf("%d",prc+i);
        for(int i=0;i<m;i++){
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            add_edge(u,v,va,top);
        }
        int q;
        scanf("%d",&q);
        while(q--){
            int s,t;
            scanf("%d%d%d",&cap,&s,&t);
            cap=BFS(s,t);
            if(cap==-1)puts("impossible");
            else printf("%d\n",cap);
        }
    }
    return 0;
}
