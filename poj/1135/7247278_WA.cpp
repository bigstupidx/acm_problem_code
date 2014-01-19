#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct edge{
	int to;
	int d;
	edge *next;
}edg[1000010], *vert[502];

const int inf = 1000000000;
int n, m, dis[502], mark[502];

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
	priority_queue <QN> Q;
	for(int i=1;i<=n;i++){
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
	int nca = 1;
	while(scanf("%d%d", &n, &m), n||m){
		int top=-1;
		memset(vert, 0, sizeof(vert));
		for(int i=0;i<m;i++){
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			add_edge(u, v, va, top);
			add_edge(v, u, va, top);
		}
		dijkstra(1);
		int lf=-1, rt=-1;
		double ans=0;
		for(int i=1;i<=n;i++){
			if(ans < dis[i]){
				ans=dis[i];
				lf=i;
			}
		}
		for(int i=1;i<=n;i++){
			for(edge *p=vert[i];p;p=p->next){
				if(dis[p->to]==dis[i]+p->d)continue;
				if(dis[i]==dis[p->to]+p->d)continue;
				double tem, maxi;
				if(dis[p->to]>dis[i]){
					tem=dis[p->to]-dis[i];
					maxi=dis[p->to];
				}
				else {
					tem=dis[i]-dis[p->to];
					maxi=dis[i];
				}
				tem=(p->d-tem)/2;
				if(tem+maxi>ans){
					ans=tem+maxi;
					lf=i;
					rt=p->to;
				}
			}
		}
		printf("System #%d\n", nca++);
		if(rt==-1){
			printf("The last domino falls after %.1lf seconds, at key domino %d.", ans, lf);
		}
		else {
			if(lf>rt){
				int tem=lf;
				lf=rt;
				rt=tem;
			}
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.", ans, lf, rt);
		}
		puts("\n");
	}
	return 0;
}
