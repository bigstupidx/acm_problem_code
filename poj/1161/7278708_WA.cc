#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct edge {
	int to;
	int d;
	edge *next;
} edg[400010], *vert[500];

const int inf = 100000000;
int mm, n, m, dis[500], mark[500], flag[300];

struct QN {
	int u;
	int d;
	bool operator<(const QN &a)const {
		return a.d < d;
	}
} now;

void add_edge(int x, int y, int va, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x];	vert[x] = p;
}

void dijkstra(int s) {
	priority_queue <QN> Q;
	for (int i = 0; i <= n; i++) {
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
			if (!mark[p->to] && dis[p->to] > dis[k] + p->d) {
				dis[p->to] = dis[k] + p->d;
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
				//printf("%d -> %d %d\n", i, pre + m, 0);
				add_edge(i, pre + m, 0, top);
				add_edge(pre + m, i, 0, top);
			}

			for (int j = 1; j < mm; j++) {
				scanf("%d", &next);

				if (flag[next]) {
					//printf("%d -> %d %d\n", i, next + m, 0);
					add_edge(i, next + m, 0, top);
					add_edge(next + m, i, 0, top);
				}

				tem = next;
				if (pre > next) {
					tp = pre, pre = next, next = tp;
				}

				p = mp.find(make_pair(pre, next));
				if (p == mp.end()) {
					mp.insert(make_pair(make_pair(pre, next), i));
				}
				else {
					//printf("%d -> %d %d\n", i, p->second, 1);
					add_edge(i, p->second, 1, top);
					add_edge(p->second, i, 1, top);
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
				add_edge(i, p->second, 1, top);
				add_edge(p->second, i, 1, top);
			}
		}
		n = m + n;
		int ans = inf;
		for (int i = 0; i < m; i++) {
			dijkstra(i);
			int sum = 0;
			for (int j = m + 1; j <= n; j++) {
				//printf("%d ", dis[j]);
				if (flag[j - m ]) {
					sum += dis[j];
				}
			}
			//puts("");
			if (sum < ans)ans = sum;
		}
		printf("%d\n", ans);
	}
	return 0;
}
