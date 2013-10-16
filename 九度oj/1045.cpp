#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < 101; i++)
        {
            if (i * 5 > n)break;

            for (int j = 0, x = 101 - i; j < x; j++)
            {
                if (i * 5 + j * 3 > n)break;

                int k = 100 - i - j;

                if (i * 5 + j * 3 + (k + 2) / 3 <=  n)
                {
                    printf("x=%d,y=%d,z=%d\n", i, j, k);
                }
            }
        }
    }

    return 0;
}
