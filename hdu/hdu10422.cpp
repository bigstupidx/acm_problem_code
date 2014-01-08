#include <cstdio>
#include <cstring>

int que[2][10000000];

void solve(int n) {
	que[0][0] = 1;
	int now = 1, len = 1;
	for (int i = 2; i <= n; i++) {
		int carry = 0, len_x = 0;
		for (int j = 0; j < len; j++) {
			carry = que[1 - now][j] * i + carry;
			que[now][len_x++] = carry % 10;
			carry /= 10;
		}
		while (carry) {
			que[now][len_x++] = carry % 10;
			carry /= 10;
		}
		now = 1 - now;
		len = len_x;
	}
	for (int i = len - 1; i >= 0; i--) {
		printf("%d", que[1 - now][i]);
	}
	puts("");
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		solve(n);
	}
	return 0;
}
