#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

__int64 n, m, arr[100010];

int get_index(int lf, __int64 x) {
	int rt = n-1, mid;
	while (lf <= rt) {
		mid = (lf + rt) / 2;
		if (arr[mid] <= x) {
			lf = mid + 1;
		}
		else {
			rt = mid - 1;
		}
	}
	return lf - 1;
}

bool check(__int64 mid) {
	__int64 cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		cnt += get_index(i, arr[i] + mid) - i;
	}
	//printf("%I64d\n", cnt);
	return cnt < m;
}

int main() {
	while (scanf("%I64d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%I64d", &arr[i]);
		}
		sort(arr, arr + n);
		m = (n - 1) * n / 2;
		if (m % 2)m = m / 2 + 1;
		else m /= 2;
		__int64 lf = 0, mid;
		__int64 rt = arr[n - 1] - arr[0];
		while (lf <= rt) {
			mid = (lf + rt) / 2;
			//printf("try mid : %I64d ", mid);
			if (check(mid)) {
				lf = mid + 1;
			}
			else {
				rt = mid - 1;
			}
		}
		printf("%I64d\n", lf);
	}
	return 0;
}
