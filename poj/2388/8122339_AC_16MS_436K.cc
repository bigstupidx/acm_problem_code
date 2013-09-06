#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, arr[10010];

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		sort(arr, arr + n);
		printf("%d\n", arr[n / 2]);
	}
	return 0;
}
