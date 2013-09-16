#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 100010
#define inf 2147483647

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[100 * maxn], *vert[maxn];

int n, dis[maxn];
bool mark[maxn];

struct Qnode {
	int u;
	int d;

	bool operator<(const Qnode & a)const {
		return a.d < d;
	}
} now;

inline void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x], vert[x] = p;
}

void dijkstra(int s, int t) {
	priority_queue <Qnode> Q;
	for (int i = 0; i < n; i++) {
		dis[i] = inf;
		mark[i] = 0;
	}
	now.u = s;
	now.d = 0;
	Q.push(now);
	dis[s] = 0;
	for (int k, i = 1; i < n; i++) {
		do {
			if (Q.empty())return;
			now = Q.top();
			Q.pop();
			k = now.u;
		} while (mark[k]);
		mark[k] = 1;
		if (k == t)return;
		for (edge *p = vert[k]; p; p = p->next) {
			if (!mark[p->to] && dis[p->to] > dis[k] + 1) {
				dis[p->to] = dis[k] + 1;
				now.u = p->to;
				now.d = dis[p->to];
				Q.push(now);
			}
		}
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < n; i++) {
			int m, u, v;
			scanf("%d%d", &u, &m);
			for (int j = 0; j < m; j++) {
				scanf("%d", &v);
				add_edge(u, v, top);
			}
		}
		int s, t;
		scanf("%d%d", &s, &t);
		dijkstra(s, t);
		printf("%d %d %d\n", s, t, dis[t] - 1);
	}
	return 0;
}
