#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

struct point {
	int x, y;
} pp[500];

struct lines {
	int ii, jj, tag;
} lin[202];

struct edge {
	int to;
	double d;
	edge *next;
} edg[1000010], *vert[500];

double inf = 1e100, dis[500];
int n, deg[500], m, mark[500], pre[500], cnt[202];

struct node {
	int i;

	bool operator<(const node & a)const {
		if (pp[a.i].x == pp[i].x) {
			return pp[a.i].y > pp[i].y;
		}
		return pp[a.i].x > pp[i].x;
	}
};

vector <node> front[200];

void add_edge(int x, int y, double va, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x], vert[x] = p;
}

struct QN {
	int u;
	double d;

	bool operator<(const QN & a)const {
		return a.d < d;
	}
} now;

void dijkstra(int s) {
	priority_queue <QN> Q;
	for (int i = 0; i < m; i++) {
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
			if (!mark[p->to] && dis[p->to] > dis[k] + p->d) {
				dis[p->to] = dis[k] + p->d;
				now.u = p->to;
				now.d = dis[p->to];
				Q.push(now);
			}
		}
	}
}

double Distance(int i, int j) {
	double ax = pp[i].x - pp[j].x;
	double by = pp[i].y - pp[j].y;
	return sqrt(ax * ax + by * by);
}

int dot(point &a, point &b, point &c) {
	return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

int cross(point &a, point &b, point &c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int PointOn(point &a, point &b, point &c) {
	return cross(a, b, c) == 0 && dot(a, b, c) <= 0;
}

int main() {
	while (scanf("%d", &n), n) {
		int x, y;
		map <pair<int, int>, int> mp;
		map <pair<int, int>, int> ::iterator p, q;

		scanf("%d%d", &x, &y);
		mp.insert(make_pair(make_pair(x, y), 0));
		pp[0].x = x, pp[0].y = y;

		scanf("%d%d", &x, &y);
		mp.insert(make_pair(make_pair(x, y), 1));
		pp[1].x = x, pp[1].y = y;

		memset(deg, 0, sizeof (deg));

		m = 2;
		for (int i = 0; i < n; i++) {

			scanf("%d%d", &x, &y);

			p = mp.find(make_pair(x, y));
			if (p == mp.end()) {
				mp.insert(make_pair(make_pair(x, y), m));
				pp[m].x = x, pp[m].y = y;
				lin[i].ii = m;
				deg[m] = 1;
				m++;
			}
			else {
				lin[i].ii = p->second;
				deg[p->second]++;
			}

			scanf("%d%d", &x, &y);
			p = mp.find(make_pair(x, y));
			if (p == mp.end()) {
				mp.insert(make_pair(make_pair(x, y), m));
				pp[m].x = x, pp[m].y = y;
				lin[i].jj = m;
				deg[m] = 1;
				m++;
			}
			else {
				lin[i].jj = p->second;
				deg[p->second]++;
			}
		}
		memset(mark, 0, sizeof (mark));
		for (int tem, i = 0; i < n; i++) {
			if (deg[lin[i].ii] == 1) {
				lin[i].tag = 0;
			}
			else if (deg[lin[i].jj] == 1) {
				lin[i].tag = 0;
				tem = lin[i].ii;
				lin[i].ii = lin[i].jj;
				lin[i].jj = tem;
			}
			else {
				lin[i].tag = 1;
				mark[lin[i].ii] = 1;
				mark[lin[i].jj] = 1;
			}
		}

		int k = 0;
		for (int i = 0; i < n; i++) {
			if (lin[i].tag == 0)continue;
			for (int j = 0; j < n; j++) {
			}
		}

		for (int i = 0; i < n; i++) {
			if (lin[i].tag == 0) {
				for (int j = 0; j < n; j++) {
					if (lin[i].tag < 1)break;
					if (PointOn(pp[lin[i].jj], pp[lin[j].ii], pp[lin[j].jj])) {
						int temp = dot(pp[lin[i].jj], pp[lin[j].ii], pp[lin[i].ii]);
						if (temp == 0) {
							lin[j].tag = -1;
						}
						else if (temp < 0) {
							if (lin[j].tag == 2) {
								lin[j].tag = -1;
							}
							else lin[j].tag = 3;
						}
						else {
							if (lin[j].tag == 3) {
								lin[j].tag = -1;
							}
							else lin[j].tag = 2;
						}
						break;
					}
				}
			}
		}
		int top = -1;
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < n; i++) {
			if (lin[i].tag < 1)continue;
			if (lin[i].tag == 1) {
				add_edge(lin[i].ii, lin[i].jj, lin[i].dd, top);
				add_edge(lin[i].jj, lin[i].ii, lin[i].dd, top);
			}
			else if (lin[i].tag == 2) {
				add_edge(lin[i].ii, lin[i].jj, lin[i].dd, top);
			}
			else if (lin[i].tag == 3) {
				add_edge(lin[i].jj, lin[i].ii, lin[i].dd, top);
			}
			for (int j = 0; j < n; j++) {
				if (lin[j].tag < 1)continue;
				if (lin[i].ii == lin[j].ii || lin[i].ii == lin[j].jj)continue;
				if (lin[i].jj == lin[j].ii || lin[i].jj == lin[j].jj)continue;
				if (PointOn(pp[lin[i].ii], pp[lin[j].ii], pp[lin[j].jj])) {

					double temp = Distance(lin[j].ii, lin[i].ii);
					add_edge(lin[j].ii, lin[i].ii, temp, top);
					add_edge(lin[i].ii, lin[j].ii, temp, top);

					temp = Distance(lin[j].jj, lin[i].ii);
					add_edge(lin[j].jj, lin[i].ii, temp, top);
					add_edge(lin[i].ii, lin[j].jj, temp, top);
				}
				else if (PointOn(pp[lin[i].jj], pp[lin[j].ii], pp[lin[j].jj])) {
					double temp = Distance(lin[i].jj, lin[j].ii);
					add_edge(lin[i].jj, lin[j].ii, temp, top);
					add_edge(lin[j].ii, lin[i].jj, temp, top);
					temp = Distance(lin[i].jj, lin[j].jj);
					add_edge(lin[i].jj, lin[j].jj, temp, top);
					add_edge(lin[j].jj, lin[i].jj, temp, top);
				}
			}
		}
		dijkstra(0);
		if (dis[1] == inf)puts("-1");
		else {
			stack <int> S;
			int t = 1;
			while (pre[t] != -1) {
				S.push(t);
				t = pre[t];
			}
			while (!S.empty()) {
				t = S.top();
				S.pop();
				printf("%d %d\n", pp[t].x, pp[t].y);
			}
			puts("0");
		}
	}
	return 0;
}
