#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to, c, f, next;
} e[100010];

const int inf = 2147483647;
int n, m, up[202][22], down[202][22], head[250], L[250], vert[250], in[22];

inline void add_edge(int x, int y, int c, int &top) {
	//printf("%d -> %d %d\n", x, y, c);
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
		if (L[i] > L[t])break;
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
	//printf("%d\n", flow);
	return flow;
}

char str[3];

int main() {
	int nca;
	scanf("%d", &nca);
	int yflag = 0;
	while (nca--) {
		if (yflag)puts("");
		else yflag = 1;
		scanf("%d%d", &n, &m);
		int s = 0, t = n + m + 1, top = -1, mm;
		int sum = 0, ss = t + 1, tt = ss + 1;
		memset(head, -1, sizeof (head));
		memset(down, 0, sizeof (down));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				up[i][j] = inf;
			}
		}
		int ysum = 0;
		for (int d, i = 1; i <= n; i++) {
			scanf("%d", &d);
			sum += d, ysum += d;
			add_edge(ss, i, d, top);
		}
		add_edge(s, tt, ysum, top);
		ysum = 0;
		for (int d, i = 1; i <= m; i++) {
			scanf("%d", &d);
			sum += d, ysum += d;
			add_edge(i + n, tt, d, top);
		}
		add_edge(ss, t, ysum, top);
		scanf("%d", &mm);
		bool flag = false;
		for (int r, c, d, i = 0; i < mm; i++) {
			scanf("%d%d%s%d", &r, &c, str, &d);
			if (flag)continue;
			if (r == 0 && c != 0) {
				for (int j = 1; j <= n; j++) {
					if (str[0] == '<') {
						if (down[j][c] >= d) {
							flag = true;
							break;
						}
						else if (up[j][c] > d - 1) {
							up[j][c] = d - 1;
						}
					}
					else if (str[0] == '=') {
						if (down[j][c] > d || up[j][c] < d) {
							flag = true;
							break;
						}
						else {
							up[j][c] = down[j][c] = d;
						}
					}
					else {
						if (up[j][c] <= d) {
							flag = true;
							break;
						}
						else if (down[j][c] <= d + 1) {
							down[j][c] = d + 1;
						}
					}
				}
			}
			else if (c == 0 && r != 0) {
				for (int j = 1; j <= m; j++) {
					if (str[0] == '<') {
						if (down[r][j] >= d) {
							flag = true;
							break;
						}
						else if (up[r][j] > d - 1) {
							up[r][j] = d - 1;
						}
					}
					else if (str[0] == '=') {
						if (down[r][j] > d || up[r][j] < d) {
							flag = true;
							break;
						}
						else {
							up[r][j] = down[r][j] = d;
						}
					}
					else {
						if (up[r][j] <= d) {
							flag = true;
							break;
						}
						else if (down[r][j] <= d + 1) {
							down[r][j] = d + 1;
						}
					}
				}
			}
			else if (c == 0 && r == 0) {
				for (int j = 1; j <= n; j++) {
					for (int k = 1; k <= m; k++) {
						if (str[0] == '<') {
							if (down[j][k] >= d) {
								flag = true;
								break;
							}
							else if (up[j][k] > d - 1) {
								up[j][k] = d - 1;
							}
						}
						else if (str[0] == '=') {
							if (up[j][k] < d || down[j][k] > d) {
								flag = true;
								break;
							}
							else {
								up[j][k] = down[j][k] = d;
							}
						}
						else {
							if (up[j][k] <= d) {
								flag = true;
								break;
							}
							else if (down[j][k] <= d + 1) {
								down[j][k] = d + 1;
							}
						}
					}
				}
			}
			else {
				if (str[0] == '<') {
					if (down[r][c] >= d) {
						flag = true;
					}
					else if (up[r][c] > d - 1) {
						up[r][c] = d - 1;
					}
				}
				else if (str[0] == '=') {
					if (up[r][c] < d || down[r][c] > d) {
						flag = true;
					}
					else {
						up[r][c] = down[r][c] = d;
					}
				}
				else {
					if (up[r][c] <= d) {
						flag = true;
					}
					else if (down[r][c] <= d + 1) {
						down[r][c] = d + 1;
					}
				}
			}
		}
		//		for (int i = 1; i <= n; i++) {
		//			for (int j = 1; j <= m; j++) {
		//				printf("%.2d.%.2d  ", down[i][j], up[i][j]);
		//			}
		//			puts("");
		//		}
		if (flag) {
			puts("IMPOSSIBLE");
		}
		else {
			memset(in, 0, sizeof (in));
			for (int i = 1; i <= n; i++) {
				ysum = 0;
				for (int j = 1; j <= m; j++) {
					sum += down[i][j];
					ysum += down[i][j];
					in[j] += down[i][j];
					if (up[i][j] < down[i][j]) {
						flag = true;
					}
					if (up[i][j] > down[i][j]) {
						add_edge(i, j + n, up[i][j] - down[i][j], top);
					}
				}
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
