#include <cstdio>
#include <cstring>

int n, m;

int xabs(int x)
{
    return x >= 0 ? x : -x;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        __int64 ans = 0;
        int start = 1, temp;

        for(int i = 0; i < m; i++)
        {
            scanf("%d", &temp);
            ans += xabs(temp + n - start) % n;
            start = temp;
        }

        printf("%I64d\n", ans);
    }

    return 0;
}
