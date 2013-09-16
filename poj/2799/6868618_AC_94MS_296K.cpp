#include <cstdio>
#include <cstring>

int fi[8] = {1, 2, 4, 8, 16, 32, 64, 128};
int n, arr[1010][32], num[4], netAdd[32], mask[32];

int main() {
	while (scanf("%d", &n) != EOF) {
		memset(arr, 0, sizeof (arr));
		for (int j, i = 0; i < n; i++) {
			scanf("%d.%d.%d.%d", &num[0], &num[1], &num[2], &num[3]);
			for (int k = 3; k >= 0; k--) {
				j = 32 - (k + 1)* 8;
				while (num[k]) {
					arr[i][j++] = num[k] % 2;
					num[k] /= 2;
				}
			}
		}
		memset(mask, 0, sizeof (mask));
		memset(netAdd, 0, sizeof (netAdd));
		int k;
		for (k = 31; k >= 0; k--) {
			int x = arr[0][k], flag = 0;
			for (int i = 1; i < n; i++) {
				if (arr[i][k] != x) {
					flag = 1;
					break;
				}
			}
			if (flag)break;
			netAdd[k] = x;
			mask[k] = 1;
		}
		memset(num, 0, sizeof (num));
		for (int x, i = 0; i < 4; i++) {
			x = i * 8;
			for (int j = x; j < x + 8; j++) {
				num[i] += fi[j - x] * netAdd[j];
			}
		}
		printf("%d.%d.%d.%d\n", num[3], num[2], num[1], num[0]);
		memset(num, 0, sizeof (num));
		for (int x, i = 0; i < 4; i++) {
			x = i * 8;
			for (int j = x; j < x + 8; j++) {
				num[i] += fi[j - x] * mask[j];
			}
		}
		printf("%d.%d.%d.%d\n", num[3], num[2], num[1], num[0]);
	}
	return 0;
}