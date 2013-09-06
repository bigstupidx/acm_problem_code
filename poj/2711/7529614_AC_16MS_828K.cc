#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

char str[22][22], gg[22][22];

struct edge {
    int to, c, next;
} e[1000010];

const int inf = 1000000000;
int n, d, m, head[1002], p[1002][2], L[1002];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

struct node {
    int x, y, cnt;
} nod[404];

void add_edge(int x, int y, int va, int &top) {
    //printf("%d -> %d %d\n", x, y, va);
    e[++top].to = y;
    e[top].c = va;
    e[top].next = head[x];
    head[x] = top;

    e[++top].to = x;
    e[top].c = 0;
    e[top].next = head[y];
    head[y] = top;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (1) {
        queue<int>Q;
        memset(L, -1, sizeof (L));
        L[s] = 0;
        Q.push(s);
        while (!Q.empty()) {
            int i = Q.front();
            Q.pop();
            for (int j = head[i]; j != -1; j = e[j].next) {
                if (L[e[j].to] == -1 && e[j].c > 0) {
                    L[e[j].to] = L[i] + 1;
                    Q.push(e[j].to);
                }
            }
        }
        if (L[t] == -1) {
            //printf("%d\n", flow);
            return flow;
        }
        int top = 0;
        p[0][0] = s;
        p[0][1] = head[s];
        while (top >= 0) {
            if (p[top][0] != t) {
                while (p[top][1] >= 0) {
                    int j = p[top][1];
                    if (L[e[j].to] > L[p[top][0]] && e[j].c > 0) {
                        p[top + 1][0] = e[j].to;
                        p[top + 1][1] = head[e[j].to];
                        top++;
                        break;
                    }
                    p[top][1] = e[j].next;
                }
                if (p[top][1] < 0) {
                    if (--top < 0)break;
                    p[top][1] = e[p[top][1]].next;
                }
            }
            else {
                int mini = inf, k;
                for (int i = 0; i < top; i++) {
                    if (mini > e[p[i][1]].c) {
                        mini = e[p[i][1]].c;
                        k = i;
                    }
                }
                flow += mini;
                for (int i = 0; i < top; i++) {
                    e[p[i][1]].c -= mini;
                    e[p[i][1]^1].c += mini;
                }
                top = k;
                p[top][1] = e[p[top][1]].next;
            }
        }
    }
}

double Distance(int i, int j) {
    double ax = nod[i].x - nod[j].x;
    double by = nod[i].y - nod[j].y;
    return sqrt(ax * ax + by * by);
}

int main() {
    //freopen("in.txt", "r", stdin);
    int nca;
    scanf("%d", &nca);
    for (int ii = 1; ii <= nca; ii++) {
        int top = -1, k = 0;
        scanf("%d%d", &n, &d);
        memset(head, -1, sizeof (head));
        for (int i = 0; i < n; i++) {
            scanf("%s", str[i]);
            m = strlen(str[i]);
            for (int j = 0; j < m; j++) {
                if (str[i][j] > '0') {
                    nod[k].x = i;
                    nod[k].y = j;
                    nod[k].cnt = str[i][j] - '0';
                    k++;
                }
            }
        }
        int sum = 0;
        int s = n * 2 * m, t = s + 1, N = n*m;
        for (int j = 0; j < n; j++) {
            scanf("%s", gg[j]);
            for (int i = 0; i < m; i++) {
                if (gg[j][i] == 'L') {
                    sum++;
                    add_edge(s, j * m + i, 1, top);
                }
            }
        }
        for (int i = 0; i < k; i++) {
            int u = nod[i].x * m + nod[i].y;
            add_edge(u, u + N, nod[i].cnt, top);
            for (int j = i + 1; j < k; j++) {
                if (Distance(i, j) <= d) {
                    int v = nod[j].x * m + nod[j].y;
                    add_edge(u + N, v, inf, top);
                    add_edge(v + N, u, inf, top);
                }
            }
            if (nod[i].x < d || nod[i].y < d || n - nod[i].x <= d || m - nod[i].y <= d) {
                add_edge(u + N, t, inf, top);
            }
        }

        sum -= max_flow(s, t);
        printf("Case #%d: ", ii);
        if (sum == 0)puts("no lizard was left behind.");
        else if (sum == 1) {
            puts("1 lizard was left behind.");
        }
        else {
            printf("%d lizards were left behind.\n", sum);
        }
    }
    return 0;
}
