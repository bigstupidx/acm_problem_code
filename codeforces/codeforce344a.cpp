//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     : 1.0.0
// Copyright   : Your copyright notice
// Description : O(Nlog(N))
//============================================================================

#include <cstdio>

int main() {
//	freopen("in.txt", "r", stdin);
	int n, a, b;
	while (scanf("%d", &n) != EOF) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			if (i == 0 || b != a) {
				++ans;
			}
			b = a;
		}
		printf("%d\n", ans);
	}
	return 0;
}
