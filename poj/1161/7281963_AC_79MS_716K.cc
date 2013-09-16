#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[200010], *vert[500];

const int inf = 100000000;
int mm, n, m, dis[500], mark[500], flag[300], cnt[252][202];

struct QN {
	int u;
	int d;
	bool operator<(const QN & a)const {
		return a.d < d;
	}
} now;

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];	vert[x] = p;
}

void dijkstra(int s) {
	priority_queue <QN> Q;
	for (int i = 0; i < n; i++) {
		dis[i] = inf;
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
			if (!mark[p->to] && dis[p->to] > dis[k] + 1) {
				dis[p->to] = dis[k] + 1;
				now.u = p->to;
				now.d = dis[p->to];
				Q.push(now);
			}
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d%d", &m, &n, &mm) != EOF) {

		memset(flag, 0, sizeof (flag));
		for (int x, i = 0; i < mm; i++) {
			scanf("%d", &x);
			cnt[x][0] = 0;
			flag[x] = 1;
		}

		int top = -1;
		memset(vert, 0, sizeof (vert));

		map <pair<int, int>, int> mp;
		map <pair<int, int>, int>::iterator p;

		for (int i = 0, id = 0; i < m; i++) {
			int pre, next, tem, tp, first;

			scanf("%d%d", &mm, &pre);

			first = pre;
			if (flag[pre]) {
				cnt[pre][++cnt[pre][0]] = i;
			}
			for (int j = 1; j < mm; j++) {
				scanf("%d", &next);

				tem = next;
				if (flag[tem]) {
					cnt[tem][++cnt[tem][0]] = i;
				}
				if (pre > next) {
					tp = pre, pre = next, next = tp;
				}

				p = mp.find(make_pair(pre, next));
				if (p == mp.end()) {
					mp.insert(make_pair(make_pair(pre, next), i));
				}
				else {
					//printf("%d -> %d %d\n", i, p->second, 1);
					add_edge(i, p->second, top);
					add_edge(p->second, i, top);
				}

				pre = tem;
			}
			if (first > pre) {
				tem = pre, pre = first, first = tem;
			}
			p = mp.find(make_pair(first, pre));
			if (p == mp.end()) {
				mp.insert(make_pair(make_pair(first, pre), i));
			}
			else {
				//printf("%d -> %d %d\n", i, p->second, 1);
				add_edge(i, p->second, top);
				add_edge(p->second, i, top);
			}
		}
		n = m + n;
		int ans = inf;
		for (int i = 0; i < m; i++) {
			dijkstra(i);
			int sum = 0;
			for (int j = 1; j <= n; j++) {
				if (flag[j]) {
					int mini = inf;
					for (int k = 1; k <= cnt[j][0]; k++) {
						if (mini > dis[cnt[j][k]]) {
							mini = dis[cnt[j][k]];
						}
					}
					sum += mini;
				}
			}
			if (sum < ans)ans = sum;
		}
		printf("%d\n", ans);
	}
	return 0;
}
