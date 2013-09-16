#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 100;

char buf[MAX_N], tmp[MAX_N], st[MAX_N];

int main() {
	while (scanf("%s", buf) != EOF) {
		int ans = 0;
		int len = strlen(buf);
		strcpy(tmp, buf);
		for (int i = 0; i < 10; ++i) {
			if (!prev_permutation(buf, buf + len)) break;
			int mini = 1000;
			for (int i = 1; i < len; ++i) {
				mini = min(mini, abs(buf[i] - buf[i - 1]));
			}
			if (ans <= mini) {
				ans = mini;
				strcpy(st, buf);
			}
		}
		int mini = 1000;
		for (int i = 1; i < len; ++i) {
			mini = min(mini, abs(tmp[i] - tmp[i - 1]));
		}
		if (ans < mini) {
			ans = mini;
			strcpy(st, tmp);
		}
		strcpy(buf, tmp);
		for (int i = 0; i < 10; ++i) {
			if (!next_permutation(buf, buf + len)) break;
			int mini = 1000;
			for (int i = 1; i < len; ++i) {
				mini = min(mini, abs(buf[i] - buf[i - 1]));
			}
			if (ans < mini) {
				ans = mini;
				strcpy(st, buf);
			}
		}
		printf("%s%d\n", st, ans);
	}
	return 0;
}




