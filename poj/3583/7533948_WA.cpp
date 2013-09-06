#include <cstdio>
#include <cstring>

char str[102], arr[1002][102], ans[1002];

void solve(int n) {
	int len = strlen(str), k = -1;
	for (int i = 0; i < len; ++i) {
		if (str[i] == '\\') {
			ans[++k] = str[i + 1];
			i++;
		}
		else if (str[i] == '{') {
			int j = i, flag = 0, num = 0;
			while (str[j] != '}')++j;
			for (int x = i + 1; x < j; ++x) {
				if (str[x] <= '9' && str[x] >= '0') {
					num = num * 10 + str[x] - '0';
				}
				else {
					flag = 1;
					break;
				}
			}
			if (!flag && num > 0 && num <= n) {
				int xlen = strlen(arr[num]);
				for (int x = 0; x < xlen; ++x) {
					ans[++k] = arr[num][x];
				}
				i = j;
			}
			else {
				ans[++k] = str[i];
			}
		}
		else {
			ans[++k] = str[i];
		}
	}
	ans[++k] = 0;
	puts(ans);
}

int main() {
	gets(str);
	int n = 1;
	while (gets(arr[n])) {
		n++;
	}
	solve(n);
	return 0;
}
