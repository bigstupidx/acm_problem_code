#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int n, m, flag[10];
char str[300], name[6][300], tem[300];

bool is_alp(char ch) {
	if (ch <= 'z' && ch >= 'a')return true;
	if (ch <= 'Z' && ch >= 'A')return true;
	if (ch <= '9' && ch >= '0')return true;
	return false;
}

void solve() {
	for (int i = 0; i < n; i++) {
		scanf("%s", name[i]);
	}
	getchar();
	for (int ii = 0; ii < m; ii++) {
		gets(str);
		int i, j, len = strlen(str) + 1;
		str[len - 1] = ' ';
		str[len] = '\0';
		memset(flag, 0, sizeof (flag));
		for (i = 0; i < len; i++) {
			if (!is_alp(str[i])) {
				str[i] = ' ';
			}
		}
		//puts(str);
		i = 0;
		while (str[i] == ' ')i++;
		j = i;
		int cnt = 0, ss = 0, hh = 0;
		for (; i < len; i++) {
			if (str[i] == ' ') {
				cnt++;
				for (int k = j; k < i; k++) {
					tem[k - j] = str[k];
				}
				tem[i - j] = '\0';
				for (int k = 0; k < n; k++) {
					if (strcmp(tem, name[k]) == 0) {
						printf("%s ", tem);
						ss = 1;
						break;
					} else if (strcmp(tem, "beautiful") == 0) {
						hh = 1;
						break;
					} else if (strcmp(tem, "pretty") == 0) {
						hh = 1;
						break;
					} else if (strcmp(tem, "lovely") == 0) {
						hh = 1;
						break;
					}
				}
				while (str[i] == ' ')i++;
				j = i--;
			}
		}
		if (!ss) {
			printf("All: ");
		}
		else {
			printf(":");
		}
		if (cnt < 10) {
			puts("oh");
		} else {
			if (hh) {
				puts("xixi");
			} else {
				puts("hehe");
			}
		}
	}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		solve();
	}
	return 0;
}