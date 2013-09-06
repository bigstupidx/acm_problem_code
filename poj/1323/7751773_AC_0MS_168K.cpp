#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, arr[52], ans[1002];

int main() {
	int nca = 0;
	while (scanf("%d%d", &n, &m), n || m) {
		for (int i = 0; i < m; i++) {
			scanf("%d", arr + i);
		}
		sort(arr, arr + m);
		int maxi = 0, num = 0;
		for (int j = m - 1, i = n * m; i > 0 && j >= 0; i--) {
			if (arr[j] == i) {
				--j, ++num;
				if (num > maxi)maxi = num;
			}
			else {
				--num;
			}
		}
		printf("Case %d: %d\n", ++nca, maxi);
	}
	return 0;
}
