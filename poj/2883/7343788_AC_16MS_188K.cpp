#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	int d;
	edge *next;
} edg[40010], *vert[2][502];

char op[4];
int n, m, dis[502], cnt[502], flag[502];

void add_edge(int x, int y, int va, int ii, int &top) {
	//printf("%d -> %d  %d %d\n", x, y, va, ii);
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[ii][x];
	vert[ii][x] = p;
}

bool spfa(int ii) {
	queue<int>Q;
	for (int i = 1; i <= n; i++) {
		dis[i] = 0;
		cnt[i] = 0;
		flag[i] = 1;
		Q.push(i);
	}
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		flag[i] = 0;
		for (edge *p = vert[ii][i]; p; p = p->next) {
			if (dis[p->to] < dis[i] + p->d) {
				dis[p->to] = dis[i] + p->d;
				if (!flag[p->to]) {
					if (++cnt[p->to] > n)return false;
					flag[p->to] = 1;
					Q.push(p->to);
				}
			}
		}
	}
	return true;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		int top = -1;
		scanf("%d%d", &n, &m);
		memset(vert, 0, sizeof (vert));
		for (int u, v, i = 0; i < m; i++) {
			scanf("%d%s%d", &u, op, &v);
			if (op[0] == 'N') {
				if (op[1] == 'E') {
					add_edge(u, v, 1, 0, top);
					add_edge(u, v, 1, 1, top);
				} else if (op[1] == 'W') {
					add_edge(u, v, 1, 1, top);
					add_edge(v, u, 1, 0, top);
				} else {
					add_edge(u, v, 0, 0, top);
					add_edge(v, u, 0, 0, top);
					add_edge(u, v, 1, 1, top);
				}
			} else if (op[0] == 'S') {
				if (op[1] == 'E') {
					add_edge(u, v, 1, 0, top);
					add_edge(v, u, 1, 1, top);
				} else if (op[1] == 'W') {
					add_edge(v, u, 1, 0, top);
					add_edge(v, u, 1, 1, top);
				} else {
					add_edge(u, v, 0, 0, top);
					add_edge(v, u, 0, 0, top);
					add_edge(v, u, 1, 1, top);
				}
			} else if (op[0] == 'E') {
				add_edge(u, v, 0, 1, top);
				add_edge(v, u, 0, 1, top);
				add_edge(u, v, 1, 0, top);
			} else if (op[0] == 'W') {
				add_edge(u, v, 0, 1, top);
				add_edge(v, u, 0, 1, top);
				add_edge(v, u, 1, 0, top);
			}
		}
		if (!spfa(0) || !spfa(1))puts("IMPOSSIBLE");
		else puts("POSSIBLE");
	}
	return 0;
}
