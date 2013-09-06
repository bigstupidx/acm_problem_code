//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, arr[100002];

bool solve(int mid) {
	int sum = 0, count = 1;
	for (int i = 1; i < n; i++) {
		int dis = arr[i] - arr[i - 1];
		if (sum + dis <= mid) {
			sum += dis;
		} else {
			++count;
			sum = 0;
		}
	}
	if (count + m >= n)
		return true;
	return false;
}

int main() {
	int l;
	while (scanf("%d%d%d", &l, &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		arr[n] = 0;
		arr[n + 1] = l;
		n += 2;
		sort(arr, arr + n);

		int lf = 0, rt = 1000000000;
		while (lf <= rt) {
			int mid = (lf + rt) / 2;
			if (solve(mid)) {
				lf = mid + 1;
			} else {
				rt = mid - 1;
			}
		}
		printf("%d\n", lf);
	}
	return 0;
}

