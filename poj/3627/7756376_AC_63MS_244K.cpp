#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, arr[20010];

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", arr + i);
		}
		sort(arr + 1, arr + 1 + n);
		int sum = 0, x;
		for (int i = n; i > 0; --i) {
			sum += arr[i];
			if (sum >= m) {
				x = i;
				break;
			}
		}
		printf("%d\n", n - x + 1);
	}
	return 0;
}
