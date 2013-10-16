#include <cstdio>
#include <cstring>

using namespace std;

int flag[2][102], n, va[3][102];

void solve() {
	for (int i = 0; i < n; i++) {
		memset(flag, 0, sizeof (flag));
		for (int j = 0; j < n; j++) {
			if (j == i)continue;
			if (va[0][j] >= va[0][i])flag[0][j] = 1;
		}
		for (int j = 0; j < n; j++) {
			if (!flag[0][j] || j == i)continue;
			if (va[1][j] >= va[1][i])flag[1][j] = 1;
		}
		int xflag = 0;
		for (int j = 0; j < n; j++) {
			if (!flag[1][j] || j == i)continue;
			if (va[2][j] >= va[2][i]) {
				xflag = 1;
				break;
			}
		}
		if (xflag)puts("No");
		else puts("Yes");
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &va[j][i]);
			}
		}
		solve();
	}
	return 0;
}