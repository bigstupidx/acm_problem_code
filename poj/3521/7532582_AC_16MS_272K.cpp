#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

struct edge {
	int to;
	double d;
	edge *next;
} edg[500010], *vert[500];

double inf = 1e100, dis[500];
int n, m, mark[500], pre[500], deg[500];

struct Qnode {
	int u;
	double d;

	bool operator<(const Qnode & a)const {
		return a.d < d;
	}
} now;

void add_edge(int x, int y, double va, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x], vert[x] = p;
}

void dijkstra(int s) {
	priority_queue <Qnode> Q;
	for (int i = 0; i < m; i++) {
		dis[i] = inf;
		mark[i] = 0;
		pre[i] = -1;
	}
	now.u = s;
	now.d = 0;
	Q.push(now);
	dis[s] = 0;
	for (int k, i = 1; i < m; i++) {
		do {
			if (Q.empty())return;
			now = Q.top();
			Q.pop();
			k = now.u;
		} while (mark[k]);
		mark[k] = 1;
		for (edge *p = vert[k]; p; p = p->next) {
			if (!mark[p->to] && dis[p->to] > dis[k] + p->d) {
				pre[p->to] = k;
				dis[p->to] = dis[k] + p -> d;
				now.u = p->to;
				now.d = dis[p->to];
				Q.push(now);
			}
		}
	}
}

struct point {
	int x, y;
} p[202];

struct lines {
	int ii;

	bool operator<(const lines & a)const {
		if (p[a.ii].x == p[ii].x) {
			return p[a.ii].y > p[ii].y;
		}
		return p[a.ii].x > p[ii].x;
	}
};

vector <lines> lin[202];

struct node {
	int i, j, tag;
} nod[202], fin[10010];

double Distance(int i, int j) {
	double ax = p[i].x - p[j].x;
	double by = p[i].y - p[j].y;
	return sqrt(ax * ax + by * by);
}

int dot(point &a, point &b, point &c) {
	return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

int cross(point &a, point &b, point &c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool PointOn(point &a, point &b, point &c) {
	return cross(a, b, c) == 0 && dot(a, b, c) <= 0;
}

void solve() {
	map <pair<int, int>, int> mp;
	map <pair<int, int>, int> ::iterator pos;

	scanf("%d%d", &p[0].x, &p[0].y);
	mp.insert(make_pair(make_pair(p[0].x, p[0].y), 0));
	scanf("%d%d", &p[1].x, &p[1].y);
	mp.insert(make_pair(make_pair(p[1].x, p[1].y), 1));

	m = 2;
	for (int x, y, i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		pos = mp.find(make_pair(x, y));
		if (pos == mp.end()) {
			mp.insert(make_pair(make_pair(x, y), m));
			p[m].x = x, p[m].y = y;
			nod[i].i = m;
			m++;
		}
		else nod[i].i = pos->second;

		scanf("%d%d", &x, &y);
		pos = mp.find(make_pair(x, y));
		if (pos == mp.end()) {
			mp.insert(make_pair(make_pair(x, y), m));
			p[m].x = x, p[m].y = y;
			nod[i].j = m;
			m++;
		}
		else nod[i].j = pos->second;
	}

	memset(deg, 0, sizeof (deg));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (PointOn(p[i], p[nod[j].i], p[nod[j].j])) {
				deg[i]++;
			}
		}
		//printf("%d %d %d\n", p[i].x, p[i].y, deg[i]);
	}

	memset(mark, 0, sizeof (mark));
	for (int temp, i = 0; i < n; i++) {
		if (deg[nod[i].i] == 1) {
			nod[i].tag = 0;
		}
		else if (deg[nod[i].j] == 1) {
			nod[i].tag = 0;
			temp = nod[i].i, nod[i].i = nod[i].j, nod[i].j = temp;
		}
		else {
			nod[i].tag = 1;
			mark[nod[i].i] = 1;
			mark[nod[i].j] = 1;
		}
		lin[i].clear();
	}

	int mm = 0;
	for (int i = 0; i < n; i++) {
		if (nod[i].tag == 0)continue;
		for (int j = 0; j < m; j++) {
			if (!mark[j])continue;
			if (PointOn(p[j], p[nod[i].i], p[nod[i].j])) {
				lines temp;
				temp.ii = j;
				lin[i].push_back(temp);
			}
		}
		sort(lin[i].begin(), lin[i].end());
		for (int j = 1; j < lin[i].size(); j++) {
			//printf("%d %d   ", p[lin[i][j].ii].x, p[lin[i][j].ii].y);
			fin[mm].i = lin[i][j - 1].ii;
			fin[mm].j = lin[i][j].ii;
			fin[mm].tag = 1;
			mm++;
		}
		//puts("");
	}

	//	for (int i = 0; i < mm; i++) {
	//		printf("%d %d", p[fin[i].i].x, p[fin[i].i].y);
	//		printf("  %d %d\n", p[fin[i].j].x, p[fin[i].j].y);
	//	}
	//	puts("");

	for (int i = 0; i < n; i++) {
		if (nod[i].tag == 1)continue;
		for (int j = 0; j < mm; j++) {
			if (fin[j].tag == -1)continue;
			if (PointOn(p[nod[i].j], p[fin[j].i], p[fin[j].j])) {
				int temp = dot(p[nod[i].j], p[fin[j].i], p[nod[i].i]);
				if (temp == 0) {
					fin[j].tag = -1;
				}
				else if (temp < 0) {
					if (fin[j].tag == 2) {
						fin[j].tag = -1;
					}
					else fin[j].tag = 3;
				}
				else {
					if (fin[j].tag == 3) {
						fin[j].tag = -1;
					}
					else fin[j].tag = 2;
				}
				break;
			}
		}
	}
	int top = -1;
	memset(vert, 0, sizeof (vert));
	for (int i = 0; i < mm; i++) {
		if (fin[i].tag == -1)continue;
		double tem = Distance(fin[i].i, fin[i].j);
		if (fin[i].tag == 1) {
			add_edge(fin[i].i, fin[i].j, tem, top);
			add_edge(fin[i].j, fin[i].i, tem, top);
		}
		else if (fin[i].tag == 2) {
			add_edge(fin[i].i, fin[i].j, tem, top);
		}
		else if (fin[i].tag == 3) {
			add_edge(fin[i].j, fin[i].i, tem, top);
		}
	}
	dijkstra(0);
	if (dis[1] == inf)puts("-1");
	else {
		stack <int> S;
		int t = 1;
		while (t != -1) {
			S.push(t);
			t = pre[t];
		}
		while (!S.empty()) {
			t = S.top();
			S.pop();
			printf("%d %d\n", p[t].x, p[t].y);
		}
		puts("0");
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		solve();
	}
	return 0;
}
