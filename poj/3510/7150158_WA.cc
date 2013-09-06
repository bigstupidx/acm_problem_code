#include <cstdio>
#include <cstring>

char str[1002], tem[1002];

void solve(int &flag) {
	int len = strlen(str), k = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'E' && str[i + 1] == 'O' && str[i + 2] == 'F') {
			flag = 1;
			break;
		}
		else if (str[i] == 'p' && str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == 'k') {
			tem[k++] = 'f';
			tem[k++] = 'l';
			tem[k++] = 'o';
			tem[k++] = 'y';
			tem[k++] = 'd';
			tem[k++] = '#';
			i += 3;
		}
		else {
			tem[k++] = str[i];
		}
	}
	len = k;
	k = 0;
	for (int i = 0; i < len; i++) {
		if (tem[i] == 'd' && tem[i + 1] == 'd') {
			str[k++] = 'p';
			i++;
		}
		else if (tem[i] == 'e') {
			if (tem[i + 1] == 'i' && (i == 0 || i > 0 && tem[i - 1] != 'c')) {
				str[k++] = 'i';
				str[k++] = 'e';
				i++;
			}
			else {
				str[k++] = 'e';
			}
		}
		else {
			str[k++] = tem[i];
		}
	}
	for (int i = 0; i < k; i++) {
		if (str[i] == ' ' || str[i] <= 'z' && str[i] >= 'a') {
			putchar(str[i]);
		}
	}
	puts("");
}

int main() {
	int flag = 0;
	while (gets(str)) {
		if (flag)continue;
		solve(flag);
	}
	return 0;
}
