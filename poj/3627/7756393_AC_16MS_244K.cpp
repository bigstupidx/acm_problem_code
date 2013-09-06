#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, arr[20010];

void adjust(int ii) {
	int maxi = ii;
	if (ii * 2 <= n && arr[maxi] < arr[ii * 2]) {
		maxi = ii << 1;
	}
	if (ii * 2 + 1 <= n && arr[maxi] < arr[ii * 2 + 1]) {
		maxi = ii * 2 + 1;
	}
	if (maxi != ii) {
		int temp = arr[maxi];
		arr[maxi] = arr[ii];
		arr[ii] = temp;
		adjust(maxi);
	}
}

void make_heap() {
	for (int i = n / 2; i > 0; --i) {
		adjust(i);
	}
}

void heap_sort() {
	int nn = n;
	make_heap();
	for (int temp, i = 1; i <= nn; ++i) {
		temp = arr[1], arr[1] = arr[nn - i + 1], arr[nn - i + 1] = temp;
		--n;
		adjust(1);
	}
	n = nn;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", arr + i);
		}
		heap_sort();
		int sum = 0, x;
		//for (int i = 1; i <= n; i++) {
		//	printf("%d ", arr[i]);
		//}
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
