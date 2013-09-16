#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 52

using namespace std;

int n, m, arr[MAXN];

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < m; i++) {
			scanf("%d", arr + i);
		}
		sort(arr, arr + m);
		int ans = arr[n - 1] - arr[0];
		for (int tmp, i = 1; i < m; i++) {
			if (i + n - 1 >= m)
				break;
			tmp = arr[i + n - 1] - arr[i];
			ans = ans < tmp ? ans : tmp;
		}
		printf("%d\n", ans);
	}
	return 0;
}
