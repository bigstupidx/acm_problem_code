//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     : 1.0.0
// Copyright   : Your copyright notice
// Description : O(Nlog(N))
//============================================================================

#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 100010

using namespace std;

int n, arr[MAXN], c[MAXN];

int binary_search(int top, int x) {
	int left = 0, right = top - 1;
	while (left <= right) {
		int mid = (left + right);
		if (c[mid] == x)
			return mid;

		if (c[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

int main() {
//	freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			int index = binary_search(maxi, arr[i]);
			c[index] = arr[i];
			if (index >= maxi)
				++maxi;
		}
		printf("%d\n", maxi);
	}
	return 0;
}
