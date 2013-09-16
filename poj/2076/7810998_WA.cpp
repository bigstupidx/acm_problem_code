#include <cstdio>
#include <cstring>
#define inf 100000000

using namespace std;

int n, m, dis[102][102], id[102], ans[102];

void solve() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (dis[i][k] == inf)continue;
			for (int j = 1; j <= n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	long long mini = 1LL << 60;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			long long total = 0, sum = 0;
			int cnt1 = 0, cnt2 = 0;
			for (int k = 1; k <= n; k++) {
				if (dis[k][i] > dis[k][j]) {
					sum += dis[k][j];
					id[k] = j;
					++cnt1;
				}
				else {
					sum += dis[k][i];
					id[k] = i;
					++cnt2;
				}
			}
			total = cnt1 * cnt2 * dis[i][j] + 2 * (n - 1) * sum;
			//printf("%d %d %lld\n", i, j, total);
			id[i] = 0, id[j] = 0;
			if (total < mini) {
				mini = total;
				for (int k = 1; k <= n; k++) {
					ans[k] = id[k];
				}
			}
			else if (total == mini) {
				bool flag = 0;
				for (int k = 1; k <= n; k++) {
					if (ans[k] > id[k]) {
						flag = true;
						break;
					}
				}
				if (flag) {
					for (int k = 1; k <= n; k++) {
						ans[k] = id[k];
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = inf;
			}
			dis[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			if (dis[x][y] > d) {
				dis[x][y] = d;
				dis[y][x] = d;
			}
		}
		solve();
	}
	return 0;
}
