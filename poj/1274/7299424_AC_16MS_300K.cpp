#include <cstdio>
#include <cstring>

int n, m, g[202][202], my[202], flag[202], mx[202];

bool path(int s) {
	for (int i = 1; i <= m; i++) {
		if (!flag[i] && g[s][i]) {
			flag[i] = 1;
			if (my[i] == -1 || path(my[i])) {
				my[i] = s;
				mx[s] = i;
				return true;
			}
		}
	}
	return false;
}

int max_match() {
	int ans = 0;
	memset(mx, -1, sizeof (mx));
	memset(my, -1, sizeof (my));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j] && my[j] != -1) {
				my[j] = i;
				mx[i] = j;
				ans++;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(flag, 0, sizeof (flag));
		if (mx[i] == -1 && path(i))ans++;
	}
	return ans;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(g, 0, sizeof (g));
		for (int i = 1; i <= n; i++) {
			int mm, x;
			scanf("%d", &mm);
			for (int j = 0; j < mm; j++) {
				scanf("%d", &x);
				g[i][x] = 1;
			}
		}
		printf("%d\n", max_match());
	}
	return 0;
}