#include <cstdio>
#include <cstring>

using namespace std;

char str[22][202], temp[202];

int main() {
	int n;
	while (scanf("%d", &n), n) {
		scanf("%s", temp);
		int len = strlen(temp), k = 0;
		for (int i = 0; i < len;) {
			if (k % 2 == 0) {
				str[k][i % n] = temp[i];
			} else {
				str[k][n - i % n - 1] = temp[i];
			}
			++i;
			if (i % n == 0) {
				++k;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				putchar(str[j][i]);
			}
		}
		puts("");
	}
	return 0;
}
