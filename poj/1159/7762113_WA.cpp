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
		int last = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (str[i] == str[n - j + 1]) {
					f[1 - last][j] = f[last][j - 1] + 1;
				}
				f[1 - last][j] = max(f[1 - last][j], max(f[last][j], f[1 - last][j - 1]));
			}
			last = 1 - last;
		}
		if (f[1 - last][n] == 1)
			f[1 - last][n] = 0;
		printf("%d\n", n - f[1 - last][n]);
	}
	return 0;
}
