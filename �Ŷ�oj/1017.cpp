#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node
{
    int u, v, d;
    bool operator <(const Node &a)const
    {
        return a.d < d;
    }
} nod[5000];

int n, m, par[102];

int find_par(int x)
{
    if (par[x] == x)
    {
        return x;
    }

    return par[x] = find_par(par[x]);
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)break;

        m = n * (n - 1) / 2;

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &nod[i].u, &nod[i].v, &nod[i].d);
        }

        sort(nod, nod + m);

        int ans = 0, cnt = n - 1;

        for (int i = 0; i < m; i++)
        {
            int ii = find_par(nod[i].u);
            int jj = find_par(nod[i].v);

            if (ii != jj)
            {
                par[ii] = jj;
                ans += nod[i].d;

                if (--cnt == 0)break;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
