#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define inf 1000000000

using namespace std;

int n, m, dis[1002][1002], cost[1002][1002];

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)break;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = inf;
                cost[i][j] = inf;
            }

            dis[i][i] = 0;
            cost[i][i] = 0;
        }

        for (int u, v, d, c, i = 0; i < m; i++)
        {
            scanf("%d%d%d%d", &u, &v, &d, &c);

            if (dis[u][v] > d)
            {
                dis[u][v] = dis[v][u] = d;
                cost[u][v] = cost[v][u] = c;
            }
            else if (dis[u][v] == d)
            {
                cost[u][v] = min(cost[u][v], c);
                cost[v][u] = cost[u][v];
            }
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (dis[i][k] == inf)continue;

                for (int j = i + 1; j <= n; j++)
                {
                    if (dis[k][j] == inf)continue;

                    int dd = dis[i][k] + dis[k][j];

                    if (dd < dis[i][j])
                    {
                        dis[i][j] = dis[j][i] = dd;
                        cost[i][j] = cost[i][k] + cost[k][j];
                    }
                    else if (dd == dis[i][j])
                    {
                        int cc = cost[i][k] + cost[k][j];
                        cost[i][j] = cost[j][i] = min(cc, cost[i][j]);
                    }
                }
            }
        }

        int s, t;
        scanf("%d%d", &s, &t);

        printf("%d %d\n", dis[s][t], cost[s][t]);
    }

    return 0;
}
