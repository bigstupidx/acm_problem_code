#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge{
	int to;
	int d;
	edge *next;
}edg[10010], *vert[505];

const int inf = 100000000;
int n, m, mm, dis[505], cnt[505], flag[505];

void add_edge(int x, int y, int va, int &top){
	edge *p=&edg[++top];
	p->to=y;
	p->d=va;
	p->next=vert[x];	vert[x]=p;
}

bool spfa(){
	queue<int>Q;
	for(int i=1;i<=n;i++){
		flag[i]=1;
		cnt[i]=0;
		dis[i]=0;
		Q.push(i);
	}
	while(!Q.empty()){
		int i=Q.front();Q.pop();
		flag[i]=0;
		for(edge *p=vert[i];p;p=p->next){
			if(dis[p->to]>dis[i]+p->d){
				dis[p->to]=dis[i]+p->d;
				if(!flag[p->to]){
					if(++cnt[p->to]>n)return true;
					flag[p->to]=1;
					Q.push(p->to);
				}
			}
		}
	}
	return false;
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		int top=-1;
		memset(vert, 0, sizeof(vert));
		
		scanf("%d%d%d", &n, &m, &mm);
		for(int i=0;i<m;i++){
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			add_edge(u, v, va, top);
			add_edge(v, u, va, top);
		}
		for(int i=0;i<mm;i++){
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			add_edge(u, v, -va, top);
		}
		if(spfa()){
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
	return 0;
}

