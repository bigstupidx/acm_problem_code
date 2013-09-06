//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <algorithm>

using namespace std;

int n, arr[100010];
char str[10];

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}

		sort(arr, arr + n);
		scanf("%s", str);
		int ii, m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &ii);
			printf("%d\n", arr[ii - 1]);
		}
	}
	return 0;
}
