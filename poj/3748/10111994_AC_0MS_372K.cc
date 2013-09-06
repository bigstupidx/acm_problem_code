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

char str[50];

int arr[32], x, y;

void solve() {
	memset(arr, 0, sizeof(arr));
	int len = strlen(str), k = 0;
	bool first = true;
	for (int i = 0; i < len; i++) {
		if (str[i] == ',') {
			if (first) {
				for (int j = i - 1; j >= 0; j--) {
					int num = 0;
					if (str[j] >= 'a') {
						num = str[j] - 'a' + 10;
					} else {
						num = str[j] - '0';
					}
					int x = 4;
					while (num || x > 0) {
						arr[k++] = num % 2;
						num /= 2;
						--x;
					}
				}
				first = false;
				x = 0;
				while (++i < len && str[i] != ',') {
					x *= 10;
					x += str[i] - '0';
				}
				--i;
			} else {
				y = 0;
				while (++i < len) {
					y *= 10;
					y += str[i] - '0';
				}
			}
		}
	}
//	printf("%d %d\n", x, y);
	arr[x] = 0;
	arr[y] = 1;
	arr[y - 1] = 1;
	arr[y - 2] = 0;
	first = false;

//	for (int i = 31; i >= 0; i--) {
//		printf("%d", arr[i]);
//	}
	for (int i = 7; i >= 0; i--) {
		int num = arr[i * 4 + 3] * 8 + arr[i * 4 + 2] * 4 + arr[i * 4 + 1] * 2 + arr[i * 4];
		if (num > 9) {
			putchar('a' + num - 10);
			first = true;
		} else {
			if (num == 0 && !first)
				continue;
			first = true;
			putchar('0' + num);
		}
	}
	puts("");
}

int main() {
	while (scanf("%s", str) != EOF) {
		solve();
	}
	return 0;
}