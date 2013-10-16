#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

const int inf = 1000000000;
int n, m, k, dis[32][32];

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	puts("SHIPPING ROUTES OUTPUT\n");
	for (int ii = 1; ii <= nca; ii++) {
		scanf("%d%d%d", &n, &m, &k);
		map <string, int> mp;
		map <string, int> ::iterator p;
		char str[2][5];
		for (int i = 0; i < n; i++) {
			scanf("%s", str[0]);
			mp[str[0]] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = inf;
			}
			dis[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			scanf("%s%s", str[0], str[1]);
			int u = mp.find(str[0])->second;
			int v = mp.find(str[1])->second;
			dis[u][v] = dis[v][u] = 1;
		}
		for (int w = 0; w < n; w++) {
			for (int u = 0; u < n; u++) {
				if (dis[u][w] != inf) {
					for (int v = 0; v < n; v++) {
						if (dis[u][v] > dis[u][w] + dis[w][v]) {
							dis[u][v] = dis[u][w] + dis[w][v];
						}
					}
				}
			}
		}
		printf("DATA SET %d\n\n", ii);
		for (int i = 0; i < k; i++) {
			int size, u, v;
			scanf("%d%s%s", &size, str[0], str[1]);
			u = mp.find(str[0])->second;
			v = mp.find(str[1])->second;
			if (dis[u][v] == inf)puts("NO SHIPMENT POSSIBLE");
			else printf("$%d\n", size * 100 * dis[u][v]);
		}
		puts("");
	}
	puts("END OF OUTPUT");
	return 0;
}