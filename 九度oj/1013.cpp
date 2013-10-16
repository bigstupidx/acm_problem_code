#include <cstdio>
#include <cstring>

using namespace std;

struct Node
{
    char name[20];
    int time_a, time_b;
} node[102];

int main()
{
    int nca;
    scanf("%d", &nca);

    while (nca--)
    {
        int n, start = 0, end = 0;
        scanf("%d", &n);

        for (int h, m, s, i = 0; i < n; i++)
        {
            scanf("%s", node[i].name);

            scanf("%d:%d:%d", h, m, s);
            node[i].time_a = h * 3600 + m * 60 + s;

            scanf("%d:%d:%d", h, m, s);
            node[i].time_b = h * 3600 + m * 60 + s;

            if (node[i].time_a < node[start].time_a)
            {
                start = i;
            }

            if (node[i].time_b > node[end].time_b)
            {
                end = i;
            }
        }

        printf("%s %s\n", node[start].name, node[end].name);
    }

    return 0;
}
