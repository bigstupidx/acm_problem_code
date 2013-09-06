#include <cstdio>
#include <vector>
#include <cstring>
#define maxn 1002

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[2000010], *vert[maxn];

int n, m, top, anc[maxn], dep[maxn], visit[maxn], color[maxn], S[maxn];
bool g[maxn][maxn], flag[maxn], v[maxn];

inline void add_edge(int x, int y) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x], vert[x] = p;
}

bool check(int s, int cc) {
	visit[s] = cc;
	for (edge *p = vert[s]; p; p = p->next) {
		if (!v[p->to])continue;
		if (visit[p->to] == -1) {
			if (!check(p->to, cc^1)) {
				return false;
			}
		}
		else if (visit[p->to] == visit[s]) {
			return false;
		}
	}
	return true;
}

void DFS(int k, int k_father, int depth) {
	color[k] = 1;
	S[++top] = k;
	anc[k] = dep[k] = depth;
	for (edge *p = vert[k]; p; p = p->next) {
		int i = p->to;
		if (color[i] == 1 && i != k_father) {
			anc[k] = anc[k] < dep[i] ? anc[k] : dep[i];
		}
		else if (color[i] == 0) {
			DFS(i, k, depth + 1);
			anc[k] = anc[k] < anc[i] ? anc[k] : anc[i];
			if (anc[i] >= dep[k]) {
				vector <int> temp;
				memset(v, 0, sizeof (v));
				temp.push_back(k);
				v[k] = true;
				do {
					v[S[top]] = true;
					temp.push_back(S[top]);
				} while (S[top--] != i);

				//				for (int j = 0; j < temp.size(); j++) {
				//					printf("%d ", temp[j]);
				//				}
				//				puts("");
				
				memset(visit, -1, sizeof (visit));
				if (!check(k, 0)) {
					for (int j = 0; j < temp.size(); j++) {
						flag[temp[j]] = true;
					}
				}
			}
		}
	}
	color[k] = 2;
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m) {
		top = -1;
		memset(g, true, sizeof (g));
		memset(vert, 0, sizeof (vert));
		for (int x, y, i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			g[x][y] = false;
			g[y][x] = false;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (g[i][j]) {
					add_edge(i, j);
					add_edge(j, i);
				}
			}
		}
		memset(flag, 0, sizeof (flag));
		memset(color, 0, sizeof (color));
		memset(visit, 0, sizeof (visit));
		for (int i = 1; i <= n; i++) {
			if (!color[i]) {
				top = 0;
				DFS(i, -1, 1);
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (flag[i]) {
				++cnt;
			}
		}
		printf("%d\n", n - cnt);
	}
	return 0;
}
