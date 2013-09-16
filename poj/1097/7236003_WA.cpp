#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char str[20], name[32][20];
int n, m, k, pre[32][32], flag[32];
double g[32][32], inf = 1000000000;

struct node {
	int ii;
	int d;
	bool operator<(const node & a)const {
		return a.d > d;
	}
} nod[32];

/*
void get_ans(int i, int j){
	if(pre[i][j]==-1)return ;
	int k=pre[i][j];
	get_ans(i, k);
	printf("%d ", k);
	get_ans(k, j);
	return ;
}
 */

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = inf;
		}
		g[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		scanf("%lf", &g[x][y]);
		g[y][x] = g[x][y];
	}
	memset(pre, -1, sizeof (pre));
	for (int w = 0; w < n; w++) {
		for (int u = 0; u < n; u++) {
			if (g[u][w] != inf) {
				for (int v = 0; v < n; v++) {
					if (g[w][v] != inf && g[u][v] > g[u][w] + g[w][v]) {
						g[u][v] = g[u][w] + g[w][v];
						pre[u][v] = w;
					}
				}
			}
		}
	}
	memset(flag, 0, sizeof (flag));
	for (int ii, i = 0; i < k; i++) {
		scanf("%d%s", &ii, str);
		flag[ii] = 1;
		strcpy(name[ii], str);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		double va;
		int x, y, top = 0;
		scanf("%d%d%lf", &x, &y, &va);
		for (int k = 0; k < n; k++) {
			if (flag[k] && fabs(g[x][k] - g[x][y] - g[y][k]) < 1e-3) {
				nod[top].ii = k;
				nod[top].d = (int) (g[x][k] - va + 0.5);
				top++;
			}
		}
		sort(nod, nod + top);
		for (int j = 0; j < top; j++) {
			int k = nod[j].ii;
			printf("%s", name[k]);
			int len = 20 - strlen(name[k]);
			while (len--)putchar(' ');
			printf("%d\n", nod[j].d);
		}
		if(i != m - 1) {
			puts("");
		}
	}
	system("pause");
	return 0;
}
