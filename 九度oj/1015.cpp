#include <cstdio>

int xx[9];

void pre_done()
{
    xx[0] = 1;

    for (int i = 1; i < 9; i++)
    {
        xx[i] = xx[i - 1] * 10;
    }
}

int main()
{
    int a, b, k;
    pre_done();

    while (scanf("%d%d%d", &a, &b, &k) != EOF)
    {
        if (a == 0 && b == 0)break;

        if (a % xx[k] == b % xx[k])puts("-1");
        else printf("%d\n", a + b);
    }

    return 0;
}
