#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1000000000;
int n, m, va[502], wi[502], f[10010];

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		int x, y;
		scanf("%d%d", &x, &y);
		m = y - x;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &va[i], &wi[i]);
		}
		f[0] = 0;
		for (int i = 1; i <= m; i++) {
			f[i] = inf;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = wi[i]; j <= m; j++) {
				f[j] = min(f[j], f[j - wi[i]] + va[i]);
			}
		}
		if (f[m] >= inf)puts("This is impossible.");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", f[m]);
	}
	return 0;
}
