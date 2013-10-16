#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int inf = 1000000000;

int n, m, c[120][120], f[120][120], pre[120];

int max_flow(int s, int t) {
    int flow = 0;
    memset(f, 0, sizeof (f));
    while (1) {
	int mini = inf;
	queue<int>Q;
	memset(pre, -1, sizeof (pre));
	Q.push(s);
	while (!Q.empty() && pre[t] == -1) {
	    int i = Q.front();
	    Q.pop();
	    for (int j = 0; j < 102; j++) {
		if (pre[j] == -1 && c[i][j] > f[i][j]) {
		    pre[j] = i;
		    Q.push(j);
		}
	    }
	}
	if (pre[t] == -1) {
	    //	    printf("%d\n", flow);
	    return flow;
	}
	for (int i = t; i != s; i = pre[i]) {
	    if (mini > c[pre[i]][i] - f[pre[i]][i]) {
		mini = c[pre[i]][i] - f[pre[i]][i];
	    }
	}
	flow += mini;
	for (int i = t; i != s; i = pre[i]) {
	    f[pre[i]][i] += mini;
	    f[i][pre[i]] -= mini;
	}
    }
}

int main() {
    int nca;
    scanf("%d", &nca);
    while (nca--) {
	scanf("%d%d", &m, &n);
	n/=2;
	memset(c, 0, sizeof (c));
	for (int s, t, i = 0; i < m; i++) {
	    scanf("%d%d", &s, &t);
	    for (int j = s; j < t; j++) {
		c[j][j + 1]++;
	    }
	    c[t][101]++;
	}
	for (int i = 1; i < 101; i++) {
	    if (i % 7 != 0 && i % 7 != 6) {
		c[0][i] = n;
	    }
	}
	if (max_flow(0, 101) == m) {
	    puts("fine");
	}
	else {
	    for (int i = 1; i < 101; i++) {
		c[0][i] = 1;
	    }
	    if (max_flow(0, 101) == m) {
		puts("weekend work");
	    }
	    else {
		puts("serious trouble");
	    }
	}
    }
    return 0;
}
