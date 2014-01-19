#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

struct edge {
	int to;
	int d;
	edge *next;
} edg[1000010], *vert[102];

const int inf = 1000000000;
int n, m, dis[102], que[2][102], mark[102], ans[102][102];
char str[10];

void add_edge(int y, int x, int va, int &top) {
	//printf("%d -> %d %d\n", x, y, va);
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x], vert[x] = p;
}

bool bellman_ford(int s) {
	int last = 0, cnt = 0;
	memset(mark, 0, sizeof (mark));
	if (s == -1) {
		for (int i = 0; i < n; i++) {
			dis[i] = 0;
			que[0][i + 1] = i;
		}
		que[0][0] = n;
	}
	else {
		for (int i = 0; i < n; i++) {
			dis[i] = inf;
		}
		dis[s] = 0;
		que[0][1] = s;
		que[0][0] = 1;
	}
	bool change = true;
	while (change) {
		if (++cnt > n)return false;
		int top = 0;
		change = false;
		for (int i = 1; i <= que[last][0]; i++) {
			int u = que[last][i];
			for (edge *p = vert[u]; p; p = p->next) {
				if (dis[p->to] > dis[u] + p->d) {
					change = true;
					dis[p->to] = dis[u] + p->d;
					if (mark[p->to] != cnt) {
						mark[p->to] = cnt;
						que[1 - last][++top] = p->to;
					}
				}
			}
		}
		last = 1 - last;
		que[last][0] = top;
	}
	return true;
}

int main() {
	int nca;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		n = 0;
		int top = -1;
		memset(vert, 0, sizeof (vert));
		map <pair<int, int>, int> mp;
		map <pair<int, int>, int> ::iterator p;
		while (scanf("%s", str), strcmp(str, "#") != 0) {
			int len = strlen(str), u = 0, v, d, r;
			for (int i = 0; i < len; i++) {
				u *= 10;
				u += str[i] - '0';
			}
			scanf("%d%d%d", &v, &d, &r);
			if (u > n)n = u;
			if (v > n)n = v;
			if (r == 0) {
				add_edge(v, u, d - 1, top);
			}
			else {
				add_edge(v, u, d, top);
				mp.insert(make_pair(make_pair(u, v), 1));
			}
		}
		printf("Case %d:\n", ii);
		++n;
		if (bellman_ford(-1)) {
			for (int i = 0; i < n; i++) {
				bellman_ford(i);
				int xflag = 0;
				for (int j = 0; j < n; j++) {
					if (xflag)putchar(' ');
					else xflag = 1;
					if (dis[j] == inf)printf("($,<)");
					else printf("(%d,<=)", dis[j]);
				}
				puts("");
			}
		}
		else {
			puts("Canonical DBM does not exist.");
		}
		puts("");
	}
	return 0;
}
