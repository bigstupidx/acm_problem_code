#include <cstdio>
#include <cstring>

char str[100];
int cnt[300], mm[10];

int main()
{
    while (gets(str))
    {
        if (strcmp(str, "#") == 0)break;

        int n = strlen(str);

        for (int i = 0; i < n; i++)
        {
            mm[i] = str[i];
        }

        gets(str);

        memset(cnt, 0, sizeof(cnt));

        for (int i = 0, m = strlen(str); i < m; i++)
        {
            int v = str[i];

            for (int j = 0; j < n; j++)
            {
                if (v == mm[j])
                {
                    ++cnt[v];
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            printf("%c %d\n", mm[i], cnt[mm[i]]);
        }
    }

    return 0;
}
