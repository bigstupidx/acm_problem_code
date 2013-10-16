#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;

int main()
{

    do
    {
        bool flag = false;

        int x, y, minx, miny, maxx, maxy;

        while (scanf("%d%d", &x, &y) != EOF)
        {
            if (x == 0 && y == 0)break;

            if (!flag)
            {
                minx = maxx = x;
                miny = maxy = y;
            }
            else
            {
                minx = min(minx, x);
                miny = min(miny, y);
                maxx = max(maxx, x);
                maxy = max(maxy, y);
            }

            flag = true;
        }

        if (!flag)break;

        printf("%d %d %d %d\n", minx, miny, maxx, maxy);
    }
    while (true);

    return 0;
}
