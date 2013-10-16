#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#define maxn 1000010

using namespace std;

long long dis[maxn << 1], inf;
int n, mark[maxn << 1], flag[maxn << 1], va[3][maxn];

struct QN {
	int u, i;
	long long d;

	bool operator<(const QN & a)const {
		return a.d < d;
	}
} now;

void dijkstra(int s, int t) {
	priority_queue <QN> Q;
	int m = n << 1;
	for (int i = 0; i < m; i++) {
		dis[i] = inf;
		mark[i] = 0;
	}
	now.u = s;
	now.i = s / n;
	now.d = 0;
	Q.push(now);
	dis[s] = 0;
	for (int k, i = 1; i < m; i++) {
		do {
			if (Q.empty())return;
			now = Q.top();
			Q.pop();
			k = now.u;
		} while (mark[k]);
		mark[k] = 1;
		if (k == t)return;
		int ii = now.i;
		int jj = k % n;
		if ((k < n && k > 0 || k >= n && k > n)) {
			if (!mark[k - 1] && dis[k - 1] > dis[k] + va[ii][jj - 1]) {
				dis[k - 1] = dis[k] + va[ii][jj - 1];
				now.u = k - 1;
				now.d = dis[k - 1];
				Q.push(now);
			}
		}
		if (k < n && k != n - 1 || k >= n && k != m - 1) {
			if (!mark[k + 1] && dis[k + 1] > dis[k] + va[ii][jj]) {
				dis[k + 1] = dis[k] + va[ii][jj];
				now.u = k + 1;
				now.d = dis[k + 1];
				Q.push(now);
			}
		}
		now.i = (ii + 1) % 2;
		if (k < n && !mark[k + n] && dis[k + n] > dis[k] + va[2][jj]) {
			dis[k + n] = dis[k] + va[2][jj];
			now.u = k + n;
			now.d = dis[k + n];
			Q.push(now);
		}
		else if (k > n && !mark[k - n] && dis[k - n] > dis[k] + va[2][jj]) {
			dis[k - n] = dis[k] + va[2][jj];
			now.u = k - n;
			now.d = dis[k - n];
			Q.push(now);
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	inf = 1LL << 63 - 1;
	//cout << inf << endl;
	while (scanf("%d", &n), n) {
		int s1, s2, t1, t2;
		scanf("%d%d%d%d", &s1, &s2, &t1, &t2);
		s1 = s1 * (n + 1) + s2;
		t1 = t1 * (n + 1) + t2;
		for (int i = 0; i < n; i++) {
			scanf("%d", &va[0][i]);
		}
		for (int i = 0; i < n + 1; i++) {
			scanf("%d", &va[2][i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &va[1][i]);
		}
		++n;
		dijkstra(s1, t1);
		//		puts("");
		//		for (int i = 0; i < n << 1; i++) {
		//			printf("%lld ", dis[i]);
		//		}
		//		puts("");
		printf("%lld\n", dis[t1]);
	}
	return 0;
}
