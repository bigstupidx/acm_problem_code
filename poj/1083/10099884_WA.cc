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
int arr[500];

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		memset(arr, 0, sizeof(arr));
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (u % 2 == 0)
				u--;
			if (v % 2 == 1)
				v++;
			for (int j = u; j <= v; j++) {
				++arr[j];
			}
		}
		int ans = 0;
		for (int i = 0; i < 402; i++) {
			if (arr[i] > ans)
				ans = arr[i];
		}
		printf("%d\n", ans * 10);
	}
	return 0;
}
