#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct edge {
	int v;
	edge *next;
} edg[404], *head, *tail, *p, *q;

int n, m, top;
bool visit[404], gg[404][404];

void DFS(int i) {
	visit[i] = true;
	for (int j = 1; j <= n; j++) {
		if (!visit[j] && gg[i][j]) {
			DFS(j);
			break;
		}
	}
	edg[top].next = head;
	head = &edg[top];
	edg[top].v = i;
	top++;
}

void hamilton() {
	top = 0;
	head = NULL;
	memset(visit, 0, sizeof (visit));
	DFS(1);
	for (p = head; p; p = p->next) {
		tail = p;
	}
	while (top < n || !gg[head->v][tail->v]) {
		if (!gg[head->v][tail->v]) {
			int s = head->v, t = tail->v;
			for (p = head; p; p = p->next) {
				if (gg[p->v][t] && gg[p->next->v][s]) {
					break;
				}
			}
			vector <int> tem;
			for (q = p->next; q; q = q->next) {
				tem.push_back(q->v);
			}
			for (int i = tem.size() - 1; i >= 0; i--) {
				p = p->next;
				p->v = tem[i];
			}
		}
		if (top == n)break;
		int k = -1;
		for (int i = 1; i <= n; i++) {
			if (visit[i])continue;
			int xflag = 0;
			for (int j = 1; j <= n; j++) {
				if (visit[j]) {
					xflag = 1;
					k = i;
					break;
				}
			}
			if (xflag)break;
		}
		for (p = head; p; q = p, p = p->next) {
			if (gg[k][p->v]) {
				break;
			}
		}
		if (p == head)DFS(k);
		else {
			tail->next = head;
			head = q->next;
			q->next = NULL;
			tail = q;
			DFS(k);
		}
	}
	for (p = head; p; p = p->next) {
		printf("%d ", p->v);
	}
	puts("");
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m) {
		memset(gg, true, sizeof (gg));
		for (int x, y, i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			gg[x][y] = false;
			gg[y][x] = false;
		}
		n <<= 1;
		for (int i = 1; i <= n; i++) {
			gg[i][i] = false;
		}
		if (n == 2)puts("1 2");
		else hamilton();
	}
	return 0;
}
