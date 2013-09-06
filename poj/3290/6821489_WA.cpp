#include <cstdio>
#include <cstring>

char str[102];
int cnt[12];

char get_char(int i) {
	if (i == 0)return 'p';
	if (i == 1)return 'q';
	if (i == 2)return 'r';
	if (i == 3)return 's';
	if (i == 4)return 't';
	if (i == 5)return 'K';
	if (i == 6)return 'A';
	if (i == 7)return 'C';
	if (i == 8)return 'E';
}

int main() {
	while (scanf("%s", str), strcmp(str, "0") != 0) {
		int len = strlen(str);
		memset(cnt, 0, sizeof (cnt));
		for (int i = 0; i < len; i++) {
			if (str[i] == 'p')
				cnt[0]++;
			else if (str[i] == 'q')
				cnt[1]++;
			else if (str[i] == 'r')
				cnt[2]++;
			else if (str[i] == 's')
				cnt[3]++;
			else if (str[i] == 't')
				cnt[4]++;
			else if (str[i] == 'K')
				cnt[5]++;
			else if (str[i] == 'A')
				cnt[6]++;
			else if (str[i] == 'C')
				cnt[7]++;
			else if (str[i] == 'E')
				cnt[8]++;
			else
				cnt[9]++;
		}
		int flag = 0, x = 0, sum = 0;
		for (int i = 0; i < 5; i++) {
			if (cnt[i] != 0) {
				flag = 1;
			}
			sum += cnt[i];
		}
		if (!flag) {
			puts("no WFF possible");
			continue;
		}
		while (cnt[9]) {
			cnt[9]--;
			putchar('N');
		};
		for (int j = 5; j < 9; j++) {
			while (cnt[j] && sum > 0) {
				int a = -1;
				for (int i = 0; i < 5; i++) {
					if (cnt[i]) {
						cnt[i]--;
						a = i;
					}
				}
				putchar(get_char(j));
				putchar(get_char(a));
				cnt[j]--;
				sum--;
				x = 1;
			}
		}
		if (!x) {
			for (int i = 0; i < 5; i++) {
				if (cnt[i]) {
					putchar(get_char(i));
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}