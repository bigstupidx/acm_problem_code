//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	int mini = 1000000000;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i * j > n)
				break;
			for (int k = j; k < n; k++) {
				if (i * j * k > n)
					break;
				if (i * j * k == n) {
					int ans = i * j + j * k + k * i;
					mini = mini < ans ? mini : ans;
				}
			}
		}
	}
	printf("%d\n", mini * 2);
}
int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		solve();
	}
	return 0;
}
