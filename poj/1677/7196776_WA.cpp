#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int n, m, ans[10];
char str[300], name[6][300], tem[300];

bool is_alp(char ch) {
	if (ch <= 'z' && ch >= 'a')return true;
	if (ch <= 'Z' && ch >= 'A')return true;
	if (ch <= '9' && ch >= '0')return true;
	return false;
}

bool is_upper(char ch) {
	if (ch <= 'Z' && ch >= 'A')return true;
	return false;
}

void solve() {
	for (int i = 0; i < n; i++) {
		gets(str);
		int len = strlen(str) - 1, j = 0, k = 0;
		while (str[j] == ' ')j++;
		while (str[len] == ' ')len--;
		for (int l = j; l <= len; l++) {
			name[i][k++] = str[l];
		}
		name[i][k] = '\0';
	}
	for (int ii = 0; ii < m; ii++) {
		gets(str);
		int i, j, len = strlen(str) + 1;
		str[len - 1] = ' ';
		str[len] = '\0';
		for (i = 0; i < len; i++) {
			if (!is_alp(str[i])) {
				str[i] = ' ';
			}
			if (is_upper(str[i])) {
				str[i] -= 'A' - 'a';
			}
		}
//		puts(str);
		i = 0;
		while (str[i] == ' ')i++;
		j = i;
		int cnt = 0, hh = 0, top = 0;
		for (; i < len; i++) {
			if (str[i] == ' ') {
				cnt++;
				for (int k = j; k < i; k++) {
					tem[k - j] = str[k];
				}
				tem[i - j] = '\0';
				for (int k = 0; k < n; k++) {
					if (strcmp(tem, name[k]) == 0) {
						ans[top++] = k;
						break;
					}
				}
				if(strcmp(tem, "beautiful") == 0)hh = 1;
				if(strcmp(tem, "pretty") == 0)hh = 1;
				if(strcmp(tem, "lovely") == 0)hh = 1;
				while (str[i] == ' ')i++;
				j = i--;
			}
		}
		if (!top) {
			printf("All:");
		}
		else {
			printf("%s", name[ans[0]]);
			for (int i = 1; i < top; i++) {
				printf(" %s", name[ans[i]]);
			}
			printf(":");
		}

		if (cnt < 10) {
			puts(" oh");
		}
		else {
			if (hh) {
				puts(" xixi");
			}
			else {
				puts(" hehe");
			}
		}
	}
}

int main() {
	//	freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {
		getchar();
		solve();
	}
	return 0;
}
