#include <cstdio>
#include <cstring>

using namespace std;

int n, arr[5002], c[5002], f[5002];

void solve() {
	memset(c, 0, sizeof (c));
	c[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		int tp = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
					c[i] = c[j];
					tp = arr[j];
				}
				else if (f[i] == f[j] + 1 && tp != arr[j]) {
					c[i] += c[j];
				}
			}
		}
	}
	int maxi = 0;
	for (int i = 1; i < n; i++) {
		if (f[i] > maxi)maxi = f[i];
	}
	printf("%d %d\n", maxi, c[n]);
}

int main() {
	arr[0] = 1 << 30;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", arr + i);
		}
		arr[++n] = 0;
		solve();
	}
	return 0;
}
