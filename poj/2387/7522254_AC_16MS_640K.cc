#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	int d;
	edge *next;
} edg[4002], *vert[1002];

const int inf = 1000000000;
int n, m, dis[1002], mark[1002], flag[1002];

struct QN {
	int ii;

	bool operator<(const QN & a)const {
		return dis[a.ii] < dis[ii];
	}
} now;

void add_edge(int x, int y, int va, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x], vert[x] = p;
}

void dijkstra(int s, int t) {
	priority_queue <QN> Q;
	for (int i = 1; i <= n; i++) {
		dis[i] = inf;
		mark[i] = 0;
		flag[i] = 0;
	}
	now.ii = s;
	Q.push(now);
	dis[s] = 0;
	flag[s] = 1;
	while (1) {
		int k;
		do {
			if (Q.empty())return;
			now = Q.top();
			Q.pop();
			k = now.ii;
		} while (mark[k]);

		if (k == t)return;
		mark[k] = 1;
		flag[k] = 0;
		
		for (edge *p = vert[k]; p; p = p->next) {
			if (!mark[p->to] && dis[p->to] > dis[k] + p->d) {
				dis[p->to] = dis[k] + p->d;
				if (!flag[p->to]) {
					flag[p->to] = 1;
					now.ii = p->to;
					Q.push(now);
				}
			}
		}
	}
}

int main() {
	while (scanf("%d%d", &m, &n) != EOF) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < m; i++) {
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, d, top);
			add_edge(v, u, d, top);
		}
		dijkstra(n, 1);
		printf("%d\n", dis[1]);
	}
	return 0;
}
