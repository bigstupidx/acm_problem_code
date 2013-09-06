#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to, c, w, next;
} e[20010];

long long dis[1002], inf = 1LL << 60;
int n, m, head[1002], flag[1002], pre[1002];

inline void add_edge(int x, int y, int w, int &top) {
	e[++top].to = y;
	e[top].c = 1;
	e[top].w = w;
	e[top].next = head[x], head[x] = top;

	e[++top].to = x;
	e[top].c = 1;
	e[top].w = -w;
	e[top].next = head[y], head[y] = top;
}

void spfa(int s) {
	queue <int> Q;
	for (int i = 1; i <= n; ++i) {
		dis[i] = inf;
		flag[i] = 0;
	}
	Q.push(s);
	dis[s] = 0;
	flag[s] = 1;
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		for (int j = head[i]; j != -1; j = e[j].next) {
			if (e[j].c > 0 && dis[e[j].to] > dis[i] + e[j].w) {
				dis[e[j].to] = dis[i] + e[j].w;
				pre[e[j].to] = j;
				if (!flag[e[j].to]) {
					flag[e[j].to] = 1;
					Q.push(e[j].to);
				}
			}
		}
		flag[i] = 0;
	}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		int top = -1;
		memset(head, -1, sizeof (head));
		for (int i = 0; i < m; ++i) {
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, d, top);
		}
		long long ans = 0;
		for (int ii = 0; ii < 2; ++ii) {
			spfa(1);
			for (int i = n; i != 1; i = e[pre[i]^1].to) {
				--e[pre[i]].c;
				++e[pre[i]^1].c;
			}
			ans += dis[n];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
