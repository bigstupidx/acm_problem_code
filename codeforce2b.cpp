#include <cstdio>
#include <cstring>

int n, g[1001][1001], dp[3][1001][1001], pre[2][1001][1001], queue[2002];

void solve(int k, int dev) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] == 0) {
				dp[k][i][j] = -1;
				continue;
			}
			int count = 0, temp = g[i][j];
			while (temp != 0 && temp % dev == 0) {
				temp /= dev;
				++count;
			}
			if (i == 0 && j == 0) {
				dp[k][0][0] = count;

			} else if (i == 0) {
				if (dp[k][0][j - 1] >= 0) {
					dp[k][0][j] = count + dp[k][0][j - 1];
					pre[k][0][j] = j - 1;

				} else {
					dp[k][0][j] = -1;
				}

			} else if (j == 0) {
				if (dp[k][i - 1][0] >= 0) {
					dp[k][i][0] = count + dp[k][i - 1][0];
					pre[k][i][0] = (i - 1) * n;

				} else {
					dp[k][i][0] = -1;
				}

			} else {
				if (dp[k][i - 1][j] == -1 && dp[k][i][j - 1] == -1) {
					dp[k][i][j] = -1;

				} else if (dp[k][i - 1][j] == -1) {
					dp[k][i][j] = dp[k][i][j - 1] + count;
					pre[k][i][j] = i * n + j - 1;

				} else if (dp[k][i][j - 1] == -1) {
					dp[k][i][j] = dp[k][i - 1][j] + count;
					pre[k][i][j] = (i - 1) * n + j;

				} else {
					if (dp[k][i - 1][j] < dp[k][i][j - 1]) {
						dp[k][i][j] = count + dp[k][i - 1][j];
						pre[k][i][j] = (i - 1) * n + j;

					} else {
						dp[k][i][j] = count + dp[k][i][j - 1];
						pre[k][i][j] = i * n + j - 1;
					}
				}
			}
		}
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		memset(dp, 0, sizeof(dp));
		memset(pre, -1, sizeof(pre));
		int ans = 1000000000, flag = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &g[i][j]);
				if (g[i][j] == 0) {
					ans = 1;
					flag = i * n + j;
				}
			}
		}
		solve(0, 2);
		solve(1, 5);
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				printf("[%d:%d]%2d  ", pre[0][i][j] / n, pre[0][i][j] % n, dp[0][i][j]);
//			}
//			puts("");
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				printf("[%d:%d]%2d  ", pre[1][i][j] / n, pre[1][i][j] % n, dp[1][i][j]);
//
//			}
//			puts("");
//		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dp[0][i][j] == -1 || dp[1][i][j] == -1) {
					dp[2][i][j] = -1;

				} else {
					if (dp[0][i][j] < dp[1][i][j]) {
						dp[2][i][j] = dp[0][i][j];

					} else {
						dp[2][i][j] = dp[1][i][j];
					}
				}
			}
		}
		ans = ans < dp[2][n - 1][n - 1] ? ans : dp[2][n - 1][n - 1];
		printf("%d\n", ans);
		if (ans == 1 && flag != -1) {
			for (int i = 0, ii = flag / n; i < ii; i++) {
				putchar('D');
			}
			for (int j = 0; j < n - 1; j++) {
				putchar('R');
			}
			for (int i = flag / n + 1; i < n; i++) {
				putchar('D');
			}
		} else {
			int top = 0, ii = n - 1, jj = n - 1;
			int k = dp[1][ii][jj] < dp[0][ii][jj] ? 1 : 0;
			while (pre[k][ii][jj] != -1) {
//				printf("%d %d %d\n", ii, jj, pre[k][ii][jj]);
				queue[top++] = ii * n + jj;
				int new_i = pre[k][ii][jj] / n;
				int new_j = pre[k][ii][jj] % n;
				ii = new_i;
				jj = new_j;
			}
			ii = 0, jj = 0;
			for (int i = top - 1; i >= 0; i--) {
				int xi = queue[i] / n;
				int xj = queue[i] % n;
				if (xj == jj) {
					putchar('D');
				} else {
					putchar('R');
				}

				ii = xi;
				jj = xj;
			}
		}
		puts("");
	}
	return 0;
}
