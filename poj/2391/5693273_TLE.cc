#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long n, dp[220][220], c[500][500], flow[500], cow[220], pi[220], Y, pre[500];
long long bb[200000];
const long long inf = 1LL << 60;
int getnum()
{
    char ch;
    while (ch=getchar(),ch==10||ch==32);
    int ans=ch-48;
    while ((ch=getchar())!=EOF&&(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans;
}
void Floyd_Short_Path() {
    int u, v, w;
    for (v = 1; v <= n; v++)
        for (u = 1; u <= n; u++)
            for (w = 1; w <= n; w++)
                if (dp[w][u] > dp[w][v] + dp[v][u])
                    dp[w][u] = dp[v][u] + dp[w][v];
}

long long BFS(int s, int t) {
    int i, p;
    queue<int>Q;
    for (i = 0; i <= 2 * n + 1; i++) {
        pre[i] = -2;
        flow[i] = inf;
    }
    Q.push(s);
    pre[s] = -1;
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        if (p == t) return flow[t];
        for (i = 0; i <= 2 * n + 1; i++)
            if (pre[i] == -2 && c[p][i]) {
                flow[i] = min(flow[p], c[p][i]);
                pre[i] = p;
                Q.push(i);
                if (i == t) return flow[t];
            }
    }
    return flow[t];
}

long long Ford_Fulkerson(int s, int t) {
    long long Max_flow = 0, step, now;
    while ((step = BFS(s, t)) != inf) {
        Max_flow += step;
        now = t;
        while (now != s) {
            c[pre[now]][now] -= step;
            c[now][pre[now]] += step;
            now = pre[now];
        }
    }
    return Max_flow;
}

bool solve(long long mid) {
    int i, j;
    memset(c, 0, sizeof (c));
    for (i = 1; i <= n; i++)c[i][i + n] = inf;
    for (i = 1; i <= n; i++) {
        c[0][i] = cow[i];
        c[i + n][2 * n + 1] = pi[i];
    }
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            if (dp[i][j] < inf && dp[i][j] <= mid)
                c[i][j + n] = c[j][i + n] = inf;
    return Ford_Fulkerson(0, 2 * n + 1) == Y;
}

int main() {
    int m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int i, j;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                dp[i][j] = inf;
        for (i = 1; i <= n; i++)dp[i][i] = 0;

        Y = 0;
        for (i = 1; i <= n; i++) {
            cow[i]=getnum();pi[i]=getnum();
            Y += cow[i];
        }

        while (m--) {
            int d;
            i=getnum();j=getnum();d=getnum();
            if (d < dp[i][j])
                dp[i][j] = dp[j][i] = d;
        }
        Floyd_Short_Path();
        int cnt = 1;
        bb[0] = 0;
        for (i = 1; i <= n; i++)
            for (j = i + 1; j <= n; j++)
                if (dp[i][j] < inf)
                    bb[cnt++] = dp[i][j];
        sort(bb, bb + cnt);
        int l = 0, r = cnt - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            //printf("try %d: ",mid);
            if (solve(bb[mid])) {
                //puts("success");
                r = mid - 1;
            } else {
                //puts("failure");
                l = mid + 1;
            }
        }
        if (l == cnt)bb[l] = -1;
        printf("%lld\n", bb[l]);
    }
    return 0;
}

