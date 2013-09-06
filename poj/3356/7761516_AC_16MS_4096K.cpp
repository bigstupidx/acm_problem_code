#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[2][1002];
int n, m, f[1002][1002];

int main() {
	while (scanf("%d%s", &n, str[0] + 1) != EOF) {
		scanf("%d%s", &m, str[1] + 1);
		memset(f, 0, sizeof (f));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				if (str[0][i] == str[1][j]) {
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
				}
			}
		}
		printf("%d\n", (n > m ? n : m) - f[n][m]);
	}
	return 0;
}

