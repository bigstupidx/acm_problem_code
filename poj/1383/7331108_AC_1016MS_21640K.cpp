#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 1000010

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[2 * maxn], *vert[maxn];

char str[1002][1002];
int n, m, deg[maxn], dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int que[2][maxn], mark[maxn];
bool visit[maxn];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];	vert[x] = p;
}

void DFS(int s, bool ff) {
	mark[s] = 1;
	visit[s] = ff;
	for (edge *p = vert[s]; p; p = p->next) {
		if (!mark[p->to]) {
			if (!ff || !visit[p->to]) {
				DFS(p->to, false);
			} else {
				DFS(p->to, true);
			}
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	while (nca--) {

		scanf("%d%d", &m, &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
		}
		int top = -1;
		memset(deg, 0, sizeof (deg));
		memset(mark, 0, sizeof (mark));
		memset(vert, 0, sizeof (vert));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str[i][j] == '.') {
					for (int k = 0; k < 4; k++) {
						int ii = dir[k][0] + i;
						int jj = dir[k][1] + j;
						if (ii < 0 || ii == n || jj == m || jj < 0)continue;
						if (str[ii][jj] == '.') {
							add_edge(i * m + j, ii * m + jj, top);
							deg[i * m + j]++;
						}
					}
				}
			}
		}
		n = n * m - 1, top = 0;
		memset(visit, false, sizeof (visit));
		for (int i = 0; i < n; i++) {
			if (deg[i] == 1) {
				mark[i] = 1;
				visit[i] = true;
				que[0][top++] = i;
			}
		}
		int now = 0, cnt = 0;
		while (top > 1) {
			int tot = 0;
			for (int i = 0; i < top; i++) {
				deg[que[now][i]] = 0;
				//printf("%d ", que[now][i]);
				for (edge *p = vert[que[now][i]]; p; p = p->next) {
					if (!mark[p->to]) {
						if (--deg[p->to] == 1) {
							mark[p->to] = 1;
							visit[p->to] = true;
							que[1 - now][tot++] = p->to;
						} else {
							visit[que[now][i]] = false;
						}
					}
				}
			}
			//puts("");
			now = 1 - now;
			top = tot;
			cnt++;
			if (tot == 0) {
				top--;
				memset(mark, 0, sizeof (mark));
				DFS(que[now][0], true);
				break;
			} else if (tot == 1) {
				top--;
				memset(mark, 0, sizeof (mark));
				DFS(que[now][0], true);
				break;
			}
		}
		//for(int i=0;i<n;i++){
		//	if(visit[i])printf("%d ", i);
		//}
		//puts("");
		printf("Maximum rope length is %d.\n", cnt * 2 + top);
	}
	return 0;
}

