#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#define maxn 120

using namespace std;

struct edge {
	int to, next;
	double c, f;
} e[100010];

const double inf = 1e100;
double c[maxn][maxn];
int n, m, deg[maxn], head[maxn], p[maxn][2], L[maxn];
bool choose[maxn];

inline void add_edge(int x, int y, double va, int &top) {
	e[++top].to = y;
	e[top].c = va;
	e[top].next = head[x], head[x] = top;

	e[++top].to = x;
	e[top].c = 0;
	e[top].next = head[y], head[y] = top;
}

double max_flow(int s, int t) {
	double flow = 0;
	while (1) {
		queue <int> Q;
		memset(L, -1, sizeof (L));
		L[s] = 0;
		Q.push(s);
		while (!Q.empty()) {
			int i = Q.front();
			Q.pop();
			for (int j = head[i]; j != -1; j = e[j].next) {
				if (L[e[j].to] == -1 && e[j].c > e[j].f) {
					L[e[j].to] = L[i] + 1;
					Q.push(e[j].to);
				}
			}
		}
		if (L[t] == -1) {
			//printf("%lf\n", flow);
			return flow;
		}
		int top = 0;
		p[0][0] = s;
		p[0][1] = head[s];
		while (top >= 0) {
			if (p[top][0] != t) {
				while (p[top][1] >= 0) {
					int j = p[top][1];
					if (L[e[j].to] == L[p[top][0]] + 1 && e[j].c > e[j].f) {
						p[top + 1][0] = e[j].to;
						p[top + 1][1] = head[e[j].to];
						top++;
						break;
					}
					p[top][1] = e[j].next;
				}
				if (p[top][1] < 0) {
					if (--top < 0)break;
					p[top][1] = e[p[top][1]].next;
				}
			}
			else {
				int k;
				double mini = inf;
				for (int i = 0; i < top; i++) {
					if (mini > e[p[i][1]].c - e[p[i][1]].f) {
						mini = e[p[i][1]].c - e[p[i][1]].f;
						k = i;
					}
				}
				flow += mini;
				for (int i = 0; i < top; i++) {
					e[p[i][1]].f += mini;
					e[p[i][1]^1].f -= mini;
				}
				top = k;
				p[top][1] = e[p[top][1]].next;
			}
		}
	}
}

double solve(double hg, int tot, int top) {
	for (int i = 0; i < top; i++) {
		e[i].f = 0;
	}
	for (int i = tot; i < top; i += 2) {
		e[i].c = m + 2 * hg - deg[e[i^1].to];
		//		printf("%d -> %d %lf\n", e[i^1].to, n+1, e[i].c);
	}
	double temp = max_flow(0, n + 1);
	if (fabs(temp - n * m) < 1e-8)return hg;
	int up = 0, down = 0;
	memset(choose, 0, sizeof (choose));
	for (int i = 1; i <= n; i++) {
		if (L[i] != -1) {
			++down;
			choose[i] = true;
			for (int j = i + 1; j <= n; j++) {
				if (L[i] != -1 && c[i][j] > 0) {
					++up;
				}
			}
		}
	}
	return up * 1.0 / down;
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {

		memset(c, 0, sizeof (c));
		memset(deg, 0, sizeof (deg));

		for (int x, y, i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			if (c[x][y] == 0) {
				++deg[x], ++deg[y];
			}
			c[x][y] = c[y][x] = 1;
		}
		int top = -1;
		memset(head, -1, sizeof (head));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (c[i][j] == 1) {
					add_edge(i, j, 1, top);
				}
			}
		}
		int s = 0, t = n + 1;
		for (int i = 1; i <= n; i++) {
			add_edge(s, i, m, top);
		}
		int tot = top + 1;
		for (int i = 1; i <= n; i++) {
			add_edge(i, t, m, top);
		}
		++top;
		double hg = 0, temp = -1;
		while (fabs(hg - temp) > 1e-6) {
			temp = hg;
			//printf("%lf\n", temp);
			hg = solve(hg, tot, top);
		}
		//printf("%lf\n", hg);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (choose[i])++cnt;
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i++) {
			if (choose[i]) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
