#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

char str[10001];

int arr[10001];

int main()
{
    while(scanf("%s", str) != EOF)
    {
        int len = strlen(str), top = 0;

        for(int i = 0; i < len; i++)
        {
            if(str[i] == '+')
            {
                continue;
            }

            arr[top++] = str[i] - '0';
        }

        sort(arr, arr + top);

        for(int i = 0; i < top; i++)
        {
            if(i != 0)
            {
                printf("+%d", arr[i]);
            }
            else
            {
                printf("%d", arr[i]);
            }
        }

        puts("");
    }

    return 0;
}
