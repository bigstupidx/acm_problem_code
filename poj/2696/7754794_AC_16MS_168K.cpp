#include <cstdio>
#include <cstring>

using namespace std;

int n, arr[9], ans[1002];

int solve(int m) {
	ans[0] = arr[0], ans[1] = arr[1], ans[2] = arr[2];
	for (int i = 3; i < m; i++) {
		if (i % 2) {
			ans[i] = arr[3] * ans[i - 1] + arr[4] * ans[i - 2] - arr[5] * ans[i - 3];
			ans[i] %= arr[6];
			ans[i] = (arr[6] + ans[i]) % arr[6];
		}
		else {
			ans[i] = arr[5] * ans[i - 1] - arr[3] * ans[i - 2] + arr[4] * ans[i - 3];
			ans[i] %= arr[7];
			ans[i] = (arr[7] + ans[i]) % arr[7];
		}
	}
	//	for (int i = 0; i < m; i++) {
	//		printf("%d ", ans[i]);
	//	}
	return ans[m - 1];
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		for (int i = 0; i < 9; ++i) {
			scanf("%d", arr + i);
		}
		printf("%d\n", solve(arr[8] + 1));
	}
	return 0;
}
