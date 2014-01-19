#include <cstdio>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int gg[9][9] = {
	-1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1,  1,  2,  3, -1, -1, -1,
	-1, -1, -1,  4,  5,  6, -1, -1, -1,
	-1,  7,  8,  9, 10, 11, 12, 13, -1,
	-1, 14, 15, 16, 17, 18, 19, 20, -1,
	-1, 21, 22, 23, 24, 25, 26, 27, -1,
	-1, -1, -1, 28, 29, 30, -1, -1, -1,
	-1, -1, -1, 31, 32, 33, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1,
};

int mark[40], dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

map <int, int> mp;
map <int, int> ::iterator p;

void pre_done() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (gg[i][j] != -1) {
				mp[gg[i][j]] = i * 9 + j;
			}
		}
	}
}

int solve() {
	while (1) {
		int start, end = -1, tem;
		for (int i = 1; i < 34; i++) {
			if (mark[i]) {
				int j = mp.find(i)->second;
				for (int k = 0; k < 4; k++) {
					int ii = j / 9 + dir[k][0];
					int jj = j % 9 + dir[k][1];
					if (gg[ii][jj] == -1 || !mark[gg[ii][jj]])continue;
					ii += dir[k][0];
					jj += dir[k][1];
					if (gg[ii][jj] == -1 || mark[gg[ii][jj]])continue;
					if (end == -1 || end <= gg[ii][jj]) {
						start = i;
						end = gg[ii][jj];
						tem = gg[ii - dir[k][0]][jj - dir[k][1]];
					}
				}
			}
		}
		if (end == -1)break;
		//printf("%d %d %d\n", start, tem, end);
		mark[start] = 0;
		mark[tem] = 0;
		mark[end] = 1;
	}
	int ans = 0;
	for (int i = 1; i < 34; i++) {
		if (mark[i])ans += i;
	}
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	pre_done();
	scanf("%d", &nca);
	puts("HI Q OUTPUT");
	while (nca--) {
		int u;
		memset(mark, 0, sizeof (mark));
		while (scanf("%d", &u), u) {
			mark[u] = 1;
		}
		printf("%d\n", solve());
	}
	puts("END OF OUTPUT");
	return 0;
}
