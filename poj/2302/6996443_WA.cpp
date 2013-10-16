#include <cstdio>
#include <cstring>

int map[6][6], mark[6][6], dis[80];
int dir[4][2] = {-1, -1, -1, 0, -1, 1, 0, -1};

bool check(int ii, int jj) {
    for (int k = 0; k < 4; k++) {
	int x = 0;
	int i = ii;
	int j = jj;
	while (mark[i][j]) {
	    i = i + dir[k][0];
	    j = j + dir[k][1];
	    if (i < 1 || i > 5 || j < 1 || j > 5)break;
	    if (!mark[i][j]) {
		x = 1;
		break;
	    }
	}
	if (x)continue;
	i = ii;
	j = jj;
	while (mark[i][j]) {
	    i = i - dir[k][0];
	    j = j - dir[k][1];
	    if (i < 1 || i > 5 || j < 1 || j > 5)break;
	    if (!mark[i][j]) {
		x = 1;
		break;
	    }
	}
	if (!x)return true;
    }
    return false;
}

int main() {
    int nca;
    scanf("%d", &nca);
    while (nca--) {
	memset(dis, 0, sizeof (dis));
	memset(mark, 0, sizeof (mark));
	for (int i = 1; i <= 5; i++) {
	    for (int j = 1; j <= 5; j++) {
		if (i == 3 && j == 3)continue;
		scanf("%d", &map[i][j]);
		dis[map[i][j]] = i * 5 + j - 1;
	    }
	}
	int cnt = 0, win = 0, xx = 0, num;
	for (int i = 0; i < 75; i++) {
	    scanf("%d", &num);
	    if (win)continue;
	    if (dis[num]) {
		int ii = dis[num] / 5;
		int jj = dis[num] % 5 + 1;
		mark[ii][jj] = 1;
		if (check(ii, jj)) {
		    win = 1;
		    cnt = i + 1;
		}
	    } else {
		if (!xx) {
		    xx = 1;
		    mark[3][3] = 1;
		    if (check(3, 3)) {
			win = 1;
			cnt = i + 1;
		    }
		}
	    }
	}
	printf("BINGO after %d numbers announced\n", cnt);
    }
    return 0;
}
