#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
int mp[18][131073], fac[18];

void pre_done() {
	fac[0] = 1;
	for (int i = 1; i < 18; i++) {
		fac[i] = fac[i - 1] * 2;
	}
}

void pre_solve() {
	for (int i = 1; i < n; i++) {
		int length = fac[i];
		int xlength = fac[i - 1];
		bool flag = i % 2 == 1;
		for (int j = 0; j < fac[n]; j += length) {
			if (flag) {
				mp[i][j] = mp[i - 1][j] | mp[i - 1][j + xlength];
			} else {
				mp[i][j] = mp[i - 1][j] xor mp[i - 1][j + xlength];
			}
		}
	}
}

int solve(int left, int right, int pos, int dep) {
	if (left == right || pos > right || pos < left)
		return mp[dep][left];
	int mid = (left + right) / 2;
	int ll = solve(left, mid, pos, dep - 1);
	int rr = solve(mid + 1, right, pos, dep - 1);
	mp[dep - 1][left] = ll;
	mp[dep - 1][mid + 1] = rr;
//	printf("%d %d %d %d %d  %d\n", dep, left, right, ll, rr, dep % 2 == 1 ? (ll | rr) : (ll xor rr));
	return mp[dep][left] = (dep % 2 == 1) ? (ll | rr) : (ll xor rr);
}

int main() {
	pre_done();
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < fac[n]; i++) {
			scanf("%d", &mp[0][i]);
		}
		pre_solve();
		for (int i = 0, x, y, tmp; i < m; i++) {
			scanf("%d%d", &x, &y);
//			tmp = mp[0][x - 1];
			mp[0][x - 1] = y;
			printf("%d\n", solve(0, fac[n] - 1, x - 1, n));
//			mp[0][x - 1] = tmp;
		}
	}
	return 0;
}
