//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     : 1.0.0
// Copyright   : Your copyright notice
// Description : O(Nlog(N))
//============================================================================

#include <cstdio>

int n, arr[100010];

int main() {
//	freopen("in.txt", "r", stdin);

	while (scanf("%d", &n) != EOF) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			if (i == arr[i]) {
				++ans;
			}
		}

		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (i != arr[i] && i == arr[arr[i]]) {
				flag = true;
				ans += 2;
				break;
			}
		}
		if (!flag && ans != n) {
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
