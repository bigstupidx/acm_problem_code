#include <cstdio>
#include <cstring>

struct node {
	int x, y, k, cnt;
} nod[102][102];

int n, dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};

bool check(int j) {
	for (int i = 1; i < n; i++) {
		if (nod[i][j].x != nod[i - 1][j].x || nod[i][j].y != nod[i - 1][j].y) {
			return false;
		}
	}
	return true;
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 73; j++) {
			int z = (nod[i][j - 1].cnt + nod[i][j - 1].k) % 4;
			int x = nod[i][j - 1].x + dir[z][0];
			int y = nod[i][j - 1].y + dir[z][1];
			if (x <= 4 && x > 0 && y <= 4 && y > 0) {
				nod[i][j].x = x;
				nod[i][j].y = y;
				nod[i][j].k = z;
				nod[i][j].cnt = (nod[i][j - 1].cnt + 1) % 2;
			} else {
				if (nod[i][j - 1].cnt == 0) {
					x = nod[i][j - 1].x + dir[(z + 1) % 4][0];
					y = nod[i][j - 1].y + dir[(z + 1) % 4][1];
					if (x <= 4 && x > 0 && y <= 4 && y > 0) {
						nod[i][j].x = x;
						nod[i][j].y = y;
						nod[i][j].k = (z + 1) % 4;
						nod[i][j].cnt = 0;
					} else {
						if (j == 1) {
							nod[i][1].x = nod[i][0].x;
							nod[i][1].y = nod[i][0].y;
							nod[i][1].k = nod[i][0].k;
							nod[i][1].cnt = nod[i][0].cnt;
						} else {
							nod[i][j].x = nod[i][j - 2].x;
							nod[i][j].y = nod[i][j - 2].y;
							nod[i][j].k = nod[i][j - 2].k;
							nod[i][j].cnt = nod[i][j - 2].cnt;
						}
					}
				} else {
					if (j == 1) {
						nod[i][1].x = nod[i][0].x;
						nod[i][1].y = nod[i][0].y;
						nod[i][1].k = nod[i][0].k;
						nod[i][1].cnt = nod[i][0].cnt;
					} else {
						nod[i][j].x = nod[i][j - 2].x;
						nod[i][j].y = nod[i][j - 2].y;
						nod[i][j].k = nod[i][j - 2].k;
						nod[i][j].cnt = nod[i][j - 2].cnt;
					}
				}
			}
		}
	}
	//	puts("");
	//	for(int i=0;i<n;i++){
	//		for(int j=0;j<5;j++){
	//			printf("(%d, %d) ", nod[i][j].x, nod[i][j].y);
	//		}
	//		puts("");
	//	}
	int cnt = -1;
	for (int i = 1; i < 73; i++) {
		if (check(i)) {
			cnt = i;
			break;
		}
	}
	if (cnt == -1)puts("no terror threat");
	else {
		int ans = 800 + (cnt * 20 / 60)*100 + (cnt * 20) % 60;
		printf("%d, %d, %d\n", nod[0][cnt].x, nod[0][cnt].y, ans);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		scanf("%d", &n);
		char str[4];
		for (int i = 0; i < n; i++) {
			scanf("%d%*c%d%*c%s", &nod[i][0].x, &nod[i][0].y, str);
			if (str[0] == 'F') {
				nod[i][0].k = 0;
				nod[i][0].cnt = 0;
			} else {
				nod[i][0].k = 1;
				nod[i][0].cnt = 1;
			}
		}
		printf("Case %d: ", ii);
		solve();
	}
	return 0;
}
