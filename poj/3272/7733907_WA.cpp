#include <cstdio>
#include <cstring>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[50010], *vert[5002];

int n, m, ans[5002], deg[5002], visit[5002];

inline void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x], vert[x] = p;
}

void DFS(int s) {
	if (visit[s])return;
	visit[s] = 1;
	if (deg[s] == 0)ans[s] = 1;
	else ans[s] = 0;
	for (edge *p = vert[s]; p; p = p->next) {
		DFS(p->to);
		ans[s] += ans[p->to];
	}
	return;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		int top = -1;
		memset(deg, 0, sizeof (deg));
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(v, u, top);
			++deg[v];
		}
		memset(visit, 0, sizeof (visit));
		DFS(n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
