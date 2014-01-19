#include <cstdio>
#include <cstring>

int dis[22][22];
const int inf = 1000000000;

int main() {
	int n, nca = 1;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= 20; i++) {
			for (int j = 1; j <= 20; j++) {
				dis[i][j] = inf;
			}
			dis[i][i] = 0;
		}
		for (int j, i = 0; i < n; i++) {
			scanf("%d", &j);
			dis[1][j] = dis[j][1] = 1;
		}
		for (int i = 2; i <= 19; i++) {
			scanf("%d", &n);
			for (int k, j = 0; j < n; j++) {
				scanf("%d", &k);
				dis[i][k] = dis[k][i] = 1;
			}
		}

		for (int k = 1; k <= 20; k++) {
			for (int i = 1; i <= 20; i++) {
				for (int j = 1; j <= 20; j++) {
					if (dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
		scanf("%d", &n);
		printf("Test Set #%d\n", nca++);
		for (int i = 0; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%d to %d: %d\n", u, v, dis[u][v]);
		}
		puts("");
	}
	return 0;
}
