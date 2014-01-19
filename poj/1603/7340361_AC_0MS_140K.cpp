#include <cstdio>
#include <cstring>

int dis[22][22], n, m;

int main() {
	//freopen("in.txt", "r", stdin);
	int nca = 1;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i < 21; i++) {
			for (int j = 1; j < 21; j++) {
				dis[i][j] = 1000;
			}
			dis[i][i] = 0;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &m);
			dis[1][m] = dis[m][1] = 1;
		}
		for (int i = 2; i < 20; i++) {
			scanf("%d", &n);
			for (int j = 0; j < n; j++) {
				scanf("%d", &m);
				dis[i][m] = dis[m][i] = 1;
			}
		}
		for (int k = 1; k < 21; k++) {
			for (int i = 1; i < 21; i++) {
				if (dis[i][k] != 1000) {
					for (int j = 1; j < 21; j++) {
						if (dis[i][j] > dis[i][k] + dis[k][j]) {
							dis[i][j] = dis[i][k] + dis[k][j];
						}
					}
				}
			}
		}
		scanf("%d", &m);
		printf("Test Set #%d\n", nca++);
		for (int i = 0; i < m; i++) {
			int s, t;
			scanf("%d%d", &s, &t);
			printf("%d to %d: %d\n", s, t, dis[s][t]);
		}
		puts("");
	}
	return 0;
}
