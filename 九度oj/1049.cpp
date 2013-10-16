#include <cstdio>
#include <cstring>

using namespace std;

char str[1002];

int main()
{
    while (gets(str))
    {
        char ch = getchar();
        getchar();

        for (int i = 0, n = strlen(str); i < n; i++)
        {
            if (str[i] != ch)
            {
                putchar(str[i]);
            }
        }

        puts("");
    }

    return 0;
}
