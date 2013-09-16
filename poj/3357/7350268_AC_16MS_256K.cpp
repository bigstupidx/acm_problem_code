#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge {
	int x, y, d;

	bool operator<(const edge & a)const {
		if (a.d == d) {
			if (a.x == x) {
				return a.y > y;
			}
			return a.x > x;
		}
		return a.d > d;
	}
} e[1000010];

int n, m, map[1002][1002], par[1002];

int find(int x) {
	if (par[x] == x)return x;
	return par[x] = find(par[x]);
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d%*c", &map[i][j]);
			}
		}
		m = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (map[i][j] != 0) {
					e[m].x = i;
					e[m].y = j;
					e[m].d = map[i][j];
					m++;
				}
			}
		}
		sort(e, e + m);
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
		printf("Case %d:\n", ii);
		int cnt = 1;
		for (int i = 0; i < m; i++) {
			int j = find(e[i].x);
			int k = find(e[i].y);
			if (j != k) {
				par[j] = k;
				printf("%c-%c %d\n", e[i].x + 'A', e[i].y + 'A', e[i].d);
				if (++cnt == n)break;
			}
		}
	}
	return 0;
}




