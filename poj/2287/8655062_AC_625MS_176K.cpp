//============================================================================
// Name        : acm.cpp
// Author      : wangjunyong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, arr[2][1002];

int main() {
	while (scanf("%d", &n), n) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				arr[i][j] = -arr[i][j];
			}
		}
		sort(arr[0], arr[0] + n);
		sort(arr[1], arr[1] + n);
		int ans = -200 * n;
		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < n; j++) {
				if (arr[0][j] < arr[1][(j + i) % n]) {
					temp += 200;
				} else if (arr[0][j] > arr[1][(j + i) % n]) {
					temp -= 200;
				}
			}
			if (temp > ans)
				ans = temp;
		}
		printf("%d\n", ans);
	}
	return 0;
}
