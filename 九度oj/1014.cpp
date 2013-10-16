#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node
{
    char name[22];
    int count;
    bool operator <(const Node a)const
    {
        if (a.count > count)return true;

        if (a.count < count)return false;

        if (strcmp(a.name, name) < 0)
        {
            return false;
        }

        return true;
    }
} nod[1002];

int n, m, g, sc[12];

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)break;

        scanf("%d%d", &m, &g);

        for (int i = 1; i <= m; i++)scanf("%d", sc + i);

        for (int mm, i = 0; i < n; i++)
        {
            scanf("%s", &nod[i].name);
            scanf("%d", &mm);
            nod[i].count = 0;

            for (int k, j = 0; j < mm; j++)
            {
                scanf("%d", &k);
                nod[i].count += sc[k];
            }
        }

        sort(nod, nod + n);

        for (int i = 0; i < n; i++)
        {
            if (nod[i].count >= g)
            {
                printf("%s %d\n", nod[i].name, nod[i].count);
            }
            else
            {
                break;
            }
        }
    }


    return 0;
}
