#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[100010], *vert[5002];

int n, m, cnt[2][5002], deg[5002], visit[5002], in[5002];

inline void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x], vert[x] = p;
}

void DFS(int s) {
	if (visit[s])return;
	visit[s] = 1;
	if (deg[s] == 0)cnt[0][s] = 1;
	else cnt[0][s] = 0;
	for (edge *p = vert[s]; p; p = p->next) {
		DFS(p->to);
		cnt[0][s] += cnt[0][p->to];
	}
	return;
}

void BFS(int s) {
	queue <int> Q;
	Q.push(s);
	cnt[1][s] = 1;
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		for (edge *p = vert[i]; p; p = p->next) {
			cnt[1][p->to] += cnt[1][i];
			if (--in[p->to] == 0) {
				Q.push(p->to);
			}
		}
	}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		int top = -1;
		memset(in, 0, sizeof (in));
		memset(cnt, 0, sizeof (cnt));
		memset(deg, 0, sizeof (deg));
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(v, u, top);
			++deg[v], ++in[u];
		}
		memset(visit, 0, sizeof (visit));
		DFS(n), BFS(n);
		//		for (int j = 0; j < 2; j++) {
		//			for (int i = 1; i <= n; i++) {
		//				printf("%d ", cnt[j][i]);
		//			}
		//			puts("");
		//		}
		int mini = 0;
		for (int i = 1; i <= n; i++) {
			for (edge *p = vert[i]; p; p = p->next) {
				if (mini < cnt[1][i] * cnt[0][p->to]) {
					//printf("%d %d %d\n", mini, i, p->to);
					mini = cnt[1][i] * cnt[0][p->to];
				}
			}
		}
		printf("%d\n", mini);
	}
	return 0;
}
