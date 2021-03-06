#include <cstdio>
#include <cstring>

char str[102], arr[1002][102], ans[1002];

void solve(int n) {
	int len = strlen(str), k = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '\\') {
			ans[k++] = '\\';
			i++;
		}
		else if (str[i] == '{') {
			int j = i, flag = 0, num = 0;
			while (str[j] != '}')j++;
			int x = i + 1, y = j - 1;
			while (str[x] == ' ' || str[x] == '\t')x++;
			while (str[y] == ' ' || str[y] == '\t')y--;
			if (x <= y) {
				int cnt = 0;
				while (str[y] == '\\')cnt++, y--;
				for (int z = x; z <= y; z++) {
					if (str[z] <= '9' && str[z] >= '0') {
						num = num * 10 + str[z] - '0';
					}
					else {
						flag = 1;
						break;
					}
				}
				if (!flag && num > 0 && num <= n && cnt % 2 == 0) {
					//					for (; i < x; i++) {
					//						ans[k++] = str[i];
					//					}
					int xlen = strlen(arr[num]);
					for (int z = 0; z < xlen; z++) {
						ans[k++] = arr[num][z];
					}
					cnt /= 2;
					for (int z = 0; z < cnt; z++) {
						ans[k++] = '\\';
					}
					//					for (++y; y <= j; y++) {
					//						ans[k++] = str[y];
					//					}
					i = j;
				}
				else ans[k++] = str[i];
			}
			else {
				ans[k++] = str[i];
			}
		}
		else {
			ans[k++] = str[i];
		}
	}
	ans[k] = 0;
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
