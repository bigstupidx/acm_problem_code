#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 27002

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[162000], *vert[maxn];

const int inf = 2147483647;
int l, r, c, dis[maxn], mark[maxn];

char str[30][30][30];

void add_edge(int x, int y, int &top) {
	//printf("%d -> %d\n", x, y);
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x], vert[x] = p;
}

int dir[6][3] = {1, 0, 0, -1, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 1, 0, 0, -1};

void build_g() {
	int top = -1;
	memset(vert, 0, sizeof (vert));
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (str[i][j][k] == '.') {
					for (int x = 0; x < 6; x++) {
						int ii = i + dir[x][0];
						int jj = j + dir[x][1];
						int kk = k + dir[x][2];
						if (ii < 0 || jj < 0 || kk < 0 || kk == c)continue;
						if (ii == l || jj == r || str[ii][jj][kk] == '#')continue;
						add_edge(i * r * c + j * c + k, ii * r * c + jj * c + kk, top);
					}
				}
			}
		}
	}
}

struct QN {
	int u;
	int d;

	bool operator<(const QN & a)const {
		return a.d < d;
	}
} now;

void dijkstra(int s) {
	int n = r * c*l;
	priority_queue <QN> Q;
	for (int i = 0; i < n; i++) {
		dis[i] = inf;
		mark[i] = 0;
	}
	now.u = s;
	now.d = 0;
	Q.push(now);
	dis[s] = 0;
	for (int k, i = 1; i < n; i++) {
		do {
			if (Q.empty())return;
			now = Q.top();
			Q.pop();
			k = now.u;
		} while (mark[k]);
		mark[k] = 1;
		for (edge *p = vert[k]; p; p = p->next) {
			if (!mark[p->to] && dis[p->to] > dis[k] + 1) {
				dis[p->to] = dis[k] + 1;
				now.u = p->to;
				now.d = dis[p->to];
				Q.push(now);
			}
		}
	}
}

int main() {
	while (scanf("%d%d%d", &l, &r, &c), l || r || c) {
		int s, t;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				scanf("%s", str[i][j]);
				for (int k = 0; k < c; k++) {
					if (str[i][j][k] == 'S') {
						s = i * r * c + j * c + k;
						str[i][j][k] = '.';
					}
					else if (str[i][j][k] == 'E') {
						t = i * r * c + j * c + k;
						str[i][j][k] = '.';
					}
				}
			}
		}
		build_g();
		dijkstra(s);
		if (dis[t] == inf) {
			puts("Trapped!");
		}
		else {
			printf("Escaped in %d minute(s).\n", dis[t]);
		}
	}
	return 0;
}
