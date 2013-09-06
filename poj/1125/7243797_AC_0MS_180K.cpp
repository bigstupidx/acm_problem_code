#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge{
	int to;
	int d;
	edge *next;
}edg[20010], *vert[102];

const int inf = 1000000000;
int n, deg[102], dis[102], mark[102];

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

void dijkstra(int s){
	priority_queue<QN>Q;
	for(int i=0;i<n;i++){
		dis[i]=inf;
		mark[i]=0;
	}
	now.u=s;
	now.d=0;
	Q.push(now);
	dis[s]=0;
	for(int k, i=1;i<n;i++){
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

int main(){
	while(scanf("%d", &n), n){
		int top=-1;
		memset(deg, 0, sizeof(deg));
		memset(vert, 0, sizeof(vert));
		for(int i=0;i<n;i++){
			int m, x, d;
			scanf("%d", &m);
			for(int j=0;j<m;j++){
				scanf("%d%d", &x, &d);
				x--;
				add_edge(i, x, d, top);
			}
		}
		int xflag=0, ans=inf, k, tem;
		for(int i=0;i<n;i++){
			dijkstra(i);
			tem=-1;
			for(int j=0;j<n;j++){
				if(dis[j]>tem){
					tem=dis[j];
				}
			}
			if(tem==inf){
				continue;
			}
			if(tem<ans){
				ans=tem;
				k=i;
			}
		}
		if(ans==inf){
			puts("disjoint");
		}
		else {
			printf("%d %d\n", k+1, ans);
		}
	}
	return 0;
}
