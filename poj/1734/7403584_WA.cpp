#include <cstdio>
#include <cstring>
#define maxn 102

const int inf = 1000000000;
int n, m, gg[maxn][maxn], dis[maxn][maxn], pre[maxn][maxn];
int top, path[maxn];

void get_ans(int ii, int jj) {
	if (pre[ii][jj] == -1)return;
	int kk = pre[ii][jj];
	if (ii != kk)get_ans(ii, kk);
	path[top++] = kk;
	if (jj != kk)get_ans(kk, jj);
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = inf;
				pre[i][j] = -1;
			}
			dis[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			u--, v--;
			if (dis[u][v] > va) {
				dis[u][v] = va;
				dis[v][u] = va;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				gg[i][j] = dis[i][j];
			}
		}
		int ans = inf;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < k; i++) {
				for (int j = i + 1; j < k; j++) {
					if (ans > gg[i][k] + gg[k][j] + dis[i][j]) {
						path[0] = i;
						top = 1;
						get_ans(i, j);
						path[top++] = j;
						path[top++] = k;
						ans = gg[i][k] + gg[k][j] + dis[i][j];
					}
				}
			}
			for (int i = 0; i < n; i++) {
				if (dis[i][k] != inf) {
					for (int j = 0; j < n; j++) {
						if (dis[i][j] > dis[i][k] + dis[k][j]) {
							pre[i][j] = k;
							dis[i][j] = dis[i][k] + dis[k][j];
						}
					}
				}
			}
		}
		if (ans == inf)puts("No solution.");
		else {
			//printf("%d\n", ans);
			for (int i = 0; i < top; i++) {
				printf("%d ", path[i] + 1);
			}
			puts("");
		}
	}
	return 0;
}
