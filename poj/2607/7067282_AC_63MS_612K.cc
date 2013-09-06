#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

struct edge {
    int to;
    int d;
    edge *next;
} edg[500010], *vert[502];

const int inf = 1000000000;
int n, m, dis[2][502], mark[502], flag[502];

struct QN {
    int u;
    int d;

    bool operator<(const QN & a)const {
	return a.d < d;
    }
} now;

void add_edge(int x, int y, int va, int &top) {
    edge *p = &edg[++top];
    p->to = y;
    p->d = va;
    p->next = vert[x];	vert[x] = p;
}

void dijkstra(int s, int ii) {
    priority_queue<QN>Q;
    memset(mark, 0, sizeof (mark));
    now.u = s;
    now.d = 0;
    Q.push(now);
    dis[ii][s] = 0;
    for (int k, i = 1; i < n; i++) {
	do {
	    if (Q.empty())return;
	    now = Q.top();
	    Q.pop();
	    k = now.u;
	} while (mark[k]);
	mark[k] = 1;
	for (edge *p = vert[k]; p; p = p->next) {
	    if (!mark[p->to] && dis[ii][p->to] > dis[ii][k] + p->d) {
		dis[ii][p->to] = dis[ii][k] + p->d;
		now.u = p->to;
		now.d = dis[ii][p->to];
		Q.push(now);
	    }
	}
    }
}

int main() {
//    freopen("small.in", "r", stdin);
//    freopen("small.out", "w", stdout);
    int top = -1;
    scanf("%d%d", &m, &n);
    for (int v, i = 0; i < m; i++) {
	scanf("%d", &v);
	flag[v] = 1;
    }
    int u, v, d;
    while(scanf("%d%d%d", &u, &v, &d)!=EOF){
	if (!flag[u])flag[u] = 2;
	if (!flag[v])flag[v] = 2;
	add_edge(u, v, d, top);
	add_edge(v, u, d, top);
    }
    n++;
    for (int i = 1; i < n; i++) {
	dis[0][i] = inf;
    }
    for (int i = 1; i < n; i++) {
	if (flag[i] == 1) {
	    dijkstra(i, 0);
	}
    }
    //for(int i=1;i<n;i++){
    //    printf("%d ", dis[0][i]);
    //}
    //puts("");
    int mini = inf, tem, k = 1;
    for (int i = 1; i < n; i++) {
	if (flag[i] == 2) {
	    for (int j = 1; j < n; j++) {
		dis[1][j] = dis[0][j];
	    }
	    dijkstra(i, 1);
	    tem = 0;
	    for (int j = 1; j < n; j++) {
		if (dis[1][j] != inf && tem < dis[1][j]) {
		    tem = dis[1][j];
		}
	    }
	    if (tem < mini) {
		mini = tem;
		k = i;
	    }
	}
    }
    printf("%d\n", k);
    //system("pause");
    return 0;
}

