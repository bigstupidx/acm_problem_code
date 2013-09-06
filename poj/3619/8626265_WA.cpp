#include <cstdio>
#include <cstring>

using namespace std;

int solve(int n, int s, int t, int r) {
	int stage = n / (s * t);
	n %= s * t;
	double ans = stage * (t + r) + n * 1.0 / s;
	if (ans > (int) ans)
		return (int) ans + 1;
	return (int) ans;
}

int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		for (int i = 0; i < k; i++) {
			int s, t, r;
			scanf("%d%d%d", &s, &t, &r);
			printf("%d\n", solve(n, s, t, r));
		}
	}
	return 0;
}
