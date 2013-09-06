#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	int d;
	edge *next;
} edg[1000010], *vert[1002];

int n, m, mark[1002], dis[1002];

struct QN {
	int u;
	int d;

	bool operator<(const QN & a)const {
		return a.d > d;
	}
} now;

void add_edge(int x, int y, int va, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x], vert[x] = p;
}

int dijkstra(int s) {
	priority_queue<QN>Q;
	now.u = s;
	now.d = 100000000;
	Q.push(now);
	memset(dis, 0, sizeof (dis));
	memset(mark, 0, sizeof (mark));
	dis[s] = 1000000000;
	while (!Q.empty()) {
		now = Q.top();
		Q.pop();
		int k = now.u;
		int d = now.d;
		if (mark[k])continue;
		mark[k] = 1;
		for (edge *p = vert[k]; p; p = p->next) {
			if (!mark[p->to]) {
				now.d = d;
				if (now.d > p->d) {
					now.d = p->d;
				}
				if (now.d > dis[p->to]) {
					dis[p->to] = now.d;
					now.u = p->to;
					Q.push(now);
				}
			}
		}
	}
	return dis[n];
}

int main() {
	int nca;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			add_edge(u, v, va, top);
			add_edge(v, u, va, top);
		}
		printf("Scenario #%d:\n%d\n", ii, dijkstra(1));
	}
	return 0;
}