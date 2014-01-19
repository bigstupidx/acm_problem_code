//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     : 1.0.0
// Copyright   : Your copyright notice
// Description : O(Nlog(N))
//============================================================================

#include <cstdio>
#include <algorithm>

using namespace std;

int n, arr[110];

int main() {
//	freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		sort(arr, arr + n);
		printf("%d ", arr[--n]);
		for (int i = 1; i < n; i++) {
			printf("%d ", arr[i]);
		}
		if (n > 0)
			printf("%d\n", arr[0]);
		else
			puts("");
	}
	return 0;
}
