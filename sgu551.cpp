#include <cstdio>
#include <cstring>

using namespace std;

int n, t1, t2;

void solve() {
	int left = 0, right = n * (t1 > t2 ? t1 : t2);
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = mid / t1 + mid / t2;
		if (sum < n) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	int n1 = (left + (t1 - 1)) / t1;
	int n2 = (left + (t2 - 1)) / t2;

	printf("%d %d\n", n1 + n2, n1 * t1 > n2 * t2 ? n1 * t1 : n2 * t2);
}

int main() {
	while (scanf("%d%d%d", &n, &t1, &t2) != EOF) {
		solve();
	}
	return 0;
}
