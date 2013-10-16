#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, f[2][5002];
char str[5002];

int main() {
	while (scanf("%d", &n) != EOF) {
		scanf("%s", str + 1);
		memset(f, 0, sizeof (f));
		int now = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (str[i] == str[n - j + 1]) {
					f[now][j] = f[1 - now][j - 1] + 1;
				}
				f[now][j] = max(f[1 - now][j], f[now][j]);
				f[now][j] = max(f[now][j - 1], f[now][j]);
			}
			now = 1 - now;
		}
		//if (f[1 - now][n] == 1)
		//	f[1 - now][n] = 0;
		printf("%d\n", n - f[1 - now][n]);
	}
	return 0;
}
