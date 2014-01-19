#include <cstdio>
#include <cstdlib>
#include <cstring>

int f[1003][1003];
int l1, l2;
char s1[1003], s2[1003];

int fmax(int a, int b) {
	return a > b ? a : b;
}

int main() {
	while (scanf("%d%s%d%s", &l1, s1 + 1, &l2, s2 + 1) != EOF) {
		memset(f, 0, sizeof (f));
		for (int i = 1; i < l1 + 1; i++)
			for (int j = 1; j < l2 + 1; j++) {
				int tmp;
				f[i][j] = fmax(f[i - 1][j], f[i][j - 1]);

				if (s1[i] == s2[j]) {
					tmp = f[i - 1][j - 1] + 1;
					f[i][j] = fmax(f[i][j], tmp);
				}
			}
		int ans = l1 > l2 ? l1 : l2;
		ans -= f[l1][l2];
		printf("%d\n", ans);
	}
	return 0;
}
