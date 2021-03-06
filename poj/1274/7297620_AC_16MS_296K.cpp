#include <cstdio>
#include <cstring>

int n, m, g[202][202], flag[202], my[202];

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
	for (int i = 0; i < n; i++) {
		memset(flag, 0, sizeof (flag));
		if (path(i))ans++;
	}
	return ans;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(g, 0, sizeof (g));
		for (int i = 0; i < n; i++) {
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
