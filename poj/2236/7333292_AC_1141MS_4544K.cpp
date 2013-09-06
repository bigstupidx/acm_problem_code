#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

struct node {
	int x, y;
} nod[1002];

int n, par[1002], d, mark[1002];
vector <int> front[1002];

int find(int x) {
	if (par[x] == 0) {
		return x;
	}
	return par[x] = find(par[x]);
}

inline double Distance(int ii, int jj) {
	double ax = nod[ii].x - nod[jj].x;
	double by = nod[ii].y - nod[jj].y;
	return sqrt(ax * ax + by * by);
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &nod[i].x, &nod[i].y);
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (Distance(i, j) <= d) {
				//printf("%d -> %d\n", i, j);
				front[i].push_back(j);
				front[j].push_back(i);
			}
		}
	}
	char str[5];
	while (scanf("%s", str) != EOF) {
		if (str[0] == 'O') {
			int v;
			scanf("%d", &v);
			mark[v] = 1;
			int ii = find(v), jj;
			for (int j = 0; j < front[v].size(); j++) {
				if (mark[front[v][j]]) {
					jj = find(front[v][j]);
					if (ii != jj) {
						par[jj] = ii;
					}
				}
			}
		} else {
			int u, v, ii, jj;
			scanf("%d%d", &u, &v);
			ii = find(u);
			jj = find(v);
			if (ii == jj)puts("SUCCESS");
			else puts("FAIL");
		}
	}
	return 0;
}
