#include <cstdio>
#include <cstring>

using namespace std;

int n, m, g[102][102], my[102], flag[102];

bool path(int s) {
	for (int i = 0; i < m; i++) {
		if (!flag[i] && g[s][i]) {
			flag[i] = 1;
			if (my[i] == -1 || path(my[i])) {
				my[i] = s;
				return true;
			}
		}
	}
	return false;
}

int max_match() {
	int ans = 0;
	memset(my, -1, sizeof (my));
	for (int i = 0; i < n; i++) {
		memset(flag, 0, sizeof (flag));
		if (path(i))ans++;
	}
	return ans;
}

int main() {
	while (scanf("%d", &n), n) {
		int mm;
		scanf("%d%d", &m, &mm);
		memset(g, 0, sizeof (g));
		for (int i = 0; i < mm; i++) {
			int ii, x, y;
			scanf("%d%d%d", &ii, &x, &y);
			if (x == 0 || y == 0)continue;
			g[x][y] = 1;
		}
		printf("%d\n", max_match());
	}
	return 0;
}
