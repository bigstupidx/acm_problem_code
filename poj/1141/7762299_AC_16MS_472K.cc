#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int f[102][102], pre[102][102];
char str[120];

bool judge(int i, int j) {
	if (str[i] == '(' && str[j] == ')')return true;
	if (str[i] == '[' && str[j] == ']')return true;
	return false;
}

void output(int i, int j) {
	if (i > j)return;
	if (i == j) {
		if (str[i] == '(' || str[i] == ')') {
			printf("()");
		}
		else {
			printf("[]");
		}
		return;
	}
	if (pre[i][j] == -1) {
		printf("%c", str[i]);
		output(i + 1, j - 1);
		printf("%c", str[j]);
	}
	else {
		output(i, pre[i][j]);
		output(pre[i][j] + 1, j);
	}
}

void solve() {
	scanf("%s", str);
	int len = strlen(str);
	memset(f, 0, sizeof (f));
	for (int i = 0; i < len; i++) {
		f[i][i] = 1;
	}
	memset(pre, -1, sizeof (pre));
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			int temp = 1000000;
			if (judge(j, j + i)) {
				temp = f[j + 1][j + i - 1];
			}
			for (int k = j; k < j + i; k++) {
				if (temp > f[j][k] + f[k + 1][j + i]) {
					temp = f[j][k] + f[k + 1][j + i];
					pre[j][j + i] = k;
				}
			}
			f[j][j + i] = temp;
		}
	}
	output(0, len - 1);
	puts("");
	return;
}

int main() {
	solve();
	return 0;
}
