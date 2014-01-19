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

int n;

bool arr[12];

char str[20];

int main() {
	while (scanf("%d\n", &n), n) {
		memset(arr, true, sizeof(arr));
		while (gets(str)) {
			if (str[4] == 'h') {
				for (int i = n; i < 11; i++) {
					arr[i] = false;
				}
			} else if (str[4] == 'l') {
				for (int i = 0; i <= n; i++) {
					arr[i] = false;
				}
			} else if (str[4] == 't') {
				break;
			}
			scanf("%d\n", &n);
		}
		if (arr[n]) {
			puts("Stan may be honest");
		} else {
			puts("Stan is dishonest");
		}
	}
	return 0;
}
