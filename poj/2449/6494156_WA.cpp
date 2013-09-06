#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int inf = 1000000000;
int n,m,k,mark[1010],dis[1010];
struct edge{
    int to;
    int va;
    edge *next;
}edg[200010],*vert[2][1010];
struct node{
    int u;
    int d;
    bool operator <(const node &a)const{
        return a.d<d;
    }
};
struct gnode{
    int u;
    int d;
    bool operator <(const gnode &a)const{
        return dis[a.u]+a.d<dis[u]+d;
    }
};
void add_edge(int u,int v,int va,int &top){
    edge *p=&edg[++top];
    p->to=v;
    p->va=va;
    p->next=vert[0][u];    vert[0][u]=p;
    
    p=&edg[++top];
    p->to=u;
    p->va=va;
    p->next=vert[1][v];     vert[1][v]=p;
}
void dijkstra(int s,int t){
    node now;
    priority_queue<node>Q;
    for(int i=1;i<=n;i++){mark[i]=0;dis[i]=inf;};
    now.u=s;    now.d=0;    dis[s]=0;
    Q.push(now);
    for(int i=1,j;i<n;i++){
        do{
            if(Q.empty())return ;
            now=Q.top();Q.pop();
            j=now.u;
        }while(mark[j]);
        mark[j]=1;
        for(edge *p=vert[1][j];p;p=p->next){
            if(!mark[p->to]&&dis[p->to]>dis[j]+p->va){
                dis[p->to]=dis[j]+p->va;
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
}
int a_star(int s,int t){
    gnode  now,next;
    priority_queue<gnode>Q;
    now.u=s;    now.d=0;
    Q.push(now);
    int cnt=0;
    while(!Q.empty()){
        now=Q.top();Q.pop();
        //printf("pop: %d\n",now.u);
        int u=now.u;
        if(u==t)cnt++;
        if(cnt==k)return now.d;
        for(edge *p=vert[0][u];p;p=p->next){
            next.u=p->to;
            next.d=now.d+p->va;
            Q.push(next);
            //printf("push: %d %d\n",next.u,next.d);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        int top=-1,s,t;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++){
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            add_edge(u,v,va,top);
        }
        scanf("%d%d%d",&s,&t,&k);
        dijkstra(t,s);
        if(dis[t]==inf)puts("-1");
        else{
            printf("%d\n",a_star(s,t));
        }
    }
    return 0;
}
