#include <cstdio>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#define maxn 1200

using namespace std;

struct edge {
	int to, next;
	double c, f;
} e[100010];

const double inf = 1000000, eps = 1e-18;
int n, m, head[maxn], p[maxn][2], L[maxn];

void add_edge(int x, int y, double va, int &top) {
	//printf("%d -> %d %lf\n", x, y, va);
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
				if (L[e[j].to] == -1 && e[j].c - e[j].f > 1e-18) {
					L[e[j].to] = L[i] + 1;
					Q.push(e[j].to);
				}
			}
		}
		if (L[t] == -1)return flow;
		int top = 0;
		p[0][0] = s;
		p[0][1] = head[s];
		while (top >= 0) {
			if (p[top][0] != t) {
				while (p[top][1] >= 0) {
					int j = p[top][1];
					if (L[e[j].to] > L[p[top][0]] && e[j].c - e[j].f > 1e-18) {
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
				double mini = inf;
				int k;
				for (int j, i = 0; i < top; i++) {
					j = p[i][1];
					if (mini > e[j].c - e[j].f) {
						mini = e[j].c - e[j].f;
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

double solve(double mid, int tot, int top) {
	for (int i = 0; i < top; i++) {
		e[i].f = 0;
	}
	for (int i = tot; i < top; i += 2) {
		e[i].c = mid;
	}
	return max_flow(0, n + m + 1);
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		int top = -1, s = 0, t = n + m + 1;
		memset(head, -1, sizeof (head));
		for (int x, y, i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			add_edge(s, i, 1, top);
			add_edge(i, m + x, inf, top);
			add_edge(i, m + y, inf, top);
		}
		int tot = top + 1;
		for (int i = 1; i <= n; i++) {
			add_edge(m + i, t, 1, top);
		}
		++top;

		double lf = 0, rt = m, mid, tem, tp;
		while (lf < rt) {
			mid = (lf + rt) / 2;

			tem = solve(mid, tot, top);
			//printf("try : %lf %lf\n", mid, tem);
			if (tem >= m) {
				tp = mid;
				rt = mid - 1e-10;
			}
			else
				lf = mid + 1e-10;
		}
		//printf("%lf\n", mid);
		solve(mid, tot, top);

		vector <int> ans;
		for (int j = head[t]; j != -1; j = e[j].next) {
			if (e[j].to > m && fabs(e[j^1].c - e[j^1].f) < 1e-8) {
				ans.push_back(e[j].to);
			}
		}
		sort(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d\n", ans[i] - m);
		}
	}
	return 0;
}
