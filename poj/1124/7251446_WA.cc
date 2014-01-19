#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[100010], *vert[404];

char str[22][22], tem[12];
int n, m, dis[2][404], mark[404], cnt[2][404], flag[30];
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
double ans[22][22];

struct entrance {
	int x, y;
} ent[30];

struct QN {
	int u;
	int d;
	bool operator<(const QN & a)const {
		return a.d < d;
	}
} now;

void add_edge(int x, int y, int &top) {
	//printf("%d %d\n", x, y);
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];	vert[x] = p;
}

void dijkstra(int s, int ii) {
	priority_queue <QN> Q;
	for (int i = 0; i < n; i++) {
		dis[ii][i] = 100000;
		cnt[ii][i] = 0;
		mark[i] = 0;
	}
	now.u = s;
	now.d = 0;
	Q.push(now);
	dis[ii][s] = 0;
	cnt[ii][s] = 1;
	for (int k, i = 1; i < n; i++) {
		do {
			if (Q.empty())return;
			now = Q.top();
			Q.pop();
			k = now.u;
		} while (mark[k]);
		mark[k] = 1;
		for (edge *p = vert[k]; p; p = p->next) {
			if (mark[p->to])continue;
			char ch = str[p->to / m][p->to % m];
			if (ch != tem[(ii + 1) % 2] && ch <= 'Z' && ch >= 'A')continue;
			if (dis[ii][p->to] > dis[ii][k] + 1) {
				cnt[ii][p->to] = cnt[ii][k];
				dis[ii][p->to] = dis[ii][k] + 1;
				now.u = p->to;
				now.d = dis[ii][p->to];
				Q.push(now);
			} else if (dis[ii][p->to] == dis[ii][k] + 1) {
				cnt[ii][p->to] += cnt[ii][k];
			}
		}
	}
}

int main() {
//	freopen("out.txt", "w", stdout);
	int top = -1;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	int r = n, c = m;
	for (int u, i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] == 'X')continue;
			u = i * m + j;
			if (str[i][j] != '.') {
				ent[str[i][j] - 'A'].x = i;
				ent[str[i][j] - 'A'].y = j;
				flag[str[i][j] - 'A'] = 1;
			}
			for (int k = 0; k < 4; k++) {
				int ii = i + dir[k][0];
				int jj = j + dir[k][1];
				if (ii < 0 || ii == n || jj < 0 || jj == m)continue;
				if (str[ii][jj] == 'X')continue;
				add_edge(u, ii * m + jj, top);
			}
		}
	}
	n = n * m;
	while (scanf("%s", tem) != EOF) {
		int load;
		scanf("%d", &load);
		if (strcmp(tem, "XX") == 0)break;
		int s = ent[tem[0] - 'A'].x * m + ent[tem[0] - 'A'].y;
		int t = ent[tem[1] - 'A'].x * m + ent[tem[1] - 'A'].y;

		dijkstra(t, 1);
		dijkstra(s, 0);
		for (int i = 0; i < n; i++) {
			cnt[0][i] = cnt[0][i] * cnt[1][i];
			//printf("%d ", cnt[0][i]);
		}
		//puts("");

		int dd = dis[0][t] - 1;
		memset(mark, 0, sizeof (mark));
		for (int i = 0; i < n; i++) {
			for (edge *p = vert[i]; p; p = p->next) {
				if (dd == dis[0][i] + dis[1][p->to]) {
					mark[p->to] = 1;
					mark[i] = 1;
				}
			}
		}

		double aver = (load * 1.0) / cnt[0][s];
		for (int i = 0; i < n; i++) {
			if (mark[i]) {
				if (i == s || i == t)continue;
				ans[i / m][i % m] += aver * cnt[0][i];
			}
		}
	}
	for (int i = 0; i < 30; i++){
		if(flag[i]){
			ans[ent[i].x][ent[i].y] = 0;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%7.2lf ", ans[i][j]);
		}
		puts("");
	}
	system("pause");
	return 0;
}