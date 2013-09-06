#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, val[2][10010];
bool f[10010][102];

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int d, i = 1; i <= n; i++) {
			scanf("%d", &d);
			val[0][i] = (m + (-d) % m) % m;
			val[1][i] = (m + d % m) % m;
		}
		memset(f, 0, sizeof (f));
		f[0][0] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (f[i - 1][j]) {
					f[i][(val[0][i] + j + m) % m] = true;
					f[i][(val[1][i] + j + m) % m] = true;
				}
			}
		}
		if (f[n][0] || f[n][0]) {
			puts("Divisible");
		}
		else {
			puts("Not divisible");
		}
	}
	return 0;
}
