#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define inf 1000000000

using namespace std;

struct edge {
	int to, c, f, next;
} e[100010];

int n, head[402], vert[402], L[402];

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

int BFS(int s, int t) {
	queue <int> Q;
	for (int i = 1; i <= 2 * n; i++) {
		vert[i] = head[i];
		L[i] = inf;
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

int main() {
	int s, t;
	while (scanf("%d%d%d", &n, &s, &t) != EOF) {
		int top = -1;
		memset(head, -1, sizeof (head));
		for (int i = 1; i <= n; i++) {
			for (int d, j = 1; j <= n; j++) {
				scanf("%d", &d);
				if (d && i != j) {
					add_edge(i + n, j, inf, top);
				}
			}
			add_edge(i, i + n, 1, top);
		}
		int flow = max_flow(s + n, t);
		if (flow >= inf)puts("NO ANSWER!");
		else {
			printf("%d\n", flow);
			if (!flow)continue;
			vector <int> temp, ans;
			for (int i = 1; i <= n; i++) {
				if (i == s || i == t)continue;
				int xflag = 0;
				for (int j = head[i]; j != -1; j = e[j].next) {
					if (e[j].to == i + n) {
						if (e[j].c > e[j].f) {
							xflag = 1;
						}
						break;
					}
				}
				if (!xflag)temp.push_back(i);
			}
			for (int i = 0; i < temp.size(); i++) {
				int u = temp[i], xx;
				for (int j = 0; j <= top; j++)e[j].f = 0;
				for (int j = head[u]; j != -1; j = e[j].next) {
					if (e[j].to == u + n) {
						xx = j;
						e[j].c = 0;
						break;
					}
				}
				int nowFlow = max_flow(s + n, t);
				//printf("%d %d\n", u, nowFlow);
				if (nowFlow != flow) {
					flow = nowFlow;
					ans.push_back(u);
				}
				else {
					e[xx].c = 1;
				}
			}
			for (int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
			puts("");
		}
	}
	return 0;
}
