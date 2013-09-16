//============================================================================
// Name        : algorithm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 1200
#define MAXM 1000010

using namespace std;

struct edge {
	int to, c, next;
} e[MAXM];

int n, m, head[MAXN], vert[MAXN], L[MAXN];
const int inf = 1000000000;

//添加x-〉y，容量为c的边
void add_edge(int x, int y, int c, int &top) {
	e[++top].to = y;
	e[top].c = c;
	e[top].next = head[x], head[x] = top;

	e[++top].to = x;
	e[top].c = 0;
	e[top].next = head[y], head[y] = top;
}

//dinic的精髓在从当前顶点出发一次或多次dfs到t，再将流量合并
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
			if ((nowFlow -= temp) == 0) {
				break;
			}
		}
		vert[s] = e[j].next;
	}
	if (vert[s] == -1)
		L[s] = inf;
	return flow;
}

//建立分层网络，从源点s出发bfs过程
//vert数组是head数组的拷贝，在dfs中起删边优化作用
//L数组就是分层数组
bool BFS(int s, int t) {
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		vert[i] = head[i];
		L[i] = inf;
	}
	L[s] = 0;
	Q.push(s);
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		if (L[i] >= L[t])
			break;
		for (int j = head[i]; j != -1; j = e[j].next) {
			if (L[e[j].to] == inf && e[j].c > 0) {
				L[e[j].to] = L[i] + 1;
				Q.push(e[j].to);
			}
		}
	}
	return L[t] != inf;
}

//dinic的思想是每次建立分层网络，在分层网络上流多次
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
		//n个顶点，m条边，每条边为u-〉v，容量为c
		for (int i = 0; i < m; i++) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			add_edge(u, v, c, top);
		}
		//源点为1，汇点为n
		printf("%d\n", max_flow(1, n));
	}
	return 0;
}
