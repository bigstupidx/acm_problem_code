#include <cstdio>
#include <cstring>

int n, m, par[1001];

int find_par(int x)
{
    if (par[x] == x)
    {
        return x;
    }

    return par[x] = find_par(par[x]);
}


void union_par(int u, int v)
{
    int ii = find_par(u);
    int jj = find_par(v);
    par[ii] = jj;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)break;

        scanf("%d", &m);

        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }

        for (int u, v, i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            union_par(u, v);
        }

        int cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            if (par[i] == i)++cnt;
        }

        printf("%d\n", cnt - 1);
    }

    return 0;
}
