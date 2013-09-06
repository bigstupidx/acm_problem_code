#include <cstdio>
#include <cstring>

bool row[12], col[12], ans[12][12];
char str[12];

int main()
{
    int n, m;

    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(ans, 0, sizeof(ans));

        for(int i = 0; i < n; i++)
        {
            scanf("%s", str);

            for(int j = 0; j < m; j++)
            {
                if(str[j] == 'S')
                {
                    col[j] = true;
                    row[i] = true;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!row[i])
            {
                for(int j = 0; j < m; j++)
                {
                    ans[i][j] = true;
                }
            }
        }

        for(int j = 0; j < m; j++)
        {
            if(!col[j])
            {
                for(int i = 0; i < n; i++)
                {
                    ans[i][j] = true;
                }
            }
        }

        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(ans[i][j])
                {
                    ++sum;
                }
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
