#include <cstdio>
#include <cstdlib>
#include <cstring>

//#define DEBUG

const int maxN = 100;
const int MAXINT = 2147483647;

int N, M, T;
int g[maxN + 1][maxN + 1];
int dist[maxN + 1];
bool mark[maxN + 1];

void prim(void) {
	int i, j, u, mind, cost = 0;

	for (i = 1; i <= N; i++) {
		dist[i] = MAXINT;
		mark[i] = false;
	}
	dist[1] = 0;

	for (i = 1; i <= N; i++) {
		mind = MAXINT;
		for (j = 1; j <= N; j++)
			if (!mark[j] && dist[j] < mind) {
				u = j;
				mind = dist[j];
			}
		if (mind == MAXINT) {
			break;
		}
		for (j = 1; j <= N; j++)
			if (!mark[j] && j != u && dist[j] == mind) {
				printf("Not Unique!\n");
				return;
			}
		mark[u] = true;
		cost += dist[u];
		for (j = 1; j <= N; j++)
			if (!mark[j] && g[u][j] < dist[j])
				dist[j] = g[u][j];
	}
	printf("%d\n", cost);
}

int main() {
	int i, j, u, v, w;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d%d", &N, &M);
		for (u = 1; u <= N; u++) {
			for (v = 1; v <= N; v++) {
				g[u][v] = MAXINT;
			}
			g[u][u] = 0;
		}
		for (j = 0; j < M; j++) {
			scanf("%d%d%d", &u, &v, &w);
			g[u][v] = g[v][u] = w;
		}
		prim();
	}
	return 0;
}