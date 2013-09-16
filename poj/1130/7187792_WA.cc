#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 1010
using namespace std;

struct edge {
	int to;
	edge *next;
} edg[2000010], *vert[10010];

int n, t, visit[maxn], que[maxn], order[maxn];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];
	vert[x] = p;
}

void DFS(int s){
	visit[s]=1;
	for(edge *p=vert[s];p;p=p->next){
		if(!visit[p->to]){
			DFS(p->to);
		}
	}
}

int main() {
	int top = -1, u, v;
	scanf("%d%d", &n, &t);
	while (scanf("%d%d", &u, &v) != EOF) {
		add_edge(v, u, top);
	}
	que[0] = t;
	top = 0;
	int ff = 0, rt = 1;
	while (ff < rt) {
		int i = que[ff++];
		visit[i] = 1;
		order[top++] = i;
		for (edge *p = vert[i]; p; p = p->next) {
			if (!visit[p->to]) {
				que[rt++] = p->to;
			}
		}
	}
	int ans;
	for (int i = 1; i < top; i++) {
		memset(visit, 0, sizeof (visit));
		visit[order[i]] = 1;
		DFS(t);
		if (!visit[0]) {
			ans = order[i];
//			printf("try %d\n", order[i]);
			break;
		}
	}
	printf("Put guards in room %d.\n", ans);
	return 0;
}
