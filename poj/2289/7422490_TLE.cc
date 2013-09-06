#include <cstdio>
#include <queue>
#include <string>
#include <sstream>
#include <cstring>
#define maxn 1512

using namespace std;

struct edge {
	int s, t, c, f, next;
} e[1000010];

const int inf = 1000000000;
int n, m, head[maxn], pre[maxn];

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
				if (pre[e[j].t] == -1 && e[j].c > e[j].f) {
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
			if (mini > e[pre[i]].c - e[pre[i]].f) {
				mini = e[pre[i]].c - e[pre[i]].f;
			}
		}
		flow += mini;
		for (int i = t; i != s; i = e[pre[i]].s) {
			e[pre[i]].f += mini;
			e[pre[i]^1].f -= mini;
		}
	}
}

void build_g(int mid, int tot, int top) {
	for (int i = 0; i <= top; i++) {
		e[i].f = 0;
	}
	for (int i = tot; i <= top; i += 2) {
		e[i].c = mid;
	}
}
char str[2000];

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m) {
		getchar();
		int top = -1, s = n + m, t = s + 1;
		memset(head, -1, sizeof (head));
		for (int u, i = 0; i < n; i++) {
			gets(str);
			string st(str);
			istringstream in(st);
			in >> str;
			while (in >> u) {
				add_edge(i, n + u, 1, top);
			}
			add_edge(s, i, 1, top);
		}
		int tot = top + 1;
		for (int i = 0; i < m; i++) {
			add_edge(i + n, t, 1, top);
		}
		int lf = 0, rt = n, mid;
		while (lf <= rt) {
			mid = (lf + rt) / 2;
			build_g(mid, tot, top);
			if (max_flow(s, t) == n) {
				rt = mid - 1;
			}
			else {
				lf = mid + 1;
			}
		}
		printf("%d\n", lf);
	}
	return 0;
}
