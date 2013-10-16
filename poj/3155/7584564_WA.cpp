#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

struct edge {
	int to, next;
	double c, f;
} e[100010];

const double inf = 1000000000;
int n, m, deg[120], head[120], p[120][2], L[120];

void add_edge(int x, int y, double va, int &top) {
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
					if (L[e[j].to] > L[p[top][0]] && e[j].c > e[j].f) {
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

double solve(double mid, int tot, int top) {
	for (int i = 0; i < top; i++) {
		e[i].f = 0;
	}
	for (int i = tot; i < top; i += 2) {
		e[i].c = m + 2 * mid - deg[e[i].to];
		//printf("%d -> %d %d\n", s, e[i].to, e[i].c);
	}
	return n * m - max_flow(0, n + 1);
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d%d", &n, &m) != EOF) {
		int top = -1, s = 0, t = n + 1;
		memset(deg, 0, sizeof (deg));
		memset(head, -1, sizeof (head));
		for (int x, y, i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			add_edge(x, y, 1, top);
			add_edge(y, x, 1, top);
			++deg[x], ++deg[y];
		}
		for (int i = 1; i <= n; i++) {
			add_edge(i, t, m, top);
		}
		int tot = top + 1;
		for (int i = 1; i <= n; i++) {
			add_edge(s, i, m, top);
		}
		++top;

		double lf = 0, rt = m, mid;
		while (lf < rt) {
			mid = (lf + rt) / 2;

			double tem = solve(mid, tot, top);
			//printf("try %lf %lf\n", mid, tem);
			if (tem > 1e-14)
				lf = mid + 1e-14;
			else
				rt = mid - 1e-14;
		}
		//puts("");
		solve(lf, tot, top);
		vector <int> ans;
		for (int j = head[0]; j != -1; j = e[j].next) {
			if (fabs(e[j].c - e[j].f) < 1e-12) {
				ans.push_back(e[j].to);
			}
		}
		sort(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
