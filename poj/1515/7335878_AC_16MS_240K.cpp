#include <cstdio>
#include <cstring>

struct edge {
	int s, t, flag;
	edge *next;
} edg[1000010], *vert[1002];

int n, m, color[1002], dep[1002], anc[1002];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->t = y;
	p->s = x;
	p->flag = 0;
	p->next = vert[x];
	vert[x] = p;

	p = &edg[++top];
	p->t = x;
	p->s = y;
	p->flag = 0;
	p->next = vert[y];
	vert[y] = p;
}

void DFS(int k, int k_father, int depth) {
	anc[k] = depth;
	dep[k] = depth;
	color[k] = 1;
	int tot = 0;
	for (edge *p = vert[k]; p; p = p->next) {
		int j = p->t;
		if (color[j] == 1 && j != k_father) {
			p->flag = 1;
			anc[k] = anc[k] < dep[j] ? anc[k] : dep[j];
		} else if (color[j] == 0) {
			tot++;
			DFS(j, k, depth + 1);
			anc[k] = anc[k] < anc[j] ? anc[k] : anc[j];
			if (anc[j] <= dep[k]) p->flag = 1;
		}
	}
	color[k] = 2;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int nca = 1;
	while (scanf("%d%d", &n, &m), n || m) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v, top);
		}
		memset(dep, 0, sizeof (dep));
		memset(anc, 0, sizeof (anc));
		memset(color, 0, sizeof (color));
		DFS(1, -1, 1);
		printf("%d\n\n", nca++);
		for (int i = 0; i <= top; i += 2) {
			if (edg[i].flag) {
				printf("%d %d\n", edg[i].s, edg[i].t);
			} else if (edg[i + 1].flag) {
				printf("%d %d\n", edg[i].t, edg[i].s);
			} else {
				printf("%d %d\n", edg[i].s, edg[i].t);
				printf("%d %d\n", edg[i].t, edg[i].s);
			}
		}
		puts("#");
	}
	return 0;
}
