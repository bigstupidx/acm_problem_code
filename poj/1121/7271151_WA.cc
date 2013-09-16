#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[10010], *vert[50], *r_vert[50];

char str[30];
int n, map[50][50], flag[50][2][30], order[50], id[50];
int top, visit[50], in[50], g[50][50];

vector <int> front[50];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];
	vert[x] = p;

	p = &edg[++top];
	p->to = x;
	p->next = r_vert[y];
	r_vert[y] = p;
}

void DFS(int s) {
	visit[s] = 1;
	for (edge *p = vert[s]; p; p = p->next) {
		if (!visit[p->to]) {
			DFS(p->to);
		}
	}
	order[top++] = s;
}

void DFS_RG(int s) {
	visit[s] = 1;
	id[s] = top;
	for (edge *p = r_vert[s]; p; p = p->next) {
		if (!visit[p->to]) {
			DFS_RG(p->to);
		}
	}
}

int main() {
	top=-1;
	scanf("%d", &n);
	for (int len, i = 1; i <= n; i++) {
		scanf("%s", str);
		if (strcmp(str, ".") != 0) {
			len = strlen(str);
			for (int j = 0; j < len; j++) {
				flag[i][0][str[j] - 'A'] = 1;
			}
		}
		scanf("%s", str);
		if (strcmp(str, ".") != 0) {
			len = strlen(str);
			for (int j = 0; j < len; j++) {
				flag[i][1][str[j] - 'A'] = 1;
			}
		}
	}
	int x, y;
	while (scanf("%d%d", &x, &y), x || y) {
		add_edge(x, y, top);
	}
	top = 1;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			DFS(i);
		}
	}

	top = 0;
	memset(visit, 0, sizeof (visit));
	for (int i = n; i > 0; i--) {
		if (!visit[order[i]]) {
			DFS_RG(order[i]);
			top++;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 30; j++) {
			if (flag[i][0][j]) {
				map[id[i]][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (edge *p = vert[i]; p; p = p->next) {
			if (id[i] != id[p->to] && !g[id[i]][id[p->to]]) {
				front[id[i]].push_back(id[p->to]);
				in[id[p->to]]++;
			}
		}
	}

	queue <int> Q;
	for (int i = 0; i < top; i++) {
		if (in[i] == 0) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		for (int j = 0; j < front[i].size(); j++) {
			int to = front[i][j];
			for (int k = 0; k < 30; k++) {
				if (!map[to][k] && map[i][k]) {
					map[to][k] = 1;
				}
			}
			if (--in[to] == 0) {
				Q.push(to);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf(":");
		for (int j = 0; j < 30; j++) {
			if (map[id[i]][j] && !flag[i][1][j]) {
				printf("%c", j + 'A');
			}
		}
		printf(":\n");
	}
	return 0;
}

