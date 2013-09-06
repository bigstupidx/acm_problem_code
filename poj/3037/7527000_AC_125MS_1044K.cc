#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

double dis[10010], inf = 1e100, fic[52];
int n, m, v, mark[10010], gg[102][102];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

struct QN {
	int u;
	double v, t;

	bool operator<(const QN & a)const {
		return a.t < t;
	}
} now, next;

void pre_done() {
	fic[0] = 1;
	for (int i = 1; i < 51; i++) {
		fic[i] = fic[i - 1]*2;
	}
	return;
}

void dijkstra(int s, int N) {
	priority_queue <QN> Q;
	for (int i = 0; i < N; i++) {
		dis[i] = inf;
		mark[i] = 0;
	}
	now.u = s;
	now.t = 0;
	now.v = v;
	Q.push(now);
	dis[s] = 0;
	for (int k, i = 1; i < N; i++) {
		do {
			if (Q.empty())return;
			now = Q.top();
			Q.pop();
			k = now.u;
		} while (mark[k]);
		mark[k] = 1;
		int r = k / m;
		int c = k % m;
		double dd = now.v;
		double xx = 1 / dd;
		//printf("%d %lf %lf\n", now.u, now.v, now.t);
		for (int j = 0; j < 4; j++) {
			int ii = r + dir[j][0];
			int jj = c + dir[j][1];
			if (ii < 0 || ii == n || jj < 0 || jj == m)continue;
			int v = ii * m + jj;
			if (!mark[v] && dis[v] > dis[k] + xx) {
				dis[v] = dis[k] + xx;
				now.u = v;
				now.t = dis[v];
				int level = gg[r][c] - gg[ii][jj];
				if (level < 0) {
					now.v = dd / fic[-level];
				}
				else {
					now.v = dd * fic[level];
				}
				Q.push(now);
			}
		}
	}
}

int main() {
	pre_done();
	while (scanf("%d%d%d", &v, &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &gg[i][j]);
			}
		}
		dijkstra(0, n * m);
		printf("%.2f\n", dis[n * m - 1]);
	}
	return 0;
}
