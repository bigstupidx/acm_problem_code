#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, c[120][120], f[120][120], pre[120], top, e[10010][2];
const int inf = 1000000000;

int max_flow(int s, int t) {
	int flow = 0;
	while (1) {
		queue<int> Q;
		memset(pre, -1, sizeof(pre));
		Q.push(s);
		while (!Q.empty() && pre[t] == -1) {
			int i = Q.front();
			Q.pop();
			for (int j = 0; j <= t; j++) {
				if (pre[j] == -1 && c[i][j] > f[i][j]) {
					pre[j] = i;
					Q.push(j);
				}
			}
		}
		if (pre[t] == -1)
			return flow;
		int mini = inf;
		for (int i = t; i != s; i = pre[i]) {
			if (mini > c[pre[i]][i] - f[pre[i]][i]) {
				mini = c[pre[i]][i] - f[pre[i]][i];
			}
		}
		flow += mini;
		for (int i = t; i != s; i = pre[i]) {
			f[pre[i]][i] += mini;
			f[i][pre[i]] -= mini;
		}
	}
}

bool DFS(int s) {
	if (s == n + 1)
		return true;
	pre[top++] = s;
	for (int i = 0; i <= n + 1; ++i) {
		if (f[s][i] > 0) {
			--f[s][i];
			if (DFS(i)) {
				return true;
			}
			++f[s][i];
		}
	}
	return false;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		int ss = n + 2, tt = n + 3;
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		top = 0;
		for (int m, i = 1; i <= n; ++i) {
			scanf("%d", &m);
			for (int v, j = 0; j < m; ++j) {
				scanf("%d", &v);
				e[top][0] = i;
				e[top][1] = v;
				++top;
				++c[i][tt];
				++c[ss][v];
				c[i][v] = inf;
			}
			c[0][i] = inf;
			c[i][n + 1] = inf;
		}
		max_flow(ss, tt);
		c[n + 1][0] = inf;
		max_flow(ss, tt);
		printf("%d\n", f[n + 1][0]);

		for (int i = 0; i < top; ++i) {
			++f[e[i][0]][e[i][1]];
		}

		top = 0;
		while (DFS(0)) {
			if (top > 1)
				printf("%d", pre[1]);
			for (int i = 2; i < top; ++i) {
				printf(" %d", pre[i]);
			}
			puts("");
			top = 0;
		}
	}
	return 0;
}

