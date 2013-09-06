#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to, c, f, next;
} e[100010];


int n, m, up[202][22], dw[202][22], in[22], cc[250][250], f[250][250], pre[250];
const int inf = 1000000000;

int max_flow(int s, int t) {
	int flow = 0;
	memset(f, 0, sizeof (f));
	while (1) {
		queue <int> Q;
		memset(pre, -1, sizeof (pre));
		Q.push(s);
		while (!Q.empty() && pre[t] == -1) {
			int i = Q.front();
			Q.pop();
			for (int j = 0; j <= t; j++) {
				if (pre[j] == -1 && cc[i][j] > f[i][j]) {
					pre[j] = i;
					Q.push(j);
				}
			}
		}
		if (pre[t] == -1) {
			//printf("%d\n", flow);
			return flow;
		}
		int mini = inf;
		for (int i = t; i != s; i = pre[i]) {
			if (mini > cc[pre[i]][i] - f[pre[i]][i]) {
				mini = cc[pre[i]][i] - f[pre[i]][i];
			}
		}
		flow += mini;
		for (int i = t; i != s; i = pre[i]) {
			f[pre[i]][i] += mini;
			f[i][pre[i]] -= mini;
		}
	}
}

bool adjust(int r, int c, char ch, int d) {
	if (ch == '<') {
		if (dw[r][c] >= d) {
			return false;
		}
		if (up[r][c] > d - 1) {
			up[r][c] = d - 1;
		}
	}
	else if (ch == '=') {
		if (up[r][c] < d || dw[r][c] > d) {
			return false;
		}
		up[r][c] = dw[r][c] = d;
	}
	else {
		if (up[r][c] <= d) {
			return false;
		}
		if (dw[r][c] < d + 1) {
			dw[r][c] = d + 1;
		}
	}
	return true;
}

char str[4];

int main() {
	int nca, xflag = 0;
	scanf("%d", &nca);
	while (nca--) {

		if (xflag)puts("");
		else xflag = 1;

		scanf("%d%d", &n, &m);
		int s = 0, t = n + m + 1, ss = t + 1, tt = ss + 1;

		memset(dw, 0, sizeof (dw));
		memset(cc, 0, sizeof (cc));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				up[i][j] = inf;
			}
		}
		int xsum = 0, ysum = 0;
		for (int d, i = 1; i <= n; i++) {
			scanf("%d", &d);
			xsum += d;
			cc[ss][i] += d;
		}
		cc[s][tt] += xsum;
		for (int d, i = 1; i <= m; i++) {
			scanf("%d", &d);
			ysum += d;
			cc[i + n][tt] += d;
		}
		cc[ss][t] += ysum;

		bool flag = false;
		int sum = xsum + ysum, mm;
		if (xsum != ysum)flag = true;

		scanf("%d", &mm);
		for (int r, c, d, i = 0; i < mm; i++) {
			scanf("%d%d%s%d", &r, &c, str, &d);
			if (flag)continue;
			if (r == 0 && c != 0) {
				for (int j = 1; j <= n; j++) {
					if (!adjust(j, c, str[0], d)) {
						flag = true;
					}
				}
			}
			else if (c == 0 && r != 0) {
				for (int j = 1; j <= m; j++) {
					if (!adjust(r, j, str[0], d)) {
						flag = true;
					}
				}
			}
			else if (c == 0 && r == 0) {
				for (int j = 1; j <= n; j++) {
					for (int k = 1; k <= m; k++) {
						if (!adjust(j, k, str[0], d)) {
							flag = true;
						}
					}
				}
			}
			else {
				if (!adjust(r, c, str[0], d)) {
					flag = true;
				}
			}
		}
		//		for (int i = 1; i <= n; i++) {
		//			for (int j = 1; j <= m; j++) {
		//				printf("%.2d , %.2d  ", dw[i][j], up[i][j]);
		//			}
		//			puts("");
		//		}
		if (flag) {
			puts("IMPOSSIBLE");
		}
		else {
			memset(in, 0, sizeof (in));
			for (int i = 1; i <= n; i++) {
				ysum = 0;
				for (int j = 1; j <= m; j++) {
					ysum += dw[i][j];
					in[j] += dw[i][j];
					if (up[i][j] < dw[i][j]) {
						flag = true;
					}
					if (up[i][j] > dw[i][j]) {
						cc[i][j + n] += up[i][j] - dw[i][j];
					}
				}
				sum += ysum;
				cc[i][tt] += ysum;
			}
			for (int i = 1; i <= m; i++) {
				cc[ss][i + n] += in[i];
			}
			cc[t][s] = inf;
			//			for (int i = 0; i <= tt; i++) {
			//				for (int j = 0; j <= tt; j++) {
			//					if (cc[i][j]) {
			//						printf("%d -> %d %d\n", i, j, cc[i][j]);
			//					}
			//				}
			//			}
			if (flag || max_flow(ss, tt) != sum) {
				puts("IMPOSSIBLE");
				continue;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					printf("%d ", dw[i][j] + f[i][j + n]);
				}
				puts("");
			}
		}
	}
	return 0;
}
