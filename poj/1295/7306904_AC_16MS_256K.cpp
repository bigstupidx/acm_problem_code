#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[10010], *vert[22];

vector <string> arr[22];
int n, out[22], visit[22];
char str[3][22], name[22][22];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];	vert[x] = p;
}

void DFS(int s, int t1, int t2) {
	visit[s] = 1;
	if (out[s] < t1) {
		arr[s].push_back(str[0]);
	} else if (out[s] < t2) {
		arr[s].push_back(str[1]);
	} else {
		arr[s].push_back(str[2]);
	}
	for (edge *p = vert[s]; p; p = p->next) {
		if (!visit[p->to]) {
			DFS(p->to, t1, t2);
		}
	}
}

int main() {
	while (scanf("%d", &n), n) {
		int top = -1;
		memset(out, 0, sizeof (out));
		memset(vert, 0, sizeof (vert));
		for (int v, i = 1; i <= n; i++) {
			while (scanf("%d", &v), v) {
				add_edge(i, v, top);
				out[i]++;
			}
			arr[i].clear();
		}
		int s, t1, t2;
		while (scanf("%d", &s), s) {
			scanf("%d%d", &t1, &t2);
			scanf("%s%s%s", str[0], str[1], str[2]);
			memset(visit, 0, sizeof (visit));
			DFS(s, t1, t2);
			for (int i = 1; i <= n; i++) {
				if (!visit[i]) {
					arr[i].push_back(str[0]);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			scanf("%s", str[0]);
			printf("%s:", str[0]);
			for (int j = 0; j < arr[i].size(); j++) {
				cout << " " << arr[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
