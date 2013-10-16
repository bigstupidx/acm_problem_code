//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to, c, next;
} e[1000010];

int n, m, head[1200], L[1200], vert[1200];
const int inf = 1000000000;

inline void add_edge(int x, int y, int c, int &top) {
	e[++top].to = y;
	e[top].c = c;
	e[top].next = head[x], head[x] = top;

	e[++top].to = x;
	e[top].c = 0;
	e[top].next = head[y], head[y] = top;
}

int DFS(int s, int t, int nowFlow) {
	if (s == t)
		return nowFlow;
	int flow = 0;
	while (vert[s] != -1) {
		int j = vert[s];
		if (L[e[j].to] == L[s] + 1 && e[j].c > 0) {
			int temp = DFS(e[j].to, t, min(e[j].c, nowFlow));
			flow += temp;
			e[j].c -= temp;
			e[j ^ 1].c += temp;
			if (!(nowFlow -= temp))
				break;
		}
		vert[s] = e[j].next;
	}
	if (vert[s] == -1)
		L[s] = inf;
	return flow;
}

bool BFS(int s, int t) {
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		L[i] = inf;
		vert[i] = head[i];
	}
	Q.push(s);
	L[s] = 0;
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		if (L[i] >= L[t])
			break;
		for (int j = vert[i]; j != -1; j = e[j].next) {
			if (L[e[j].to] == inf && e[j].c > 0) {
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
	while (scanf("%d%d", &m, &n) != EOF) {
		int top = -1;
		memset(head, -1, sizeof(head));
		for (int i = 0; i < m; i++) {
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, d, top);
		}
		printf("%d\n", max_flow(1, n));
	}
	return 0;
}
