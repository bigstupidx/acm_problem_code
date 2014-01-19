#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct edge {
	int u;
	edge *next;
} e[404], *head, *tail, *p, *q;

int n, m, top;
bool gg[404][404], visit[404];

void insert_list(int i) {
	visit[i] = 1;
	for (int j = 1; j <= n; j++) {
		if (!visit[j] && gg[i][j]) {
			insert_list(j);
			break;
		}
	}
	e[top].u = i;
	e[top].next = head;
	head = &e[top];
	top++;
}

void hamilton() {
	memset(visit, 0, sizeof (visit));
	top = 0;
	head = tail = NULL;
	insert_list(1);
	for (p = head; p; tail = p, p = p->next);
	while (top < n || !gg[head->u][tail->u]) {
		//		for (p = head; p; p = p->next) {
		//			printf("%d ", p->u);
		//		}
		//		puts("");
		if (!gg[head->u][tail->u]) {
			for (p = head; p->next != NULL; p = p->next) {
				if (gg[p->u][tail->u] && gg[p->next->u][head->u]) {
					break;
				}
			}
			vector <int> tem;
			for (q = p->next; q; q = q->next) {
				tem.push_back(q->u);
			}
			for (int i = tem.size() - 1; i >= 0; i--) {
				q = p->next;
				q->u = tem[i];
				p = q;
			}
		}
		int k = -1;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				for (int j = 1; j <= n; j++) {
					if (visit[j] && gg[i][j]) {
						k = i;
						break;
					}
				}
				if (k != -1)break;
			}
		}
		if (k == -1)break;
		for (p = head; p; q = p, p = p->next) {
			if (gg[p->u][k]) {
				break;
			}
		}
		if (p == head) {
			insert_list(k);
		} else {
			tail->next = head;
			head = q->next;
			q->next = NULL;
			insert_list(k);
		}
	}
	for (p = head; p; p = p->next) {
		printf("%d ", p->u);
	}
	puts("");
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m) {

		memset(gg, true, sizeof (gg));
		for (int x, y, i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			gg[x][y] = gg[y][x] = 0;
		}
		n <<= 1;
		for (int i = 1; i <= n; i++) {
			gg[i][i] = 0;
		}
		if (n == 1)puts("1 2");
		else hamilton();
	}
	return 0;
}
