#include <cstdio>
#include <cstring>

char str[5];
int mp[3][3];

int xabs(int x) {
	return x > 0 ? x : -x;
}

bool checkWin(int xx) {
	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 0; j < 3; j++) {
			cnt += mp[i][j] == xx ? 1 : 0;
		}
		if (cnt == 3)
			return true;
	}

	for (int j = 0; j < 3; j++) {
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			cnt += mp[i][j] == xx ? 1 : 0;
		}
		if (cnt == 3)
			return true;
	}
	if (mp[0][0] == xx && mp[0][0] == mp[1][1] && mp[1][1] == mp[2][2]) {
		return true;
	}
	if (mp[0][2] == xx && mp[0][2] == mp[1][1] && mp[1][1] == mp[2][0]) {
		return true;
	}
	return false;
}

int main() {
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%s", str);
		for (int j = 0; j < 3; j++) {
			if (str[j] == 'X') {
				mp[i][j] = 0;
				++cnt0;
			} else if (str[j] == '0') {
				mp[i][j] = 1;
				++cnt1;
			} else {
				mp[i][j] = -1;
			}
		}
	}
	int cnt = cnt0 - cnt1;
	if (cnt < 0 || cnt > 1) {
		puts("illegal");

	} else {
		bool win0 = checkWin(0);
		bool win1 = checkWin(1);
		if (win0 && win1) {
			puts("illegal");
		} else if (win0) {
			puts(cnt == 1 ? "the first player won" : "illegal");
		} else if (win1) {
			puts(cnt == 0 ? "the second player won" : "illegal");
		} else {
			if (cnt0 + cnt1 == 9) {
				puts("draw");
			} else {
				puts(cnt0 > cnt1 ? "second" : "first");
			}
		}
	}
	return 0;
}
