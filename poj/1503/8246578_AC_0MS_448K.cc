#include <cstdio>
#include <cstring>

using namespace std;

char temp[200];

int input[100][120], ans[120];

int main() {
	memset(input, 0, sizeof(input));
	int cnt = 0;
	while (scanf("%s", temp), strcmp(temp, "0") != 0) {
		int len = strlen(temp);
		for (int i = 0; i < len; ++i) {
			input[cnt][len - i - 1] = temp[i] - '0';
		}
		++cnt;
	}
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < 120; i++) {
		for (int j = 0; j < cnt; ++j) {
			ans[i] += input[j][i];
		}
		ans[i + 1] += ans[i] / 10;
		ans[i] = ans[i] % 10;
	}
	bool begin = false;
	for (int i = 120; i >= 0; i--) {
		if (ans[i] != 0) {
			begin = true;
			printf("%c", ans[i] + '0');
		} else {
			if (begin) {
				printf("%c", '0');
			}
		}
	}
	puts("");
	return 0;
}
