#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 10010

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[1000010], *vert[maxn];

int n, disx[maxn], disy[maxn], my[maxn], mx[maxn];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];
	vert[x] = p;
}

bool BFS() {
	queue<int>Q;
	memset(disx, 0, sizeof (disx));
	memset(disy, 0, sizeof (disy));
	for (int i = 1; i <= n; i++) {
		if (mx[i] == -1) {
			Q.push(i);
		}
	}
	bool xflag = false;
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		for (edge *p = vert[i]; p; p = p->next) {
			if (disy[p->to] == 0) {
				disy[p->to] = disx[i] + 1;
				if (my[p->to] == -1)xflag = true;
				else {
					disx[my[p->to]] = disy[p->to] + 1;
					Q.push(my[p->to]);
				}
			}
		}
	}
	return xflag;
}

bool path(int s) {
	for (edge *p = vert[s]; p; p = p->next) {
		if (disy[p->to] == disx[s] + 1) {
			disy[p->to] = 0;
			if (my[p->to] == -1 || path(my[p->to])) {
				my[p->to] = s;
				mx[s] = p->to;
				return true;
			}
		}
	}
	return false;
}

int max_match() {
	int ans = 0;
	memset(mx, -1, sizeof (mx));
	memset(my, -1, sizeof (my));
	while (BFS()) {
		for (int i = 1; i <= n; i++) {
			if (mx[i] == -1) {
				if (path(i))ans++;
			}
		}
	}
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < n; i++) {
			char ch;
			int u, v, m;
			scanf("%d", &u);
			u++;
			while ((ch = getchar()) != '(');
			scanf("%d", &m);
			while ((ch = getchar()) != ')');
			for (int j = 0; j < m; j++) {
				scanf("%d", &v);
				add_edge(u, v - n + 1, top);
			}
		}
		printf("%d\n", max_match());
	}
	return 0;
}
