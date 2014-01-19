#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge{
	int to;
	int d;
	edge *next;
}edg[10010], *vert[502];

const int inf = 1000000000;
int n, m, w, dis[502], cnt[502], flag[502];

void add_edge(int x, int y, int va, int &top){
	edge *p=&edg[++top];
	p->to=y;
	p->d=va;
	p->next=vert[x];	vert[x]=p;
}

bool spfa(){
	queue<int>Q;
	for(int i=1;i<=n;i++){
		dis[i]=0;
		cnt[i]=0;
		flag[i]=1;
		Q.push(i);
	}
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(edge *p=vert[u];p;p=p->next){
			if(dis[p->to]>dis[u]+p->d){
				dis[p->to]=dis[u]+p->d;
				if(!flag[p->to]){
					if(++cnt[p->to]>n)return true;
					flag[p->to]=1;
					Q.push(p->to);
				}
			}
		}
		flag[u]=0;
	}
	return false;
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		int u, v, d, top=-1;
		scanf("%d%d%d", &n, &m, &w);
		memset(vert, 0, sizeof(vert));
		for(int i=0;i<m;i++){
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, d, top);
			add_edge(v, u, d, top);
		}
		for(int i=0;i<w;i++){
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, -d, top);
		}
		if(spfa()){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}
