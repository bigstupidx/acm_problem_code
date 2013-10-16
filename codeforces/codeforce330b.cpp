#include <cstdio>
#include <cstring>

int n, m, deg[1002];

int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(deg, 0, sizeof(deg));

        for(int x, y, i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            deg[x]++;
            deg[y]++;
        }

        for(int i = 1; i <= n; i++)
        {
            if(deg[i] == 0)
            {
                printf("%d\n", n - 1);

                for(int j = 1; j <= n; j++)
                {
                    if(i == j)continue;

                    printf("%d %d\n", i, j);
                }

                break;
            }
        }
    }

    return 0;
}
