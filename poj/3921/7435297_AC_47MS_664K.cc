#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 60

using namespace std;

const int inf = 100000000;
int n, m, k, dis[maxn][maxn], flag[maxn], c[2 * maxn][2 * maxn], pre[2 * maxn];

struct edge {
    int u, v;
} edg[4002];

int max_flow(int s, int t) {
    int xx = 2 * n + 1, flow = 0;
    while (1) {
	queue<int>Q;
	memset(pre, -1, sizeof (pre));
	Q.push(s);
	while (!Q.empty() && pre[t] == -1) {
	    int i = Q.front();
	    Q.pop();
	    for (int j = 1; j < xx; j++) {
		if (pre[j] == -1 && c[i][j] > 0) {
		    pre[j] = i;
		    Q.push(j);
		}
	    }
	}
	if (pre[t] == -1)return flow;
	int mini = inf;
	for (int i = t; i != s; i = pre[i]) {
	    if (mini > c[pre[i]][i]) {
		mini = c[pre[i]][i];
	    }
	}
	flow += mini;
	for (int i = t; i != s; i = pre[i]) {
	    c[pre[i]][i] -= mini;
	    c[i][pre[i]] += mini;
	}
    }
}

int main() {
    while (scanf("%d%d%d", &n, &m, &k), n || m || k) {
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++) {
		dis[i][j] = inf;
	    }
	    dis[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
	    scanf("%d%d", &edg[i].u, &edg[i].v);
	    dis[edg[i].u][edg[i].v] = 1;
	}
	for (int w = 1; w <= n; w++) {
	    for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
		    if (dis[u][v] > dis[u][w] + dis[w][v]) {
			dis[u][v] = dis[u][w] + dis[w][v];
		    }
		}
	    }
	}
	if (dis[1][n] > k)puts("0");
	else {
	    memset(c, 0, sizeof (c));
	    memset(flag, 0, sizeof (flag));
	    for (int i = 1; i <= n; i++) {
		if (dis[1][i] + dis[i][n] <= k) {
		    flag[i] = 1;
		    c[i][i + n] = 1;
		}
	    }
	    for (int i = 0; i < m; i++) {
		if (flag[edg[i].u] && flag[edg[i].v]) {
		    c[edg[i].u + n][edg[i].v] = 1;
		}
	    }
	    printf("%d\n", max_flow(1 + n, n));
	}
    }
    return 0;
}
