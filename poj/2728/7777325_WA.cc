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
bool mk[MAXN];

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
    double tot = 0;
    for (int i = 0; i < N; ++i)
        dist[i] = INF, mk[i] = false;
    dist[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        double mini = INF;
        int u;
        for (int j = 0; j < N; ++j)
            if (!mk[j] && dcmp(dist[j] - mini) < 0)
            {
                mini = dist[j];
                u = j;
            }
        tot += dist[u];
        mk[u] = true;
        for (int j = 0; j < N; ++j)
            if (!mk[j])
            {
                double tmp = cost[u][j] - p * g[u][j];
                if (dcmp(tmp - dist[j]) < 0) dist[j] = tmp;
            }
    }
    return tot;
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
        double st = 0.0, ed = 10000000.0, mid;
        while (st + eps < ed)
        {
            mid = (st + ed) / 2;
            if (dcmp(prim(mid)) < 0) ed = mid;
            else st = mid;
        }
        printf("%.3lf\n", mid);
    }
}

int main()
{
    init();
    return 0;
}