#include <cstdio>
#include <algorithm>

using namespace std;

struct edge {
	int x, y, d;
	bool operator<(const edge & a)const {
		return d < a.d;
	}
} edg[3000];

int n, m, par[52];

int find(int x) {
	if (par[x] == -1) {
		return x;
	}
	return par[x] = find(par[x]);
}

int kruskral() {
	int ans = 0, cnt = 1;
	sort(edg, edg + m);
	memset(par, -1, sizeof (par));
	for (int i = 0; i < m; i++) {
		int ii = find(edg[i].x);
		int jj = find(edg[i].y);
		if (ii != jj) {
			par[ii] = jj;
			ans += edg[i].d;
			if (++cnt == n)break;
		}
	}
	return ans;
}

int main() {
	while (scanf("%d", &n), n) {
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &edg[i].x, &edg[i].y, &edg[i].d);
		}
		printf("%d\n", kruskral());
	}
	return 0;
}
