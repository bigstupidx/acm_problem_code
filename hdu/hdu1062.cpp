#include <cstdio>
#include <cstring>

using namespace std;

char str[1003];

void solve() {
	int len = strlen(str), j = -1;
	str[len] = ' ';
	str[++len] = '\0';
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ' || str[i] == '\t') {
			for (int k = i - 1; k > j; k--) {
				putchar(str[k]);
			}
			if (i != len - 1) {
				putchar(str[i]);
			}
			j = i;
		}
	}
	puts("");
}

int main() {
	int nca;
	scanf("%d", &nca);
	getchar();
	for (int i = 0; i < nca; i++) {
		gets(str);
		solve();
	}
	return 0;
}
