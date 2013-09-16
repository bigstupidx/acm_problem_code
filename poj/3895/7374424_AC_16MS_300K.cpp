#include <cstdio>
#include <cstring>

struct edge {
	int to;
	edge *next;
} edg[20000100], *vert[4500];

int n, m, par[4500], color[4500], anc[4500], dep[4500];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];
	vert[x] = p;
}

int my_find(int x) {
	if (par[x] == -1)return x;
	return par[x] = my_find(par[x]);
}

void DFS(int k, int k_father, int depth) {
	color[k] = 1;
	anc[k] = dep[k] = depth;
	for (edge *p = vert[k]; p; p = p->next) {
		int i = p->to;
		if (i != k_father && color[i] == 1)
			anc[k] = anc[k] > dep[i] ? dep[i] : anc[k];
		if (color[i] == 0) {
			DFS(i, k, depth + 1);
			anc[k] = anc[k] > anc[i] ? anc[i] : anc[k];
			if (anc[i] < dep[k]) {
				int ii = my_find(i), kk = my_find(k);
				par[ii] = kk;
			}
		}
	}
	color[k] = 2;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		scanf("%d%d", &n, &m);
		for (int x, y, i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			add_edge(x, y, top);
			add_edge(y, x, top);
		}
		memset(dep, 0, sizeof (dep));
		memset(anc, 0, sizeof (anc));
		memset(par, -1, sizeof (par));
		memset(color, 0, sizeof (color));
		for (int i = 1; i <= n; i++) {
			if (!color[i])DFS(i, -1, 1);
		}
		int ans = 0;
		memset(anc, 0, sizeof (anc));
		for (int i = 1; i <= n; i++) {
			int ii = my_find(i);
			int tem = ++anc[ii];
			if (tem > ans)ans = tem;
		}
		if (ans == 1)ans = -1;
		printf("%d\n", ans + 1);
	}
	return 0;
}