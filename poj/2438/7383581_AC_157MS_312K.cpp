#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#define maxn 404

using namespace std;

struct edge {
	int v;
	edge *next;
} e[maxn], *head, *tail, *p, *q;

int n, m, top, que[maxn];
bool visit[maxn], gg[maxn][maxn];

void DFS(int s) {
	visit[s] = 1;
	for (int i = 1; i <= n; i++) {
		if (!visit[i] && gg[s][i]) {
			DFS(i);
			break;
		}
	}
	e[top].next = head;
	head = &e[top];
	e[top].v = s;
	top++;
}

void hamilton() {
	DFS(1);
	for (p = head; p; p = p->next)tail = p;
	while (top < n || !gg[head->v][tail->v]) {
		if (!gg[head->v][tail->v]) {
			int s = head->v, t = tail->v;
			for (p = head; p->next; p = p->next) {
				int x = p->next->v;
				if (gg[p->v][t] && gg[s][x]) {
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
		int k = -1, tot = 0;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				que[tot++] = i;
			}
		}
		for (p = head; p; q = p, p = p->next) {
			bool xflag = 0;
			for (int j = 0; j < tot; j++) {
				if (!visit[que[j]] && gg[p->v][que[j]]) {
					xflag = 1;
					k = que[j];
					break;
				}
			}
			if (xflag)break;
		}
		if (k == -1)break;
		if (p != head) {
			tail->next = head;
			head = q->next;
			q->next = NULL;
			tail = q;
		}
		DFS(k);
	}
	for (p = head; p; p = p->next) {
		printf("%d ", p->v);
	}
	puts("");
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m) {
		top = 0;
		head = NULL;
		memset(gg, true, sizeof (gg));
		memset(visit, 0, sizeof (visit));
		for (int x, y, i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			gg[x][y] = false;
			gg[y][x] = false;
		}
		n <<= 1;
		for (int i = 1; i <= n; i++) {
			gg[i][i] = false;
		}
		hamilton();
	}
	return 0;
}
