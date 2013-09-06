#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	int d;
	edge *next;
} edg[200010], *vert[50010];

const int inf = 100000000;
int n, dis[50010], flag[50010];

void add_edge(int x, int y, int va, int &top) {
	//printf("%d -> %d %d\n", x,y, va);
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x];	vert[x] = p;
}

int spfa(int s, int t) {
	queue<int>Q;
	for (int i = s; i <= t; i++) {
		dis[i] = -inf;
		flag[i] = 0;
	}
	Q.push(s);
	dis[s] = 0;
	flag[s] = 1;
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		for (edge *p = vert[i]; p; p = p->next) {
			if (dis[p->to] < dis[i] + p->d) {
				dis[p->to] = dis[i] + p->d;
				if (!flag[p->to]) {
					flag[p->to] = 1;
					Q.push(p->to);
				}
			}
		}
		flag[i] = 0;
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
		printf("%d\n", spfa(mini, maxi));
	}
	return 0;
}