#include <cstdio>
#include <cstring>
#define MAXN 50010

int n, m, arr[MAXN], min[30][MAXN], max[30][MAXN];

void make_rmq() {
	for (int i = 1, fic = 1; 2 * fic <= n; fic *= 2, i++) {
		int x = n - fic;
		for (int j = 0; j < x; j++) {
			min[i][j] = min[i - 1][j] < min[i - 1][j + fic] ? min[i - 1][j] : min[i - 1][j + fic];
			max[i][j] = max[i - 1][j] > max[i - 1][j + fic] ? max[i - 1][j] : max[i - 1][j + fic];
		}
	}
}

int check_rmq(int lf, int rt) {
	if (lf > rt) {
		int tem = lf;
		lf = rt;
		rt = tem;
	}
	int fic = 1, i = 0, len = rt - lf + 1;
	while (fic * 2 <= len) {
		fic <<= 1;
		i++;
	}
	int ax = min[i][lf] < min[i][rt - fic + 1] ? min[i][lf] : min[i][rt - fic + 1];
	int bx = max[i][lf] > max[i][rt - fic + 1] ? max[i][lf] : max[i][rt - fic + 1];
	return bx - ax;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			min[0][i] = arr[i];
			max[0][i] = arr[i];
		}
		make_rmq();
		for (int x, y, i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			x--, y--;
			printf("%d\n", check_rmq(x, y));
		}
	}
	return 0;
}
