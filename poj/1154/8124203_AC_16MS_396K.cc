#include <cstdio>
#include <cstring>

using namespace std;

bool flag[30];
int n, m, dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1}, best;

char map[21][21];

void DFS(int i, int j, int dep) {
	if (dep > best)
		best = dep;
	flag[map[i][j] - 'A'] = true;
	for (int k = 0; k < 4; k++) {
		int ii = i + dir[k][0];
		int jj = j + dir[k][1];
		if (ii < 0 || ii >= n || jj < 0 || jj >= m || flag[map[ii][jj] - 'A'])
			continue;
		DFS(ii, jj, dep + 1);
	}
	flag[map[i][j] - 'A'] = false;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s", map[i]);
		}
		best = 0;
		memset(flag, 0, sizeof (flag));
		DFS(0, 0, 1);
		printf("%d\n", best);
	}
	return 0;
}
