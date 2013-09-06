#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, arr[52], ans[1002];

void adjust(int ii) {
	int maxi = ii;
	if (2 * ii <= m && arr[maxi] < arr[2 * ii]) {
		maxi = 2 * ii;
	}
	if (2 * ii + 1 <= m && arr[maxi] < arr[2 * ii + 1]) {
		maxi = 2 * ii + 1;
	}
	if (ii != maxi) {
		int tp = arr[ii];
		arr[ii] = arr[maxi], arr[maxi] = tp;
		adjust(maxi);
	}
}

void make_heap() {
	for (int i = m / 2; i > 0; i--) {
		adjust(i);
	}
}

void heap_sort() {
	make_heap();
	int tp, x = m;
	for (int i = 1; i <= x; i++) {
		tp = arr[1], arr[1] = arr[x - i + 1], arr[x - i + 1] = tp;
		--m;
		adjust(1);
	}
	m = x;
}

int main() {
	int nca = 0;
	while (scanf("%d%d", &n, &m), n || m) {
		for (int i = 1; i <= m; i++) {
			scanf("%d", arr + i);
		}
		heap_sort();
		int maxi = 0, num = 0;
		for (int j = m, i = n * m; i > 0 && j > 0; i--) {
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
