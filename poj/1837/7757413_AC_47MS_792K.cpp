#include <cstdio>
#include <cstring>

using namespace std;

int n, m, va[30], wi[20], f[20][8000];

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", va + i);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d", wi + i);
		}
		memset(f, 0, sizeof (f));
		f[0][4000] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < n; j++) {
				int d = wi[i] * va[j];
				for (int k = 0; k < 8000; k++) {
					if (k + d < 0)continue;
					f[i][k + d] += f[i - 1][k];
				}
			}
		}
		printf("%d\n", f[m][4000]);
	}
	return 0;
}
