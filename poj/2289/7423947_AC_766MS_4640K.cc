#include <cstdio>
#include <queue>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[2000010], *vert[1002];

int n, m, my[502][1002], flag[502];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];
	vert[x] = p;
}

bool path(int s, int mid) {
	for (edge *p = vert[s]; p; p = p->next) {
		if (!flag[p->to]) {
			flag[p->to] = 1;
			if (my[p->to][0] < mid) {
				my[p->to][++my[p->to][0]] = s;
				return true;
			}
			else {
				for (int i = 1; i <= mid; i++) {
					if (path(my[p->to][i], mid)) {
						my[p->to][i] = s;
						return true;
					}
				}
			}
		}
	}
	return false;
}

int multi_max_match(int mid) {
	int ans = 0;
	for (int i = 0; i < m; i++)my[i][0] = 0;
	for (int i = 0; i < n; i++) {
		memset(flag, 0, sizeof (flag));
		if (path(i, mid))ans++;
	}
	//printf("match: %d\n", ans);
	return ans;
}

char str[2002];

int main() {
	while (scanf("%d%d", &n, &m), n || m) {
		getchar();
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int v, i = 0; i < n; i++) {
			gets(str);
			string st(str);
			istringstream in(st);
			in >> str;
			while (in >> v) {
				add_edge(i, v, top);
			}
		}
		int lf = 0, rt = n;
		while (lf <= rt) {
			int mid = (lf + rt) / 2;
			if (multi_max_match(mid) == n) {
				rt = mid - 1;
			}
			else lf = mid + 1;
		}
		printf("%d\n", lf);
	}
	return 0;
}
