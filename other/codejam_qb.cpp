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

int n, s, p, arr[102];

int solve() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp = arr[i];
		int x = temp / 3;
		if (temp % 3 == 0) {
			if (x >= p)
				++ans;
			else if (x - 1 >= 0 && x + 1 >= p && s > 0) {
				--s;
				++ans;
			}
		} else if (temp % 3 == 1) {
			if (x + 1 >= p)
				++ans;
		} else {
			if (x + 1 >= p)
				++ans;
			else if (x + 2 >= p && s > 0) {
				--s;
				++ans;
			}
		}
	}
	return ans;
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int nca;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		printf("Case #%d: %d\n", ii, solve());
	}
	return 0;
}
