#include <cstdio>
#include <algorithm>

using namespace std;

int n;
__int64 arr[100002];

__int64 gcd(__int64 a, __int64 b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main() {
	while (scanf("%d", &n) != EOF) {
		__int64 sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%I64d", &arr[i]);
			sum += arr[i];
		}
		sort(arr, arr + n);
		for (int i = 0; i < n; i++) {
			sum += 2 * arr[i] * (2 * i + 1 - n);
		}
		__int64 gg = gcd(sum, n);
		printf("%I64d %I64d\n", sum/gg, n / gg);
	}
	return 0;
}
