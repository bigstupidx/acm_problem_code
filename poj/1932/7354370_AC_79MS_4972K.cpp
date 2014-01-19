#include <cstdio>
#include <stack>
#include <cstdlib>
#include <cstring>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[10010], *vert[102];

const int inf = 1000000000;
int n, va[102], visit[102], dis[102];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];	vert[x] = p;
}

bool DFS(int s) {
	if (s == n)return true;
	visit[s] = 1;
	for (edge *p = vert[s]; p; p = p->next) {
		if (!visit[p->to]) {
			int tem = dis[s] + va[p->to];
			if (tem > 0) {
				dis[p->to] = tem;
				if (DFS(p->to))return true;
			}
		} else {
			if (dis[p->to] < 10010 && dis[p->to] < dis[s] + va[p->to]) {
				dis[p->to] = dis[s] + va[p->to];
				if (DFS(p->to))return true;
			}
		}
	}
	return false;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
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
		dis[1] = 100;
		if (DFS(1))puts("winnable");
		else puts("hopeless");
	}
	return 0;
}

