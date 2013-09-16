#include<stdio.h>
#include<string.h>
const int inf = 20000;
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
int g[205][205], c[205][205];
int a[205], b[205];
int queue[5000000];
int pre[450];
int suma, sumb;

int bfs(int s, int t, int n) {
    int head = 0, tail = 0;
    queue[tail++] = s;
    for (int i = 0; i <= n; ++i) pre[i] = -1;
    while (head < tail) {
	int u = queue[head++];
	for (int i = 0; i <= n; i++)
	    if (c[u][i] > 0 && pre[i] == -1) {
		queue[tail++] = i;
		pre[i] = u;
		if (i == t) break;
	    }
    }
    if (pre[t] == -1) return 0;
    int delta = inf;
    for (int i = t; i != s; i = pre[i])
	delta = min(delta, c[pre[i]][i]);
    return delta;
}

int max_flow(int s, int t, int n) {
    int flow = 0;
    while (1) {
	int delta = bfs(s, t, n);
	if (delta <= 0) break;
	flow += delta;
	for (int i = t; i != s; i = pre[i]) {
	    c[pre[i]][i] -= delta;
	    c[i][pre[i]] += delta;
	}
    }
    return flow;
}

bool check(int v, int n) {
    int i, j;
    memset(c, 0, sizeof (c));
    for (i = 1; i <= n; ++i) {
	c[0][i] = a[i];
	c[i][n + 1] = b[i];
    }
    for (i = 1; i <= n; ++i)
	for (j = 1; j <= n; ++j)
	    if (i != j && g[i][j] <= v)
		c[i][j] = inf;
    if (max_flow(0, n + 1, n + 1) >= suma) return true;
    return false;
}

int main() {
    int n, m, ans;
    int i, j, k, s, t, v, low, mid, high;
    while (scanf("%d", &n) && n) {
	ans = -1;
	suma = sumb = 0;
	for (i = 1; i <= n; ++i) {
	    scanf("%d", &a[i]);
	    suma += a[i];
	}
	for (i = 1; i <= n; ++i) {
	    scanf("%d", &b[i]);
	    sumb += b[i];
	}
	for (i = 1; i <= n; ++i) {
	    for (j = i + 1; j <= n; ++j)
		g[i][j] = g[j][i] = inf;
	    g[i][i] = 0;
	}

	low = 0, high=-1;
	scanf("%d", &m);
	for (i = 1; i <= m; ++i) {
	    scanf("%d%d%d", &s, &t, &v);
	    if(v > high) high=v;
	    g[s][t] = g[t][s] = min(g[s][t], v);
	}
	if (suma > sumb) {
	    puts("No Solution");
	    continue;
	}
	while (low <= high) {
	    mid = (low + high) >> 1;
	    if (check(mid, n)) {
		ans = mid;
		high = mid - 1;
	    } else low = mid + 1;
	}
	ans  == -1 ? puts("No Solution") : printf("%d\n", ans);
    }
    return 0;
}