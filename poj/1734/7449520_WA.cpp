#include <cstdio>
#include <cstring>

using namespace std;

const int inf = 1000000000;
int n, m, dis[120][120], gg[120][120], pre[120][120];
int top, order[102];

void get_ans(int i, int j) {
	int k = pre[i][j];
	if (k == -1) {
		order[top++] = j;
		return;
	}
	get_ans(i, k);
	get_ans(k, j);
	return;
}

int main() {
	//freopen("small.in", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = inf;
				pre[i][j] = -1;
			}
			dis[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			if (dis[x][y] > d) {
				dis[x][y] = d;
				dis[y][x] = d;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				gg[i][j] = dis[i][j];
			}
		}
		int ans = inf;
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i < k; i++) {
				for (int j = i + 1; j < k; j++) {
					if (ans > dis[i][j] + gg[i][k] + gg[k][j]) {
						top = 2;
						order[0] = k;
						order[1] = i;
						get_ans(i, j);
						ans = dis[i][j] + gg[i][k] + gg[k][j];
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
						pre[i][j] = k;
					}
				}
			}
		}
		if (ans == inf)puts("No solution.");
		else {
			//printf("%d\n", ans);
			printf("%d", order[0]);
			for (int i = 1; i < top; i++) {
				printf(" %d", order[i]);
			}
			puts("");
		}
	}
	return 0;
}
