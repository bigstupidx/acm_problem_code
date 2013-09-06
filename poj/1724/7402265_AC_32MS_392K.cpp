#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	int d;
	int mon;
	edge *next;
} edg[10010], *vert[102];

int n, m, k, dis[102];

struct Qnode {
	int u;
	int tim, mon;

	bool operator<(const Qnode & a)const {
		if (a.tim == tim)return a.mon < mon;
		return a.tim < tim;
	}
} now, next;

void add_edge(int x, int y, int va, int d, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->mon = d;
	p->next = vert[x];
	vert[x] = p;
}

int BFS() {
	priority_queue <Qnode> Q;
	for (int i = 1; i <= n; i++)dis[i] = 2147483647;
	now.u = 1;
	now.tim = 0;
	now.mon = 0;
	Q.push(now);
	while (!Q.empty()) {
		now = Q.top();
		Q.pop();
		if (now.u == n)return now.tim;
		int u = now.u;
		if (dis[u] <= now.mon)continue;
		dis[u] = now.mon;
		for (edge *p = vert[u]; p; p = p->next) {
			next.mon = now.mon + p->mon;
			if (next.mon > k)continue;
			next.u = p->to;
			next.tim = now.tim + p->d;
			Q.push(next);
		}
	}
	return -1;
}

int main() {
	while (scanf("%d%d%d", &k, &n, &m) != EOF) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < m; i++) {
			int s, t, d, l;
			scanf("%d%d%d%d", &s, &t, &d, &l);
			add_edge(s, t, d, l, top);
		}
		printf("%d\n", BFS());
	}
	return 0;
}
