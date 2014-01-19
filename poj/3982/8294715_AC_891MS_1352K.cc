#include <cstdio>
#include <cstring>

using namespace std;

char arr[100][10001], str[3][10001];

void solve() {
	for (int i = 3; i < 100; i++) {
		for (int j = 0; j < 10000; ++j) {
			arr[i][j] += arr[i - 1][j] + arr[i - 2][j] + arr[i - 3][j];
			arr[i][j + 1] += arr[i][j] / 10;
			arr[i][j] %= 10;
		}
	}
	int flag = -1;
	for (int i = 10000; i >= 0; --i) {
		if (arr[99][i] != 0) {
			flag = i;
			break;
		}
	}
	if (flag == -1)
		puts("0");
	else {
		for (int i = flag; i >= 0; --i) {
			printf("%d", arr[99][i]);
		}
		puts("");
	}
}

int main() {
	while (scanf("%s%s%s", str[0], str[1], str[2]) != EOF) {
		memset(arr, 0, sizeof(arr));
		int len = strlen(str[0]);
		for (int i = len - 1; i >= 0; --i) {
			arr[0][len - i - 1] = str[0][i] - '0';
		}
		len = strlen(str[1]);
		for (int i = len - 1; i >= 0; --i) {
			arr[1][len - i - 1] = str[1][i] - '0';
		}
		len = strlen(str[2]);
		for (int i = len - 1; i >= 0; --i) {
			arr[2][len - i - 1] = str[2][i] - '0';
		}
		solve();
	}
	return 0;
}
