#include <cstdio>
#include <cstring>

int n, arr[10002];

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)break;

        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);

            if (arr[i] >= 0)
            {
                flag = false;
            }
        }

        if (flag)
        {
            printf("0 %d %d\n", arr[0], arr[n - 1]);
            continue;
        }

        int maxi = -1, ii = 0, jj = 0, sum = 0;

        for (int tempi = 0, tempj = 0, i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum < 0)
            {
                sum = 0;
                tempi = tempj = i + 1;
            }
            else if (sum > 0)
            {
                tempj = i;
            }

            if (sum > maxi)
            {
                ii = tempi;
                jj = tempj;
                maxi = sum;
            }
        }

        printf("%d %d %d\n", maxi, arr[ii], arr[jj]);
    }

    return 0;
}
