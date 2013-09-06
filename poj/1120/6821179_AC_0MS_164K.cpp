#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, arrD[20], map[2][22][22];
int flag[404], dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 16; i++) {
		scanf("%d", &arrD[i]);
	}

	//		memset(map, 0, sizeof (map));
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			scanf("%d", &map[0][i][j]);
		}
	}

	int now = 0;
	queue<int>Q;
	for (int i = 0; i < n; i++) {
		memset(flag, 0, sizeof (flag));
		for (int ii = 0; ii < 20; ii++) {
			for (int jj = 0; jj < 20; jj++) {
				if (map[now][ii][jj] != 0) {
					if (!flag[ii * 20 + jj]) {
						flag[ii * 20 + jj] = 1;
						Q.push(ii * 20 + jj);
					}
					for (int j = 0; j < 4; j++) {
						int x = ii + dir[j][0];
						int y = jj + dir[j][1];
						if (x >= 0 && x < 20 && y < 20 && y >= 0) {
							if (!flag[(x = x * 20 + y)]) {
								flag[x] = 1;
								Q.push(x);
							}
						}
					}
				}
			}
		}
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			int i = x / 20;
			int j = x % 20;
			int sum = map[now][i][j];
			for (int k = 0; k < 4; k++) {
				int ii = i + dir[k][0];
				int jj = j + dir[k][1];
				if (ii >= 0 && ii < 20 && jj < 20 && jj >= 0) {
					sum += map[now][ii][jj];
				}
			}
			if (arrD[sum] + map[now][i][j] < 0)map[1 - now][i][j] = 0;
			else if (arrD[sum] + map[now][i][j] > 3)map[1 - now][i][j] = 3;
			else map[1 - now][i][j] = map[now][i][j] + arrD[sum];
			//				printf("%d %d %d %d\n", sum, i, j, map[1 - now][i][j]);
		}
		//			puts("");
		now = 1 - now;
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[now][i][j] == 0)
				putchar('.');
			else if (map[now][i][j] == 1)
				putchar('!');
			else if (map[now][i][j] == 2)
				putchar('X');
			else
				putchar('#');
		}
		puts("");
	}
	return 0;
}
