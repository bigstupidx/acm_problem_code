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
int ans[2002], a[2002], b[2002], c[2002];

char str[502];

void calc(int n) {
	if (n == 1) {
		for (int i = 0; i < 202; i++) {
			c[i] = a[i];
		}
		return;
	}
	calc(n / 2);
	memset(b, 0, sizeof(b));
	for (int i = 0; i < 2002; i++) {
		b[i] = c[i];
	}
	memset(c, 0, sizeof(c));
	for (int i = 0; i < 2002; i++) {
		for (int j = 0; j < 2002; j++) {
			if (i + j > 2002)
				continue;
			c[i + j] += b[i] * b[j];
		}
	}
	if (n % 2 == 1) {
		memset(b, 0, sizeof(b));
		for (int i = 0; i < 2002; i++) {
			for (int j = 0; j < 2002; j++) {
				if (i + j > 2002)
					continue;
				b[i + j] += c[i] * a[j];
			}
		}
		for (int i = 0; i < 2002; i++) {
			c[i] = b[i];
		}
	}
	for (int i = 0; i < 2002; i++) {
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
		bool big = false;
		for (int i = 2001; i >= 0; i--) {
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
