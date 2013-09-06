#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

struct edge {
	int to;
	int d;
	edge *next;
} edg[20010], *vert[102];

const int inf = 1000000000;
int n, m, dis[102], pre[102], mark[102], ans, xx, yy, zz;

struct QN {
	int u;
	int d;

	bool operator<(const QN & a)const {
		return a.d < d;
	}
} now;

void add_edge(int x, int y, int va, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x];
	vert[x] = p;
}

void dijkstra(int s) {
	priority_queue<QN>Q;
	for (int i = 1; i <= n; i++) {
		dis[i] = inf;
		pre[i] = -1;
		mark[i] = 0;
	}
	now.u = s;
	now.d = 0;
	Q.push(now);
	dis[s] = 0;
	for (int k, i = 1; i < n; i++) {
		do {
			if (Q.empty())return;
			now = Q.top();
			Q.pop();
			k = now.u;
		} while (mark[k]);
		mark[k] = 1;
		for (edge *p = vert[k]; p; p = p->next) {
			if (dis[p->to] > dis[k] + p->d) {
				if (dis[p->to] != inf && pre[p->to] != k) {
					if (ans > dis[k] + p->d + dis[p->to]) {
						ans = dis[k] + p->d + dis[p->to];
						zz = p->to;
						xx = s;
						yy = k;
					}
				}
				pre[p->to] = k;
				dis[p->to] = dis[k] + p->d;
				now.u = p->to;
				now.d = dis[p->to];
				Q.push(now);
			} else if (pre[k] != p->to && ans > dis[k] + p->d + dis[p->to]) {
				ans = dis[k] + p->d + dis[p->to];
				zz = p->to;
				yy = k;
				xx = s;
			}
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < m; i++) {
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			add_edge(u, v, va, top);
			add_edge(v, u, va, top);
		}
		ans = inf;
		for (int i = 1; i <= n; i++) {
			dijkstra(i);
		}
		if (ans == inf)puts("No solution.");
		else {
			//printf("%d\n", ans);
			dijkstra(xx);
			queue<int>Q;
			while (pre[yy] != -1) {
				//printf("%d ", yy);
				Q.push(yy);
				yy = pre[yy];
			}
			Q.push(xx);
			stack<int>S;
			while (pre[zz] != -1) {
				//printf("%d ", zz);
				S.push(zz);
				zz = pre[zz];
			}
			while (!S.empty()) {
				Q.push(S.top());
				S.pop();
			}
			while (!Q.empty()) {
				printf("%d ", Q.front());
				Q.pop();
			}
			puts("");
		}
	}
	return 0;
}
