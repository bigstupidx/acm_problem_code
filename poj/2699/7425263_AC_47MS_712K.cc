#include <cstdio>
#include <queue>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge {
	int s, t, c, next;
} e[1000010];

int n, m, sc[12], head[100], pre[100];

char str[1002];

void add_edge(int x, int y, int va, int &top) {
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
		if (pre[t] == -1)return flow;
		int mini = 1000000;
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

void build_g(int s, int t, int mid) {
	int top = -1, k = n;
	memset(head, -1, sizeof (head));
	for (int i = 0; i < mid; i++) {
		for (int j = i + 1; j < n; j++) {
			add_edge(s, k, 1, top);
			add_edge(k, i, 1, top);
			add_edge(k, j, 1, top);
			k++;
		}
	}
	for (int i = mid; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			add_edge(s, k, 1, top);
			add_edge(k, i, 1, top);
			if (sc[j] == sc[i]) {
				add_edge(k, j, 1, top);
			}
			k++;
		}
	}
	for (int i = 0; i < n; i++) {
		add_edge(i, t, sc[i], top);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	getchar();
	while (nca--) {
		gets(str);
		string st(str);
		istringstream in(st);
		n = 0;
		while (in >> sc[n])n++;
		sort(sc, sc + n);
		int lf = 0, rt = n - 1;
		m = (n - 1) * n / 2;
		int s = n + m, t = s + 1;
		while (lf <= rt) {
			int mid = (lf + rt) / 2;
			build_g(s, t, mid);
			if (max_flow(s, t) == m) {
				rt = mid - 1;
			}
			else {
				lf = mid + 1;
			}
		}
		printf("%d\n", n - lf);
	}
	return 0;
}
