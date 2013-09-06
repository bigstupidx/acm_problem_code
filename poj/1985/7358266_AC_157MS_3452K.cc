#include <cstdio>
#include <cstring>

struct edge {
	int to;
	int d;
	edge *next;
} edg[100010], *vert[40010];

int n, m, ans[40010], maxi;

void add_edge(int x, int y, int va, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x];	vert[x] = p;
}

inline int my_max(int x, int y) {
	if (x > y)return x;
	return y;
}

void DFS(int k, int k_father) {
	ans[k] = 0;
	for (edge *p = vert[k]; p; p = p->next) {
		if (p->to != k_father) {
			DFS(p->to, k);
			maxi = my_max(maxi, ans[k] + p->d + ans[p->to]);
			ans[k] = my_max(ans[k], ans[p->to] + p->d);
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		char str[3];
		for (int i = 0; i < m; i++) {
			int u, v, d;
			scanf("%d%d%d%s", &u, &v, &d, str);
			add_edge(u, v, d, top);
			add_edge(v, u, d, top);
		}
		maxi = 0;
		memset(ans, 0, sizeof (ans));
		DFS(1, -1);
		printf("%d\n", maxi);
	}
	return 0;
}
