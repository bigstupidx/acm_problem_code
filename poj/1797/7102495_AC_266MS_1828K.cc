#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
    int to;
    int d;
    edge *next;
} edg[2000010], *vert[1002];

int n, m, mark[1002], dis[1002];

struct QN {
    int u;
    int d;
    bool operator<(const QN & a)const {
	return a.d > d;
    }
} now;

void add_edge(int x, int y, int va, int &top) {
    edge *p = &edg[++top];
    p->to = y;
    p->d = va;
    p->next = vert[x];
    vert[x] = p;
}

int dijkstra(int s) {
    priority_queue<QN>Q;
    memset(dis, 0, sizeof (dis));
    memset(mark, 0, sizeof (mark));
    now.u = s;
    now.d = 100000000;
    Q.push(now);
    while (!Q.empty()) {
	now = Q.top();
	Q.pop();
	int u = now.u;
	int d = now.d;
	if(u==n)break;
	if (mark[u])continue;
	mark[u] = 1;
	for (edge *p = vert[u]; p; p = p->next) {
	    if (mark[p->to])continue;
	    now.d = d;
	    if (now.d > p->d) {
		now.d = p->d;
	    }
	    if (now.d > dis[p->to]) {
		dis[p->to] = now.d;
		now.u = p->to;
		Q.push(now);
	    }
	}
    }
    return dis[n];
}

int main() {
    int nca;
    scanf("%d", &nca);
    for (int ii = 1; ii <= nca; ii++) {
	int top = -1;
	memset(vert, 0, sizeof (vert));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
	    int u, v, d;
	    scanf("%d%d%d", &u, &v, &d);
	    add_edge(u, v, d, top);
	    add_edge(v, u, d, top);
	}
	printf("Scenario #%d:\n", ii);
	printf("%d\n", dijkstra(1));
	puts("");
    }
    return 0;
}
