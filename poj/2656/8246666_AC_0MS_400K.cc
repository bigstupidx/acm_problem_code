#include <cstdio>

int main() {
	int n;
	while (scanf("%d", &n), n) {
		int ans = 0, maxi = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (a + b > 8 && a + b - 8 > maxi) {
				maxi = a + b - 8;
				ans = i + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
