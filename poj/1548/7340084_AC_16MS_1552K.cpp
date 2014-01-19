#include <cstdio>
#include <cstring>

struct node {
	int x, y;
} nod[600];

int n, g[600][600], my[600], flag[600];

bool check(int i, int j) {
	if (nod[j].x >= nod[i].x && nod[j].y >= nod[i].y)return true;
	return false;
}

bool path(int s) {
	for (int i = 0; i < n; i++) {
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
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &nod[0].x, &nod[0].y) != EOF) {
		if (nod[0].x == -1 && nod[0].y == -1)break;
		if (nod[0].x == 0 && nod[0].y == 0) {
			puts("0");
			continue;
		}
		n = 1;
		while (scanf("%d%d", &nod[n].x, &nod[n].y) == 2) {
			if (nod[n].x == 0 && nod[n].y == 0)break;
			n++;
		}
		memset(g, 0, sizeof (g));
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (check(i, j))g[i][j] = 1;
				else if (check(j, i))g[j][i] = 1;
			}
		}
		printf("%d\n", n - max_match());
	}
	return 0;
}
