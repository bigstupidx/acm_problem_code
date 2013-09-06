#include <cstdio>
#include <cstring>

using namespace std;

char str[203];

int main() {
	int n, n1, n0, n2;
	while (scanf("%d%d%d", &n, &n0, &n1) != EOF) {
		scanf("%s", str);
		if (n1 + n0 > n) {
			puts("-1");
			continue;
		}
		n2 = n - n0 - n1;
		for (int i = 0; i < n; i++) {
			if (str[i] == '0') {
				--n0;
			} else if (str[i] == '1') {
				--n1;
			} else {
				--n2;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == '0') {
				if (n0 < 0) {
					++n0;
					++ans;
					if (n1 > 0) {
						--n1;
						str[i] = '1';
					} else {
						str[i] = '2';
					}
				}
			} else if (str[i] == '1') {
				if (n1 < 0) {
					++n1;
					++ans;
					if (n0 > 0) {
						--n0;
						str[i] = '0';
					} else {
						str[i] = '2';
					}
				}

			} else {
				if (n2 < 0) {
					++n2;
					++ans;
					if (n0 > 0) {
						--n0;
						str[i] = '0';
					} else {
						--n1;
						str[i] = '1';
					}
				}
			}
		}
		printf("%d\n%s\n", ans, str);
	}
	return 0;
}
