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

int n, top;
int ans[200], a[300], b[300], c[300];

char str[202];

void calc(int n) {
	if (n == 1) {
		for (int i = 0; i < 102; i++) {
			c[i] = a[i];
		}
		return;
	}
	calc(n / 2);
	memset(b, 0, sizeof(b));
	for (int i = 0; i < 102; i++) {
		b[i] = c[i];
	}
	memset(c, 0, sizeof(c));
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			c[i + j] += b[i] * b[j];
		}
	}
	if (n % 2 == 1) {
		memset(b, 0, sizeof(b));
		for (int i = 0; i < 102; i++) {
			for (int j = 0; j < 102; j++) {
				b[i + j] += c[i] * a[j];
			}
		}
		for (int i = 0; i < 102; i++) {
			c[i] = b[i];
		}
	}
	for (int i = 0; i < 102; i++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
}

void solve() {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		ans[len - i - 1] = str[i] - '0';
	}
	int left = 0, right = 1000000001;
	while (left <= right) {
		int mid = (left + right) / 2;
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		int temp = mid, j = 0;
		while (temp) {
			a[j++] = temp % 10;
			temp /= 10;
		}
		calc(n);
//		printf("%d : ", mid);
//		for (int i = 20; i >= 0; i--) {
//			printf("%d ", c[i]);
//		}
//		puts("");
//		for (int i = 20; i >= 0; i--) {
//			printf("%d ", ans[i]);
//		}
//		puts("");

		bool big = false;
		for (int i = 102; i >= 0; i--) {
			if (ans[i] > c[i]) {
				break;
			} else if (ans[i] < c[i]) {
				big = true;
				break;
			}
		}
		if (big)
			right = mid - 1;
		else
			left = mid + 1;
	}
	printf("%d\n", left - 1);
}

int main() {
	while (scanf("%d%s", &n, str) != EOF) {
		solve();
	}
	return 0;
}
