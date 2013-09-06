#include <cstdio>
#include <cstring>
#include <cmath>

#define MAXN 1000
#define INF 1e100
#define eps 1e-6

int N;
double x[MAXN], y[MAXN], z[MAXN];
double g[MAXN][MAXN], cost[MAXN][MAXN];
double dist[MAXN];
int pre[MAXN];

double caldist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double calcost(double z1, double z2)
{
    return fabs(z1 - z2);
}

int dcmp(double x)
{
    return x < -eps ? -1 : x > eps;
}

double prim(double p)
{
    double d = 0, c = 0;
    for (int i = 1; i < N; ++i)
        dist[i] = cost[0][i] - p * g[0][i];
    dist[0] = 0;
    memset(pre, 0, sizeof (pre));
    for (int u, i = 1; i < N; ++i)
    {
        double mini = INF;
        for (int j = 1; j < N; ++j)
            if (pre[j] != -1 && dcmp(dist[j] - mini) < 0)
            {
                mini = dist[j];
                u = j;
            }
        c += cost[pre[u]][u];
        d += g[pre[u]][u];
        pre[u] = -1;
        for (int j = 0; j < N; ++j)
            if (pre[j] != -1)
            {
                double tmp = cost[u][j] - p * g[u][j];
                if (dcmp(tmp - dist[j]) < 0)
                {
                    dist[j] = tmp;
                    pre[j] = u;
                }
            }
    }
    return c / d;
}

void init()
{
    while (scanf("%d", &N), N)
    {
        for (int i = 0; i < N; ++i)
            scanf("%lf%lf%lf", x + i, y + i, z + i);
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
            {
                g[i][j] = g[j][i] = caldist(x[i], y[i], x[j], y[j]);
                cost[i][j] = cost[j][i] = calcost(z[i], z[j]);
            }
        double now = 0.0, next;
        do
        {
            next = now;
            now = prim(now);
        }while (fabs(next - now) > eps);
        printf("%.3lf\n", next);
    }
}

int main()
{
    init();
    return 0;
}