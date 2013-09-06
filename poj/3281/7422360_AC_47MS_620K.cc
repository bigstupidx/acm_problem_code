#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 502

using namespace std;

struct edge {
	int s, t, c, next;
} e[1000010];

const int inf = 1000000000;
int n, head[maxn], pre[maxn];

void add_edge(int x, int y, int va, int &top) {
	//printf("%d -> %d %d\n", x, y, va);
	e[++top].s = x;
	e[top].t = y;
	e[top].c = va;
	e[top].next = head[x];
	head[x] = top;

	e[++top].s = y;
	e[top].t = x;
	e[top].c = 0;
	e[top].next = head[y];
	head[y] = top;
}

int max_flow(int s, int t) {
	int flow = 0;
	while (1) {
		queue<int>Q;
		memset(pre, -1, sizeof (pre));
		Q.push(s);
		while (!Q.empty() && pre[t] == -1) {
			int i = Q.front();
			Q.pop();
			for (int j = head[i]; j != -1; j = e[j].next) {
				if (pre[e[j].t] == -1 && e[j].c > 0) {
					pre[e[j].t] = j;
					Q.push(e[j].t);
				}
			}
		}
		if (pre[t] == -1) {
			//printf("flow : %d \n", flow);
			return flow;
		}

		int mini = inf;
		for (int i = t; i != s; i = e[pre[i]].s) {
			if (mini > e[pre[i]].c) {
				mini = e[pre[i]].c;
			}
		}
		flow += mini;
		for (int i = t; i != s; i = e[pre[i]].s) {
			e[pre[i]].c -= mini;
			e[pre[i]^1].c += mini;
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, p;
	while (scanf("%d%d%d", &n, &m, &p) != EOF) {
		int top = -1;
		memset(head, -1, sizeof (head));
		for (int i = 0; i < n; i++) {
			add_edge(i, i + n, 1, top);
			int m1, m2, x;
			scanf("%d%d", &m1, &m2);
			for (int j = 0; j < m1; j++) {
				scanf("%d", &x);
				add_edge(2 * n + x - 1, i, 1, top);
			}
			for (int j = 0; j < m2; j++) {
				scanf("%d", &x);
				add_edge(i + n, 2 * n + m - 1 + x, 1, top);
			}
		}
		int s = 2 * n + m + p, t = s + 1;
		for (int i = 0; i < m; i++) {
			add_edge(s, 2 * n + i, 1, top);
		}
		for (int i = 0; i < p; i++) {
			add_edge(2 * n + m + i, t, 1, top);
		}
		printf("%d\n", max_flow(s, t));
	}
	return 0;
}
