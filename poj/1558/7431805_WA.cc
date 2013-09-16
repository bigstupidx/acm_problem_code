#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[10][10], tem[3];

struct node {
	char str[10];

	bool operator<(const node & a)const {
		return strcmp(a.str, str) > 0;
	}
} nod[1000010];

int dir[8][2] = {
	0, -1, -1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1
};

bool ok(int i, int j) {
	if (i < 8 && i >= 0 && j < 8 && j >= 0)return true;
	return false;
}

void solve() {
	int top = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (str[i][j] == tem[0]) {
				for (int k = 0; k < 8; k++) {
					int ii = i + dir[k][0];
					int jj = j + dir[k][1];
					int cnt = 0;
					while (ok(ii, jj)) {
						if (str[ii][jj] != '.')cnt++;
						ii += dir[k][0];
						jj += dir[k][1];
					}
					ii = i - dir[k][0];
					jj = j - dir[k][1];
					while (ok(ii, jj)) {
						if (str[ii][jj] != '.')cnt++;
						ii -= dir[k][0];
						jj -= dir[k][1];
					}
					cnt++;
					ii = i;
					jj = j;
					int flag = 0;
					while (cnt) {
						cnt--;
						ii += dir[k][0];
						jj += dir[k][1];
						if (!ok(ii, jj) || str[ii][jj] == tem[1]) {
							flag = 1;
							break;
						}
					}
					if (!ok(ii, jj))continue;
					if (!flag) {
						nod[top].str[0] = i + 'A';
						nod[top].str[1] = j + '1';
						nod[top].str[2] = '-';
						nod[top].str[3] = ii + 'A';
						nod[top].str[4] = jj + '1';
						nod[top].str[5] = 0;
						top++;
					}
				}
			}
		}
	}
	if (!top)puts("No moves are possible");
	else {
		sort(nod, nod + top);
		for (int i = 0; i < top; i++) {
			puts(nod[i].str);
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	int xflag = 0;
	while (scanf("%s", str[0]) != EOF) {
		if (xflag)puts("");
		else xflag = 1;
		for (int i = 1; i < 8; i++) {
			scanf("%s", str[i]);
		}
		scanf("%s", tem);
		if (tem[0] == 'O')tem[1] = 'X';
		else tem[1] = 'O';
		solve();
	}
	return 0;
}
