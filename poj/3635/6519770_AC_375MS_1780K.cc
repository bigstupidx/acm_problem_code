#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[20010],*vert[1002];
const int inf = 1000000000;
int n,m,prc[1002],cap,dis[1002][102];
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
    for(int i=0;i<n;i++)
	for(int j=0;j<=cap;j++)
		dis[i][j]=inf;
    now.u=s;    now.cost=0;     now.cap=0;
    Q.push(now);
    while(!Q.empty()){
	now=Q.top();Q.pop();
	int u=now.u;
	if(u==t)return now.cost;
	if(now.cost>=dis[u][now.cap])continue;
	dis[u][now.cap]=now.cost;
	for(edge *p=vert[u];p;p=p->next){
		if(now.cap>=p->d){
			next.u=p->to;
			next.cap=now.cap-p->d;
			next.cost=now.cost;
			Q.push(next);
		}
	}
	if(now.cap<cap){
		now.cap++;
		now.cost+=prc[now.u];
		Q.push(now);
	}
    }
    return -1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        int top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<n;i++)
		scanf("%d",prc+i);
        for(int i=0;i<m;i++){
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            add_edge(u,v,va,top);
	    add_edge(v,u,va,top);
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
