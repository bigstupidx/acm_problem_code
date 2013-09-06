#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge{
	int to;
	int d;
	edge *next;
}edg[20010], *vert[602];

const int inf = 1000000000;
int n, m, dis[2][602], mark[602], flag[602], e[10002][3];

struct QN{
	int u;
	int d;
	bool operator <(const QN &a)const{
		return a.d < d;
	}
}now;

void add_edge(int x, int y, int va, int &top){
	edge *p=&edg[++top];
	p->to=y;
	p->d=va;
	p->next=vert[x];	vert[x]=p;
}

void dijkstra(int s, int ii){
	priority_queue<QN>Q;
	for(int i=1;i<=n;i++){
		dis[ii][i]=inf;
		mark[i]=0;
	}
	now.u=s;
	now.d=0;
	Q.push(now);
	dis[ii][s]=0;
	for(int k, i=1;i<n;i++){
		do{
			if(Q.empty())return ;
			now=Q.top();Q.pop();
			k=now.u;
		}while(mark[k]);
		mark[k]=1;
		for(edge *p=vert[k];p;p=p->next){
			int to=p->to;
			if(!mark[to]&&flag[to]==s&&dis[ii][to]>dis[ii][k]+p->d){
				dis[ii][to]=dis[ii][k]+p->d;
				now.u=to;
				now.d=dis[ii][to];
				Q.push(now);
			}
		}
	}
}

int main(){
	while(scanf("%d", &n), n){
		int top=-1;
		memset(vert, 0, sizeof(vert));
		scanf("%d", &m);
		for(int i=0;i<m;i++){
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			add_edge(u, v, va, top);
			add_edge(v, u, va, top);
		}
		for(int i=1;i<=n;i++){
			scanf("%d", &flag[i]);
		}
		dijkstra(1, 1);
		dijkstra(2, 0);
		int mini=inf;
		for(int i=1;i<=n;i++){
			int ii=flag[i], tem;
			for(edge *p=vert[i];p;p=p->next){
				if(ii!=flag[p->to]){
					tem=dis[ii%2][i]+dis[(ii+1)%2][p->to]+p->d;
					if(tem<mini){
						mini=tem;
					}
				}
			}
		}
		if(mini==inf)mini=-1;
		printf("%d\n", mini);
	}
	return 0;
}
