#include <cstdio>
#include <cstring>

char str[100];

int get_char(char ch) {
	if (ch <= '9' && ch >= '0') {
		return ch - '0';
	}
	if (ch <= 'f' && ch >= 'a') {
		return ch - 'a' + 10;
	}
	return false;
}

int get_num(int lf, int rt, int base) {
	int tem, ans = 0;
	for (int i = lf; i < rt; i++) {
		ans *= base;
		tem = get_char(str[i]);
		if (tem == -1 || tem >= base)return -1;
		ans += tem;
	}
	return ans;
}

bool solve() {
	int base;
	int len = strlen(str), flag = 0, xflag = 0;
	for (int j, i = 0; i < len; i++) {
		if (str[i] == '#') {
			if (flag) {
				if (str[i - 1] == '#') {
					j = i + 1;
					xflag = 1;
				}
				else {
					base = get_num(j, i, base);
					if (base == -1)return false;
					if (i == len - 1)return true;
					if (!xflag)return false;
					if (base > 16 || base < 2)return false;
					j = i + 1;
					xflag = 0;
				}
			}
			else {
				if (str[0] == '#')return false;
				base = get_num(0, i, 10);
				if (base == -1 || base > 16 || base < 2)return false;
				flag = 1;
				j = i + 1;
			}
		}
	}
	return false;
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%s", str);
		if (solve()) {
			puts("yes");
		} else {
			puts("no");
		}
	}
	return 0;
}
