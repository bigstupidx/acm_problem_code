#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m, last, c[222][222], f[222][222], w[222][222], dis[222];
int flag[222], pre[222], cnt[222];
const int inf = 1000000000;

struct node {
	int x, y, c;
} a[102], b[102];

inline int ABS(int x) {
	return x > 0 ? x : -x;
}

bool spfa() {
	queue <int> Q;
	for (int i = 1; i <= n + m; i++) {
		dis[i] = inf;
		cnt[i] = 0;
		flag[i] = 1;
		Q.push(i);
	}
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		flag[i] = 0;
		for (int j = 1; j <= n + m; j++) {
			if (c[i][j] > f[i][j] && dis[j] > dis[i] + w[i][j]) {
				dis[j] = dis[i] + w[i][j];
				pre[j] = i;
				if (!flag[j]) {
					if (++cnt[j] > n + m) {
						last = j;
						return true;
					}
					flag[j] = 1;
					Q.push(j);
				}
			}
		}
	}
	return false;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(c, 0, sizeof (c));
		memset(f, 0, sizeof (f));
		memset(w, 0, sizeof (w));
		int s = 0, t = n + m + 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
			c[0][i] = a[i].c;
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].c);
			c[i + n][t] = b[i].c;
			for (int j = 1; j <= n; j++) {
				c[j][i + n] = inf;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int d, j = 1; j <= m; j++) {
				scanf("%d", &d);
				f[0][i] += d;
				f[i][0] -= d;
				f[i][j + n] += d;
				f[j + n][i] -= d;
				f[j + n][t] += d;
				f[t][j + n] -= d;
				d = ABS(a[i].x - b[j].x) + ABS(a[i].y - b[j].y) + 1;
				w[i][j + n] = d;
				w[j + n][i] = -d;
			}
		}
		if (spfa()) {
			puts("SUBOPTIMAL");
			memset(flag, 0, sizeof (flag));
			while (!flag[last]) {
				flag[last] = 1;
				last = pre[last];
			}
			memset(flag, 0, sizeof (flag));
			while (!flag[last]) {
				flag[last] = 1;
				++f[pre[last]][last];
				--f[last][pre[last]];
				last = pre[last];
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					printf("%d ", f[i][j + n]);
				}
				puts("");
			}
		}
		else {
			puts("OPTIMAL");
		}
	}
	return 0;
}
