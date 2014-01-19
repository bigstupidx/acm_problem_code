#include <cstdio>
#include <cstring>

struct edge {
	int to;
	edge *next;
} edg[40010], *vert[202];

int n, m, my[202], flag[202];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];	vert[x] = p;
}

bool path(int s) {
	for (edge *p = vert[s]; p; p = p->next) {
		if (!flag[p->to]) {
			flag[p->to] = 1;
			if (my[p->to] == -1 || path(my[p->to])) {
				my[p->to] = s;
				return true;
			}
		}
	}
	return false;
}

int max_match() {
	int ans = 0;
	memset(my, -1, sizeof (my));
	for (int i = 0; i < n; i++) {
		memset(flag, 0, sizeof (flag));
		if (path(i))ans++;
	}
	return ans;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < n; i++) {
			int mm, x;
			scanf("%d", &mm);
			for (int j = 0; j < mm; j++) {
				scanf("%d", &x);
				add_edge(i, x, top);
			}
		}
		printf("%d\n", max_match());
	}
	return 0;
}
