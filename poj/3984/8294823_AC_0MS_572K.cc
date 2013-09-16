#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int map[5][5], dir[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 }, dis[25], pre[25], mark[25];
const int inf = 100;

struct Qnode {
	int u;
	int d;

	bool operator<(const Qnode & a) const {
		return a.d < d;
	}
} now;

void dijkstra(int s) {
	priority_queue<Qnode> Q;
	for (int i = 0; i < 25; i++) {
		pre[i] = -1;
		dis[i] = inf;
		mark[i] = 0;
	}
	dis[s] = 0;
	now.u = s;
	now.d = 0;
	Q.push(now);
	for (int k, i = 1; i < 25; i++) {
		do {
			if (Q.empty())
				return;
			now = Q.top();
			Q.pop();
			k = now.u;
		} while (mark[k]);
		mark[k] = 1;
		for (int j = 0; j < 4; j++) {
			int ii = k / 5 + dir[j][0];
			int jj = k % 5 + dir[j][1];
			if (ii < 0 || ii == 5 || jj < 0 || jj == 5 || map[ii][jj] == 1)
				continue;
			int x = ii * 5 + jj;
			if (!mark[x] && dis[x] > dis[k] + 1) {
				dis[x] = dis[k] + 1;
				pre[x] = k;
				now.u = x;
				now.d = dis[x];
				Q.push(now);
			}
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dijkstra(0);
	stack<int> S;
	int t = 24;
	while (pre[t] != -1) {
		S.push(t);
		t = pre[t];
	}
	S.push(0);
	while (!S.empty()) {
		t = S.top();
		S.pop();
		printf("(%d, %d)\n", t / 5, t % 5);
	}
	return 0;
}
