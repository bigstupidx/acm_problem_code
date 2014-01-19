#include <cstdio>

int n, arr[102];

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)break;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int xx, cnt = 0;
        scanf("%d", &xx);

        for (int i = 0; i < n; i++)
        {
            cnt += (xx == arr[i]);
        }

        printf("%d\n", cnt);
    }

    return 0;
}
