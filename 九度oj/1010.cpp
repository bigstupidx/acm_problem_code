#include <cstdio>
#include <cstring>

char str[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int getNum(char num[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(str[i], num) == 0)
        {
            return i;
        }
    }

    return -1;
}

char input[20];

int main()
{

    do
    {
        int a = 0, b = 0;

        while (scanf("%s", input) != EOF)
        {
            if (strcmp(input, "+") == 0)
            {
                break;
            }

            a = a * 10 + getNum(input);
        }

        while (scanf("%s", input) != EOF)
        {
            if (strcmp(input, "=") == 0)
            {
                break;
            }

            b = b * 10 + getNum(input);
        }

        if (a == 0 && b == 0)break;

        printf("%d\n", a + b);
    }
    while (true);

    return 0;
}
