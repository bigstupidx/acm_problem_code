#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	int d;
	edge *next;
} edg[400010], *vert[200010];

int n, deg[200010], flag[200010];
long long val[200010];

struct QN {
	int u;
	long long d;
	bool operator<(const QN & a)const {
		return a.d < d;
	}
} now, next;

void add_edge(int x, int y, int va, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x];	vert[x] = p;
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		int top = -1;
		scanf("%d", &n);

		memset(val, 0, sizeof (val));
		memset(deg, 0, sizeof (deg));

		memset(flag, 0, sizeof (flag));
		memset(vert, 0, sizeof (vert));
		for (int i = 1; i < n; i++) {
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			add_edge(x, y, d, top);
			add_edge(y, x, d, top);
			deg[x]++, deg[y]++;
		}
		int cnt = 0;
		priority_queue <QN> Q;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 1) {
				cnt++;
				now.u = i;
				now.d = 0;
				Q.push(now);
			}
		}
		while (!Q.empty()) {
			now = Q.top();
			Q.pop();
			int k = now.u;
			flag[k] = 1;
			for (edge *p = vert[k]; p; p = p->next) {
				if (!flag[p->to]) {
					if (p->d <= now.d || now.d == 0) {
						val[p->to] += p->d;
					}
					else if (now.d != 0) {
						val[p->to] += now.d;
					}
					if (--deg[p->to] == 1) {
						next.u = p->to;
						next.d = val[p->to];
						Q.push(next);
					}
				}
			}
		}
		printf("%lld\n", val[now.u]);
	}
	return 0;
}
