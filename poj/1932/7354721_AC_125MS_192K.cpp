#include <cstdio>
#include <stack>
#include <cstdlib>
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

bool bellman_ford(int s, int inf) {
	stack<int>Q;
	for (int i = 1; i <= n; i++) {
		dis[i] = 0;
		flag[i] = 0;
	}
	dis[1] = 100;
	flag[1] = 1;
	Q.push(s);
	while (!Q.empty()) {
		int i = Q.top();
		Q.pop();
		if (i == n)return true;
		for (edge *p = vert[i]; p; p = p->next) {
			if (dis[p->to] < inf && dis[p->to] < dis[i] + va[p->to]) {
				dis[p->to] = dis[i] + va[p->to];
				if (!flag[p->to]) {
					flag[p->to] = 1;
					Q.push(p->to);
				}
			}
		}
		flag[i] = 0;
	}
	return false;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n), n != -1) {
		int top = -1, sum = 0;
		memset(vert, 0, sizeof (vert));
		for (int i = 1; i <= n; i++) {
			int m, v;
			scanf("%d%d", &va[i], &m);
			if (va[i] < 0)sum += va[i];
			for (int j = 0; j < m; j++) {
				scanf("%d", &v);
				add_edge(i, v, top);
			}
		}
		sum -= 100;
		if (bellman_ford(1, -sum))puts("winnable");
		else puts("hopeless");
	}
	return 0;
}

