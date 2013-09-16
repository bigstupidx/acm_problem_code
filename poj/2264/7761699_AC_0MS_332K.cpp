#include <cstdio>
#include <cstring>

using namespace std;

int n, m, f[120][120], pre[120][120][2], pos[120];
char str[2][120];

void solve() {
	memset(pre, -1, sizeof (pre));
	memset(f, 0, sizeof (f));
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (str[0][i] == str[1][j]) {
				f[i][j] = f[i - 1][j - 1] + 1;
				pre[i][j][0] = i - 1;
				pre[i][j][1] = j - 1;
			}
			if (f[i][j] < f[i - 1][j]) {
				f[i][j] = f[i - 1][j];
				pre[i][j][0] = i - 1;
				pre[i][j][1] = j;
			}
			if (f[i][j] < f[i][j - 1]) {
				f[i][j] = f[i][j - 1];
				pre[i][j][0] = i;
				pre[i][j][1] = j - 1;
			}
		}
	}
	int i = n - 1, j = m - 1;
	memset(pos, 0, sizeof (pos));
	while (pre[i][j][0] != -1) {
		int ii = pre[i][j][0];
		int jj = pre[i][j][1];
		if (f[i][j] != f[ii][jj]) {
			pos[i] = j;
		}
		i = ii, j = jj;
	}
	i = 1, j = 1;
	for (; i < n; i++) {
		if (pos[i]) {
			for (; j < pos[i]; ++j) {
				putchar(str[1][j]);
			}
			j = pos[i] + 1;
		}
		putchar(str[0][i]);
	}
	while (j < m) {
		putchar(str[1][j]);
		++j;
	}
	puts("");
}

int main() {
	str[0][0] = ' ', str[1][0] = ' ';
	while (scanf("%s%s", str[0] + 1, str[1] + 1) != EOF) {
		n = strlen(str[0]);
		m = strlen(str[1]);
		solve();
	}
	return 0;
}
