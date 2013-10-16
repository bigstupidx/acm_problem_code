#include <cstdio>
#include <cstring>

char str[102];

int main()
{
    while (scanf("%s", str) != EOF)
    {
        if (strcmp(str, "E") == 0)break;

        int len = strlen(str);
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < len; i++)
        {
            if (str[i] == 'Z')++cnt0;
            else if (str[i] == 'O')++cnt1;
            else if (str[i] == 'J')++cnt2;
        }

        while (cnt0 > 0 || cnt1 > 0 || cnt2 > 0)
        {
            if (cnt0 > 0) { putchar('Z'); --cnt0; }

            if (cnt1 > 0) { putchar('O'); --cnt1; }

            if (cnt2 > 0) { putchar('J'); --cnt2; }
        }
		puts("");
    }

    return 0;
}
