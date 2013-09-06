#include <cstdio>

using namespace std;

int n, arr[40010], ans[40010];

int binary_search(int m, int x) {
	int lf = 0, rt = m;
	while (lf <= rt) {
		int mid = (lf + rt) / 2;
		if (ans[mid] < x)
			lf = mid + 1;
		else
			rt = mid - 1;
	}
	return lf;
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
		}
		int k = -1;
		for (int i = 0; i < n; ++i) {
			int id = binary_search(k, arr[i]);
			ans[id] = arr[i];
			if (id > k)++k;
		}
		printf("%d\n", k + 1);
	}
	return 0;
}
