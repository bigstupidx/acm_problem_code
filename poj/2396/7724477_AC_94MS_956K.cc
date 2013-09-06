#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to, c, f, next;
} e[100010];

int n, m, up[202][22], down[202][252], head[250], L[250], vert[250], in[22];
const int inf = 1000000000;

inline void add_edge(int x, int y, int c, int &top) {
	e[++top].to = y;
	e[top].c = c;
	e[top].f = 0;
	e[top].next = head[x], head[x] = top;

	e[++top].to = x;
	e[top].c = 0;
	e[top].f = 0;
	e[top].next = head[y], head[y] = top;
}

int DFS(int s, int t, int nowFlow) {
	if (s == t)return nowFlow;
	int flow = 0;
	while (vert[s] != -1) {
		int j = vert[s];
		if (L[e[j].to] == L[s] + 1 && e[j].c > e[j].f) {
			int temp = DFS(e[j].to, t, min(e[j].c - e[j].f, nowFlow));
			flow += temp;
			e[j].f += temp;
			e[j^1].f -= temp;
			if (!(nowFlow -= temp))break;
		}
		vert[s] = e[j].next;
	}
	if (vert[s] == -1)L[s] = inf;
	return flow;
}

bool BFS(int s, int t) {
	queue <int> Q;
	for (int i = 0; i <= t; i++) {
		L[i] = inf;
		vert[i] = head[i];
	}
	L[s] = 0;
	Q.push(s);
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		if (L[i] >= L[t])break;
		for (int j = head[i]; j != -1; j = e[j].next) {
			if (L[e[j].to] == inf && e[j].c > e[j].f) {
				L[e[j].to] = L[i] + 1;
				Q.push(e[j].to);
			}
		}
	}
	return L[t] != inf;
}

int max_flow(int s, int t) {
	int flow = 0;
	while (BFS(s, t)) {
		flow += DFS(s, t, inf);
	}
	return flow;
}

bool adjust(int r, int c, char ch, int d) {
	if (ch == '<') {
		if (down[r][c] >= d) {
			return false;
		}
		if (up[r][c] > d - 1) {
			up[r][c] = d - 1;
		}
	}
	else if (ch == '=') {
		if (up[r][c] < d || down[r][c] > d) {
			return false;
		}
		up[r][c] = down[r][c] = d;
	}
	else {
		if (up[r][c] <= d) {
			return false;
		}
		if (down[r][c] < d + 1) {
			down[r][c] = d + 1;
		}
	}
	return true;
}

char str[4];

int main() {
	int nca, xflag = 0;
	scanf("%d", &nca);
	while (nca--) {

		if (xflag)puts("");
		else xflag = 1;

		scanf("%d%d", &n, &m);
		int top = -1, s = 0, t = n + m + 1;
		int ss = t + 1, tt = ss + 1;

		memset(head, -1, sizeof (head));
		memset(down, 0, sizeof (down));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				up[i][j] = inf;
			}
		}
		int xsum = 0, ysum = 0;
		for (int d, i = 1; i <= n; i++) {
			scanf("%d", &d);
			xsum += d;
			add_edge(ss, i, d, top);
		}
		add_edge(s, tt, xsum, top);
		for (int d, i = 1; i <= m; i++) {
			scanf("%d", &d);
			ysum += d;
			add_edge(i + n, tt, d, top);
		}
		add_edge(ss, t, ysum, top);

		bool flag = false;
		int sum = xsum + ysum, mm;
		if (xsum != ysum)flag = true;

		scanf("%d", &mm);
		for (int r, c, d, i = 0; i < mm; i++) {
			scanf("%d%d%s%d", &r, &c, str, &d);
			if (flag)continue;
			if (r == 0 && c != 0) {
				for (int j = 1; j <= n; j++) {
					if (!adjust(j, c, str[0], d)) {
						flag = true;
					}
				}
			}
			else if (c == 0 && r != 0) {
				for (int j = 1; j <= m; j++) {
					if (!adjust(r, j, str[0], d)) {
						flag = true;
					}
				}
			}
			else if (c == 0 && r == 0) {
				for (int j = 1; j <= n; j++) {
					for (int k = 1; k <= m; k++) {
						if (!adjust(j, k, str[0], d)) {
							flag = true;
						}
					}
				}
			}
			else {
				if (!adjust(r, c, str[0], d)) {
					flag = true;
				}
			}
		}
		if (flag) {
			puts("IMPOSSIBLE");
		}
		else {
			memset(in, 0, sizeof (in));
			for (int i = 1; i <= n; i++) {
				ysum = 0;
				for (int j = 1; j <= m; j++) {
					ysum += down[i][j];
					in[j] += down[i][j];
					if (up[i][j] < down[i][j]) {
						flag = true;
					}
					if (up[i][j] > down[i][j]) {
						add_edge(i, j + n, up[i][j] - down[i][j], top);
					}
				}
				sum += ysum;
				if (ysum)add_edge(i, tt, ysum, top);
			}
			for (int i = 1; i <= m; i++) {
				add_edge(ss, i + n, in[i], top);
			}
			add_edge(t, s, inf, top);
			if (flag || max_flow(ss, tt) != sum) {
				puts("IMPOSSIBLE");
				continue;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = head[i]; j != -1; j = e[j].next) {
					if (e[j].to > n) {
						down[i][e[j].to - n] += e[j].f;
					}
				}
				for (int j = 1; j <= m; j++) {
					printf("%d ", down[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}