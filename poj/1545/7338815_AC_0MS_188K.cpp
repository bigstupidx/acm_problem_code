#include <cstdio>
#include <cmath>
#include <cstring>

char str[30], name[3];
double dis[30][30], val[30], inf = 10000000;

int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		double tem;
		for (int i = 0; i < 27; i++) {
			for (int j = 0; j < 27; j++) {
				dis[i][j] = inf;
			}
			dis[i][i] = 0;
		}
		memset(val, 0, sizeof (val));
		for (int i = 0; i < n; i++) {
			scanf("%s%lf%s", name, &tem, str);
			int u = name[0] - 'A';
			val[u] = tem;
			int len = strlen(str);
			for (int j = 0; j < len; j++) {
				if (str[j] == '*') {
					dis[u][26] = dis[26][u] = log10(0.95);
				} else {
					dis[u][str[j] - 'A'] = log10(0.95);
					dis[str[j] - 'A'][u] = log10(0.95);
				}
			}
		}
		for (int w = 0; w < 27; w++) {
			for (int u = 0; u < 27; u++) {
				if (dis[u][w] != inf) {
					for (int v = 0; v < 27; v++) {
						if (dis[w][v] != inf && dis[u][v] > dis[u][w] + dis[w][v]) {
							dis[u][v] = dis[u][w] + dis[w][v];
						}
					}
				}
			}
		}
		double ans = 0;
		int k = 0;
		for (int i = 0; i < 26; i++) {
			tem = pow(10, dis[i][27]);
			if (dis[i][27] != inf && val[i] * tem > ans) {
				ans = val[i] * tem;
				k = i;
			}
		}
		printf("Import from %c\n", k + 'A');
	}
	return 0;
}