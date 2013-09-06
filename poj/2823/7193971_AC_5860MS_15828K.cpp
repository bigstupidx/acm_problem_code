#include <cstdio>
#include <cstring>
#define maxn 1000010

int n, len, min[2][maxn], max[2][maxn], now;

void make_rmq() {
	now = 0;
	for (int fic = 1; fic * 2 <= len; fic *= 2) {
		int m = n - fic;
		for (int j = 0; j < m; j++) {
			min[1 - now][j] = min[now][j] < min[now][j + fic] ? min[now][j] : min[now][j + fic];
			max[1 - now][j] = max[now][j] > max[now][j + fic] ? max[now][j] : max[now][j + fic];
		}
		now = 1 - now;
	}
}

void check_rmq() {
	n -= len - 1;
	int fic = 1, x, tem;
	while (fic * 2 <= len)fic <<= 1;
	x = len - fic;
	for (int i = 0; i < n; i++) {
		tem = min[now][i] < min[now][i + x] ? min[now][i] : min[now][i + x];
		printf("%d ", tem);
	}
	puts("");
	for (int i = 0; i < n; i++) {
		tem = max[now][i] > max[now][i + x] ? max[now][i] : max[now][i + x];
		printf("%d ", tem);
	}
	puts("");
}

int main() {
	while (scanf("%d%d", &n, &len) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &min[0][i]);
			max[0][i] = min[0][i];
		}
		make_rmq();
		check_rmq();
	}
	return 0;
}
