/*
http://codeforces.com/problemset/problem/339/C
*/

#include <cstdio>

char str[12];
bool flag[11];
int m, result[1002];

bool solve(int left, int right, int dep, int turn, int last) {
	if (dep == m)
		return true;

	if (turn == 0) {
		for (int i = 0; i < 10; i++) {
			if (flag[i] && i != last) {
				int new_left = left + i + 1;
				if (new_left > right && solve(new_left, right, dep + 1, 1 - turn, i)) {
					result[dep] = i;
					return true;
				}
			}
		}
		return false;
	} else {
		for (int i = 0; i < 10; i++) {
			if (flag[i] && i != last) {
				int new_right = right + i + 1;
				if (left < new_right && solve(left, new_right, dep + 1, 1 - turn, i)) {
					result[dep] = i;
					return true;
				}
			}
		}
		return false;
	}
}

int main() {
	while (scanf("%s%d", str, &m) != EOF) {
		for (int i = 0; i < 10; i++) {
			if (str[i] == '0') {
				flag[i] = false;
			} else {
				flag[i] = true;
			}
		}

		if (solve(0, 0, 0, 0, -1)) {
			puts("YES");
			for (int i = 0; i < m; i++) {
				printf("%d ", result[i] + 1);
			}
			puts("");
		} else {
			puts("NO");
		}
	}
	return 0;
}
