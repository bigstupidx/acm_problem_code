#include <cstdio>
#include <cstring>

int n, m, g[202][202], my[202], flag[202];

bool path(int s) {
	for (int i = 1; i <= n; i++) {
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
	for (int i = 1; i <= n; i++) {
		memset(flag, 0, sizeof (flag));
		if (path(i))ans++;
	}
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		memset(g, 0, sizeof (g));
		scanf("%d%d", &n, &m);
		for (int x, y, i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			g[x][y] = 1;
		}
		printf("%d\n", n - max_match());
	}
	return 0;
}