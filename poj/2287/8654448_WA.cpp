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
			}
		}
		sort(arr[0], arr[0] + n);
		sort(arr[1], arr[1] + n);
		int pos = 0, mis = 0, a1 = 0, a2 = n - 1, b1 = 0, b2 = n - 1;
		for (int i = 0; i < n; i++) {
			if (arr[0][a2] > arr[1][b2]) {
				--a2;
				--b2;
				++pos;
			} else if (arr[0][a1] > arr[0][b1]) {
				++a1;
				++b1;
				++pos;
			} else {
				if (arr[0][a1] < arr[1][b2]) {
					++mis;
				}
				++a1;
				--b2;
			}
		}
		printf("%d\n", (pos - mis) * 200);
	}
	return 0;
}
