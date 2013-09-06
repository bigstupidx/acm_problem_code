#include <cstdio>
#include <cstring>

struct edge {
	int to;
	int d;
	edge *next;
} edg[200010], *vert[50010];

const int inf = 100000000;
int n, dis[50010], mark[50010], que[2][50010];

void add_edge(int x, int y, int va, int &top) {
	//printf("%d -> %d %d\n", x,y, va);
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x];	vert[x] = p;
}

int bellman_ford(int s, int t) {
	int now = 0, cnt = 1;
	que[0][0] = 1;
	for (int i = s; i <= t; i++) {
		dis[i] = 0;
		mark[i] = 1;
		que[0][que[0][0]++] = i;
	}
	bool change = true;
	while (change) {
		if (++cnt > t - s)return -1;
		change = false;
		int top = 1;
		for (int i = 1; i < que[now][0]; i++) {
			int u = que[now][i];
			for (edge *p = vert[u]; p; p = p->next) {
				if (dis[p->to] < dis[u] + p->d) {
					dis[p->to] = dis[u] + p->d;
					change = true;
					if (mark[p->to] != cnt) {
						mark[p->to] = cnt;
						que[1 - now][top++] = p->to;
					}
				}
			}
		}
		now = 1 - now;
		que[now][0] = top;
	}
	return dis[t];
}

int main() {
	while (scanf("%d", &n) != EOF) {
		int top = -1, mini = inf, maxi = -inf;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < n; i++) {
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			if (mini > x)mini = x;
			if (maxi < y + 1)maxi = y + 1;
			add_edge(x, y + 1, d, top);
		}
		for (int i = mini; i < maxi; i++) {
			add_edge(i, i + 1, 0, top);
			add_edge(i + 1, i, -1, top);
		}
		printf("%d\n", bellman_ford(mini, maxi));
	}
	return 0;
}