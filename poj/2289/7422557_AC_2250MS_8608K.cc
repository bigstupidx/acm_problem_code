#include <cstdio>
#include <queue>
#include <string>
#include <sstream>
#include <cstring>
#define maxn 1512

using namespace std;

struct edge {
	int to, c, f, next;
} e[1000010];

const int inf = 1000000000;
int n, m, head[maxn], L[maxn], p[maxn][2];

void add_edge(int x, int y, int va, int &top) {
	//printf("%d -> %d %d\n", x, y, va);
	e[++top].to = y;
	e[top].c = va;
	e[top].next = head[x];
	head[x] = top;

	e[++top].to = x;
	e[top].c = 0;
	e[top].next = head[y];
	head[y] = top;
}

int max_flow(int s, int t) {
	int flow = 0;
	while (1) {
		queue<int>Q;
		memset(L, -1, sizeof (L));
		Q.push(s);
		L[s] = 0;
		while (!Q.empty()) {
			int i = Q.front();
			Q.pop();
			for (int j = head[i]; j != -1; j = e[j].next) {
				if (L[e[j].to] == -1 && e[j].c > e[j].f) {
					L[e[j].to] = L[i] + 1;
					Q.push(e[j].to);
				}
			}
		}
		if (L[t] == -1) {
			//printf("flow : %d\n", flow);
			return flow;
		}
		int top = 0;
		p[0][0] = s;
		p[0][1] = head[s];
		while (top >= 0) {
			if (p[top][0] != t) {
				while (p[top][1] >= 0) {
					int j = p[top][1];
					if (L[e[j].to] > L[p[top][0]] && e[j].c > e[j].f) {
						p[top + 1][0] = e[j].to;
						p[top + 1][1] = head[e[j].to];
						top++;
						break;
					}
					p[top][1] = e[j].next;
				}
				if (p[top][1] < 0) {
					if (--top < 0)break;
					p[top][1] = e[p[top][1]].next;
				}
			}
			else {
				int mini = 100000000, k;
				for (int i = 0; i < top; i++) {
					if (mini > e[p[i][1]].c - e[p[i][1]].f) {
						mini = e[p[i][1]].c - e[p[i][1]].f;
						k = i;
					}
				}
				flow += mini;
				for (int i = 0; i < top; i++) {
					e[p[i][1]].f += mini;
					e[p[i][1]^1].f -= mini;
				}
				top = k;
				p[top][1] = e[p[top][1]].next;
			}
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
