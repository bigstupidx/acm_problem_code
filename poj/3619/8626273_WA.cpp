#include <cstdio>
#include <cstring>

using namespace std;

int solve(int n, int s, int t, int r) {
	int stage = n / (s * t);
	n %= s * t;
	return stage * (t + r) + (n + s - 1) / s;
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
