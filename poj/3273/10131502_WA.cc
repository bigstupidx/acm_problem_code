//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, arr[100002];

bool solve(int sum) {
	int count = 1, ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans + arr[i] > sum) {
			++count;
			ans = arr[i];
		} else {
			ans += arr[i];
		}
	}
	if (count <= m)
		return true;
	return false;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
			sum += arr[i];
		}
		int lf = 0, rt = 1000000;
		solve(500);
		while (lf <= rt) {
			int mid = (lf + rt) / 2;
			if (solve(mid)) {
				rt = mid - 1;
			} else {
				lf = mid + 1;
			}
		}
		printf("%d\n", lf);
	}
	return 0;
}
