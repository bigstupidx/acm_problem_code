#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	int d;
	char str[23];
	bool operator<(const node & a)const {
		if (a.d == d) {
			return strcmp(a.str, str) > 0;
		}
		return a.d > d;
	}
} nod[100010];

struct edge {
	int to;
	int d;
	bool operator<(const edge & a)const {
		return a.to < to;
	}
} now;
int n, m, top, maxi, path[22], visit[22];
vector <edge> front[22];

void DFS(int s, int t, int dep, int total) {
	if (total > maxi)return;
	visit[s] = 1;
	if (s == t) {
		nod[top].d = total;
		for (int i = 0; i < dep; i++) {
			nod[top].str[i] = path[i] + '0';
		}
		nod[top].str[dep] = t + '0';
		nod[top].str[dep + 1] = 0;
		top++;
	} else {
		path[dep] = s;
		for (int j = 0; j < front[s].size(); j++) {
			int to = front[s][j].to;
			if (!visit[to]) {
				DFS(to, t, dep + 1, total + front[s][j].d);
			}
		}
	}
	visit[s] = 0;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca = 1, xflag = 0;
	while (scanf("%d", &n), n != -1) {
		if (xflag)puts("");
		else xflag = 1;
		scanf("%d", &m);
		for (int i = 1; i <= n; i++)front[i].clear();
		for (int u, v, va, i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &va);
			now.to = v;
			now.d = va;
			front[u].push_back(now);
			now.to = u;
			front[v].push_back(now);
		}
		int s, t;
		scanf("%d%d%d", &s, &t, &maxi);
		top = 0;
		memset(visit, 0, sizeof (visit));
		DFS(s, t, 0, 0);
		printf("Case %d:\n", nca++);
		if (top == 0)puts(" NO ACCEPTABLE TOURS");
		else {
			sort(nod, nod + top);
			for (int i = 0; i < top; i++) {
				printf(" %d:", nod[i].d);
				for (int j = 0; nod[i].str[j]; j++) {
					printf(" %d", nod[i].str[j] - '0');
				}
				puts("");
			}
		}
	}
	return 0;
}

