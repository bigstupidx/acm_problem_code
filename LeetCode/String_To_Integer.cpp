

class Solution
{
    public:
        int atoi(const char *str)
        {
            if (str == NULL)return 0;

            int len = strlen(str);

            int  i = 0, sign = 1;

            while (i < len && str[i] == ' ')++i;

            if (i >= len)return 0;

            if (str[i] == '+' || str[i] == '-')
            {
                sign = str[i] == '-' ? -1 : 1;
                ++i;
            }

            bool flag = true;

            int ans = 0, start = i;

            for (; i < len; i++)
            {
                if (str[i] > '9' || str[i] < '0')
                {
                    flag = false;
                    break;
                }

                ans = ans * 10 + (str[i] - '0');
            }

            if (i - start > 10)
            {
                return sign == 1 ? 2147483647 : -2147483648;
            }

            if (i - start == 10)
            {
                str += start;

                if (sign == 1 && strcmp(str, "2147483647") >= 0)
                {
                    return 2147483647;
                }

                if (sign == -1 && strcmp(str, "2147483648") >= 0)
                {
                    return -2147483648;
                }
            }

            return ans * sign;
        }
};
