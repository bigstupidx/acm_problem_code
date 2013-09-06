#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
#define MAXN 60

using namespace std;

double dis[MAXN], inf = 1e100;
int n, xx[MAXN], yy[MAXN], zz[MAXN], durtime[MAXN], id[MAXN];

struct edge {
	int to;
	double d;
	int begin_time;
	edge *next;
} edg[10000], *vert[MAXN];

struct Qnode {
	int u;
	double d;
	bool operator <(const Qnode &a) const {
		return a.d < d;
	}
} now;

void add_edge(int x, int y, int begin_time, double time, int &top) {
	printf("%d -> %d %lf %d\n", x, y, time, begin_time);
	edge *p = &edg[++top];
	p->to = y;
	p->d = time;
	p->begin_time = begin_time;
	p->next = vert[x], vert[x] = p;
}

double Distance(int i, int j) {
	double ax = xx[i] - xx[j];
	double by = yy[i] - yy[j];
	double cz = zz[i] - zz[j];
	return sqrt(ax * ax + by * by + cz * cz);
}

void solve() {
	priority_queue<Qnode> Q;
	for (int i = 0; i < n; ++i) {
		dis[i] = inf;
	}
	dis[0] = 0;
	now.u = 0;
	now.d = 0;
	Q.push(now);
	while (!Q.empty()) {
		now = Q.top();
		Q.pop();
		int k = now.u;
		for (edge *p = vert[k]; p; p = p->next) {
			if (p->begin_time > dis[k])
				continue;
			if (dis[p->to] > dis[k] + p->d) {
				dis[p->to] = dis[k] + p->d;
				now.u = p->to;
				now.d = dis[p->to];
				Q.push(now);
			}
		}
	}
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		for (int i = 0; i < 2; i++) {
			scanf("%d%d%d", &xx[i], &yy[i], &zz[i]);
			id[i] = i;
		}
		scanf("%d", &n);
		n += 2;
		int ver_id = 2, top = -1;
		memset(vert, 0, sizeof(vert));
		for (int i = 2; i < n; ++i) {
			int x, y, z, u = -1, v = -1;
			scanf("%d%d%d", &x, &y, &z);
			for (int j = 0; j < ver_id; ++j) {
				if (x == xx[j] && y == yy[j] && z == zz[j]) {
					u = j;
					break;
				}
			}
			if (u == -1) {
				xx[ver_id] = x;
				yy[ver_id] = y;
				zz[ver_id] = z;
				u = ver_id++;
			}
			scanf("%d%d%d", &x, &y, &z);
			for (int j = 0; j < ver_id; ++j) {
				if (x == xx[j] && y == yy[j] && z == zz[j]) {
					v = j;
					break;
				}
			}
			if (v == -1) {
				xx[ver_id] = x;
				yy[ver_id] = y;
				zz[ver_id] = z;
				v = ver_id++;
			}
			scanf("%d%d", &x, &y);
			add_edge(u, v, x, y, top);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				double dist = Distance(i, j);
				add_edge(i, j, 0, dist, top);
				add_edge(j, i, 0, dist, top);
			}
		}
		solve();
		printf("%.0lf\n", dis[1]);
	}
	return 0;
}
