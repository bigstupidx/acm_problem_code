#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, c[12], va[12], f[100010];

void multipack(int ii) {
	if (c[ii] * va[ii] >= m) {
		for (int i = va[ii]; i <= m; i++) {
			f[i] = max(f[i], f[i - va[ii]] + va[ii]);
		}
		return;
	}
	int k = 1;
	while (c[ii] > k) {
		for (int i = m; i >= va[ii]; i--) {
			if (i < k * va[ii])break;
			f[i] = max(f[i], f[i - k * va[ii]] + k * va[ii]);
		}
		c[ii] -= k;
		k <<= 1;
	}
	for (int i = m; i >= va[ii]; i--) {
		if (i < c[ii] * va[ii])break;
		f[i] = max(f[i], f[i - c[ii] * va[ii]] + c[ii] * va[ii]);
	}
}

int main() {
	while (scanf("%d%d", &m, &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &c[i], &va[i]);
		}
		memset(f, 0, sizeof (f));
		for (int i = 1; i <= n; i++) {
			multipack(i);
		}
		printf("%d\n", f[m]);
	}
	return 0;
}
