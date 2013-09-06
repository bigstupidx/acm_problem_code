#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge{
	int to;
	int d;
	edge *next;
}edg[2000010], *vert[2][1000010];

__int64 inf=1, dis[2][1000010];
int n, m, mark[1000010];

struct QN{
	int u;
	__int64 d;
	bool operator <(const QN &a)const{
		return a.d < d;
	}
}now;

void add_edge(int x, int y, int va, int &top){
	edge *p=&edg[++top];
	p->to=y;
	p->d=va;
	p->next=vert[0][x];		vert[0][x]=p;
	
	p=&edg[++top];
	p->to=x;
	p->d=va;
	p->next=vert[1][y];		vert[1][y]=p;
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
		for(edge *p=vert[ii][k];p;p=p->next){
			if(!mark[p->to]&&dis[ii][p->to]>dis[ii][k]+p->d){
				dis[ii][p->to]=dis[ii][k]+p->d;
				now.u=p->to;
				now.d=dis[ii][p->to];
				Q.push(now);
			}
		}
	}
}

int main(){
	int nca;
	scanf("%d", &nca);
	inf<<=60;
//	printf("%I64d\n", inf);
	while(nca--){
		int top=-1;
		memset(vert, 0, sizeof(vert));
		scanf("%d%d", &n, &m);
		for(int i=0;i<m;i++){
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			add_edge(u, v, va, top);
		}
		dijkstra(1, 0);
		dijkstra(1, 1);
		__int64 ans=0;
		for(int i=1;i<=n;i++){
			ans+=dis[0][i]+dis[1][i];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
