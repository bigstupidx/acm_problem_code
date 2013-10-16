#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[90010], *vert[300];

const int inf = 10000000;
int n, rank[300], map[300], visit[300];
int fic[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256};

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];	vert[x] = p;
}

void spfa(int s) {
	queue <int> Q;
	for (int i = 1; i <= n; i++) {
		rank[i] = inf, visit[i] = 0;
	}
	Q.push(s);
	rank[s] = n;
	visit[s] = 1;
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		visit[s] = 0;
		for (edge *p = vert[i]; p; p = p->next) {
			if (rank[p->to] > rank[i] - 1) {
				rank[p->to] = rank[i] - 1;
				if (!visit[p->to]) {
					visit[p->to] = 1;
					Q.push(p->to);
				}
			}
		}
	}
}

void DFS(int s) {
	visit[s] = 1;
	for (edge *p = vert[s]; p; p = p->next) {
		if (!visit[p->to]) {
			DFS(p->to);
		}
	}
}

int main() {
	int flag = 0;
	while (scanf("%d", &n), n) {
		if (flag)puts("");
		else flag = 1;
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < fic[n]; i++) {
			map[i] = i + 1;
		}
		for (int i = n; i > 0; i--) {
			int m = fic[i - 1], x;
			for (int j = 0; j < m; j++) {
				scanf("%d", &x);
				int u = map[j * 2];
				int v = map[j * 2 + 1];
				if (u != x) {
					add_edge(x, u, top);
				} else {
					add_edge(x, v, top);
				}
				map[j] = x;
			}
		}
		n = fic[n];
		spfa(map[0]);
		for (int i = 1; i <= n; i++) {
			rank[i] = n + 1 - rank[i];
		}
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int u;
			scanf("%d", &u);
			memset(visit, 0, sizeof (visit));
			DFS(u);
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (visit[i])cnt++;
			}
			cnt = n + 1 - cnt;
			printf("Player %d can be ranked as high as %d or as low as %d.\n", u, rank[u], cnt);
		}
	}
	return 0;
}

