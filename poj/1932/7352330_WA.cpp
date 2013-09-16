#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[10010], *vert[102];

int n, va[102], flag[102], dis[102];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];
	vert[x] = p;
}

bool bellman_ford() {
	queue<int>Q;
	for (int i = 1; i <= n; i++) {
		dis[i] = -10000000;
		flag[i] = 0;
	}
	Q.push(1);
	flag[1] = 1;
	dis[1] = 100;
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		if (i == n)return true;
		for (edge *p = vert[i]; p; p = p->next) {
			if (dis[p->to] == -10000000) {
				int tem = dis[i] + va[p->to];
				if (tem > 0) {
					dis[p->to] = tem;
					if (!flag[p->to]) {
						flag[p->to] = 1;
						Q.push(p->to);
					}
				}
			} else {
				if (dis[p->to] < 10001 && dis[p->to] < dis[i] + va[p->to]) {
					dis[p->to] = 10000000;
					if (!flag[p->to]) {
						flag[p->to] = 1;
						Q.push(p->to);
					}
				}
			}
		}
		flag[i] = 0;
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
		if (bellman_ford())puts("winnable");
		else puts("hopeless");
	}
	return 0;
}

