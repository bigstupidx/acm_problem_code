#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, wi[3410], va[3410], f[13000];

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", wi + i, va + i);
		}
		for (int i = 0; i <= m; ++i) {
			f[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = m; j >= wi[i]; --j) {
				f[j] = max(f[j], f[j - wi[i]] + va[i]);
			}
		}
		printf("%d\n", f[m]);
	}
	return 0;
}
