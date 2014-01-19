#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge {
	int to;
	int d;
	int id;
	edge *next;
} edg[2000100], *vert[2][10002];

long long inf = 1, dis[2][10002];
int n, m, mark[10002], k;

struct QN {
	int u;
	long long d;

	bool operator<(const QN & a)const {
		return d > a.d;
	}
} now;

void add_edge(int x, int y, int va, int i, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->id = i;
	p->next = vert[0][x];
	vert[0][x] = p;

	p = &edg[++top];
	p->to = x;
	p->d = va;
	p->id = i;
	p->next = vert[1][y];
	vert[1][y] = p;
}

void dijkstra(int s, int ii) {
	priority_queue<QN>Q;
	for (int i = 1; i <= n; i++) {
		dis[ii][i] = inf;
		mark[i] = 0;
	}
	now.u = s;
	now.d = 0;
	Q.push(now);
	dis[ii][s] = 0;
	for (int j, i = 1; i < n; i++) {
		do {
			if (Q.empty())return;
			now = Q.top();
			Q.pop();
			j = now.u;
		} while (mark[j]);
		mark[j] = 1;
		for (edge *p = vert[ii][j]; p; p = p->next) {
			if (!mark[p->to] && dis[ii][p->to] > dis[ii][j] + p->d) {
				dis[ii][p->to] = dis[ii][j] + p->d;
				now.u = p->to;
				now.d = dis[ii][p->to];
				Q.push(now);
			}
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	inf <<= 60;
	while (scanf("%d%d%d", &n, &m, &k) != EOF) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < m; i++) {
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			add_edge(u, v, va, i + 1, top);
		}
		dijkstra(1, 0);
		if (dis[0][n] == inf)puts("0");
		else {
			dijkstra(n, 1);
			vector <int> ans;
			long long dd = dis[0][n] + k + 1;
			for (int i = 1; i <= n; i++) {
				for (edge *p = vert[0][i]; p; p = p->next) {
					if (dis[0][i] + dis[1][p->to] + p->d < dd) {
						ans.push_back(p->id);
					}
				}
			}
			sort(ans.begin(), ans.end());
			printf("%d\n", ans.size());
			for (int i = 0; i < ans.size(); i++) {
				printf("%d\n", ans[i]);
			}
		}
	}
	return 0;
}
