#include <cstdio>
#include <cstring>

#define MAXN 100001

using namespace std;


int n, arr[MAXN], c[MAXN];

int my_search(int top, int x)
{
    int left = 0, right = top - 1;

    while(left <= right)
    {
        int mid  = (left + right) / 2;

        if(c[mid] <= x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        memset(c, 0, sizeof(c));

        int top = 0;

        for(int i = 0; i < n; i++)
        {
            int index = my_search(top, arr[i]);


            if(index >= top)
            {
                c[top++] = arr[i];
            }
            else
            {
                c[index] = arr[i];
            }
        }

        printf("%d\n", top);
    }

    return 0;
}
