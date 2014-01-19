#include <cstdio>
#include <string.h>

int n, m, flag[60];

struct node {
	char tem[102];
	char str[102];
	char upt[102];
} exp[60], acr[60];

char str[100], ch, tem[3][100];

void get_exp() {
	int i = 0, k;
	while (str[i] != '"')i++;
	for (k = 0, i++; str[i] != '"'; i++) {
		tem[0][k++] = str[i];
	}
	tem[0][k] = 0;
	i++, k = 0;
	while (str[i] != '"')i++;
	for (i++; str[i] != '"'; i++) {
		tem[1][k++] = str[i];
	}
	tem[1][k] = 0;
}

bool is_alp(char ch) {
	if (ch == ' ' || ch == '\t' || ch == '.' || ch == ',')return false;
	if (ch == '?' || ch == '!')return false;
	return true;
}

void solve() {
	int len = strlen(str), i = 0;
	str[len++] = ' ';
	while (!is_alp(str[i])) {
		putchar(str[i]);
		i++;
	}
	for (int k = i; i < len; i++) {
		if (!is_alp(str[i])) {
			int yflag = 0;
			for (int j = k; j < i; j++) {
				tem[0][j - k] = str[j];
			}
			tem[0][i - k] = 0;
			for (int ii = 0; ii < n; ii++) {
				if (strcmp(exp[ii].str, tem[0]) == 0) {
					printf("%s", exp[ii].tem);
					yflag = 1;
					break;
				}
			}
			if (!yflag) {
				strcpy(tem[1], tem[0]);
				tem[1][0] += 'a' - 'A';
				for (int ii = 0; ii < n; ii++) {
					if (strcmp(exp[ii].upt, tem[0]) == 0) {
						yflag = 1;
						int xlen = strlen(exp[ii].tem);
						for (int jj = 0; jj < xlen; jj++) {
							ch = exp[ii].tem[jj];
							if (ch <= 'z' && ch >= 'a') {
								putchar(ch + 'A' - 'a');
							}
							else putchar(ch);
						}
						break;
					}
					if (strcmp(exp[ii].str, tem[1]) == 0) {
						yflag = 1;
						ch = exp[ii].tem[0];
						if (ch <= 'z' && ch >= 'a')putchar(ch + 'A' - 'a');
						else putchar(ch);
						printf("%s", exp[ii].tem + 1);
						break;
					}
				}
			}
			if (!yflag) {
				for (int ii = 0; ii < m; ii++) {
					if (flag[ii])continue;
					if (strcmp(tem[0], acr[ii].str) == 0) {
						flag[ii] = 1;
						yflag = 1;
						printf("%s (%s)", acr[ii].tem, tem[0]);
						break;
					}
				}
			}
			if (!yflag) {
				printf("%s", tem[0]);
			}
			while (i < len && !is_alp(str[i])) {
				if (i != len - 1)putchar(str[i]);
				i++;
			}
			k = i;
		}
	}
	puts("");
}

int main() {
	//freopen("out.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	while ((ch = getchar()) != '\n');
	for (int i = 0; i < n; i++) {
		gets(str);
		get_exp();
		strcpy(exp[i].str, tem[0]);
		strcpy(exp[i].tem, tem[1]);
		strcpy(exp[i].upt, tem[0]);
		int len = strlen(tem[0]);
		for (int j = 0; j < len; j++) {
			if (tem[0][j] <= 'z' && tem[0][j] >= 'a') {
				exp[i].upt[j] += 'A' - 'a';
			}
		}
	}
	for (int i = 0; i < m; i++) {
		gets(str);
		get_exp();
		strcpy(acr[i].str, tem[0]);
		strcpy(acr[i].tem, tem[1]);
	}
	while (gets(str)) {
		memset(flag, 0, sizeof (flag));
		solve();
		while (gets(str)) {
			if (strcmp(str, "#") == 0)break;
			solve();
		}
		puts("#");
	}
	return 0;
}
