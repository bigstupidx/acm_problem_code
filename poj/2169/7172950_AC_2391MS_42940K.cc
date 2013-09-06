#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
	int to;
	int d;
	edge *next;
} edg[8000010], *vert[2002];

const int inf = 100000000;
int n, m, s[2], t[2], dis[2002], mark[2002], start, end, pre[2002];

struct QN {
	int u;
	int d;
	bool operator<(const QN & a)const {
		return a.d < d;
	}
} now;

struct node {
	int x, y;
} nod[100010];

vector <int> front[102];

map <pair<int, int>, int> mp;
map <pair<int, int>, int> ::iterator p, pos;
map <int, pair<int, int> > gg;
map <int, pair<int, int> > ::iterator q;

void _add(int a, int b, int &id) {
	mp.insert(make_pair(make_pair(a, b), id++));
	mp.insert(make_pair(make_pair(b, a), id++));
	gg.insert(make_pair(id - 2, make_pair(a, b)));
	gg.insert(make_pair(id - 1, make_pair(b, a)));
}

void add_edge(int x, int y, int va, int &top) {
	//	printf("%d -> %d\n", x, y);
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x];	vert[x] = p;
}

void _init() {
	int id = 0;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s[0], &s[1]);
	scanf("%d%d", &t[0], &t[1]);
	for (int x, y, i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		_add(x, y, id);
		front[x].push_back(y);
		front[y].push_back(x);
	}
	int top = -1;
	memset(vert, 0, sizeof (vert));
	for (p = mp.begin(); p != mp.end(); p++) {
		int x = p->first.first;
		int y = p->first.second;
		for (int j = 0; j < front[x].size(); j++) {
			int xto = front[x][j];
			if (xto == y)continue;
			pos = mp.find(make_pair(xto, y));
			if (pos != mp.end()) {
				add_edge(p->second, pos->second, 1, top);
			}
		}
		for (int j = 0; j < front[y].size(); j++) {
			int yto = front[y][j];
			pos = mp.find(make_pair(x, yto));
			if (yto != x && pos != mp.end()) {
				add_edge(p->second, pos->second, 1, top);
			}
			for (int k = 0; k < front[x].size(); k++) {
				int xto = front[x][k];
				if (xto == y && yto == x)continue;
				pos = mp.find(make_pair(xto, yto));
				if (pos != mp.end()) {
					add_edge(p->second, pos->second, 2, top);
				}
			}
		}
	}
	n = id;
	end = mp.find(make_pair(t[0], t[1]))->second;
	start = mp.find(make_pair(s[0], s[1]))->second;
}

void dijkstra() {
	priority_queue<QN>Q;
	for (int i = 0; i < n; i++) {
		dis[i] = inf;
		mark[i] = 0;
		pre[i] = -1;
	}
	now.u = start;
	now.d = 0;
	Q.push(now);
	dis[start] = 0;
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
				pre[p->to] = k;
				now.u = p->to;
				now.d = dis[p->to];
				Q.push(now);
			}
		}
	}
}

void my_print() {
	int top = 1;
	printf("%d", dis[end]);
	while (end != -1) {
		q = gg.find(end);
		nod[top].x = q->second.first;
		nod[top].y = q->second.second;
		top++;
		end = pre[end];
	}
	printf(" %d\n", top - 1);
	for (int i = top - 1; i > 0; i--) {
		printf("%d %d\n", nod[i].x, nod[i].y);
	}
}

int main() {
	_init();
	dijkstra();
	my_print();
	return 0;
}