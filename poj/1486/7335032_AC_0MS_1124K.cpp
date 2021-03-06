#include <cstdio>
#include <cstring>

struct node {
	int x1, y1, x2, y2;
} win[500];

int n, g[500][500], my[500], flag[500];

bool connect(int x, int y, int i) {
	if (win[i].x1 > x || x > win[i].x2)return false;
	if (win[i].y1 > y || y > win[i].y2)return false;
	return true;
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

bool max_match() {
	memset(my, -1, sizeof (my));
	for (int i = 0; i < n; i++) {
		memset(flag, 0, sizeof (flag));
		if (!path(i))return false;
	}
	return true;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca = 1;
	while (scanf("%d", &n), n) {

		for (int i = 0; i < n; i++) {
			scanf("%d%d%d%d", &win[i].x1, &win[i].x2, &win[i].y1, &win[i].y2);
		}
		memset(g, 0, sizeof (g));
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			for (int j = 0; j < n; j++) {
				if (connect(x, y, j)) {
					g[i][j] = 1;
				}
			}
		}
		printf("Heap %d\n", nca++);
		int xflag = 0;
		max_match();
		for (int i = 0; i < n; i++) {
			int s = my[i];
			my[i] = -1;
			memset(flag, 0, sizeof (flag));
			g[s][i] = 0;
			if (!path(s)) {
				xflag = 1;
				my[i] = s;
				printf("(%c,%d) ", i + 'A', s + 1);
			}
			g[s][i] = 1;
		}
		if (!xflag)printf("none");
		puts("\n");
	}
	return 0;
}
