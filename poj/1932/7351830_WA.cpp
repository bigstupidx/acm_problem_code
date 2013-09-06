#include <cstdio>
#include <cstring>

struct edge {
	int to;
	edge *next;
} edg[10010], *vert[102];

int n, va[102], visit[102], dis[102];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];
	vert[x] = p;
}

void DFS(int s) {
	visit[s] = 1;
	for (edge *p = vert[s]; p; p = p->next) {
		if (!visit[p->to]) {
			DFS(p->to);
		}
	}
}

bool dfs(int s) {
	if (s == n)return true;
	visit[s] = 1;
	for (edge *p = vert[s]; p; p = p->next) {
		if (!visit[p->to]) {
			dis[p->to] = dis[s] + va[p->to];
			if (dis[p->to] < 1)continue;
			if (dfs(p->to))return true;
		} else if (dis[p->to] != 100000) {
			if (dis[s] + va[p->to] > dis[p->to]) {
				dis[p->to] = 100000;
				if (dfs(p->to))return true;
			}
		}
	}
	return false;
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n), n != -1) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 1; i <= n; i++) {
			int m, v;
			scanf("%d%d", &va[i], &m);
			for (int j = 0; j < m; j++) {
				scanf("%d", &v);
				add_edge(i, v, top);
			}
		}
		memset(visit, 0, sizeof (visit));
		DFS(1);
		if (!visit[n])puts("hopeless");
		else {
			memset(visit, 0, sizeof (visit));
			dis[1] = 100;
			if (dfs(1))puts("winnable");
			else puts("hopeless");
		}
	}
	return 0;
}

