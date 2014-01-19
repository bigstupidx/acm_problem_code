class Solution
{
    public:
        void getNext(char *s, int len, vector<int> &next)
        {
            int j = 0, k = -1;
            next[0] = -1;

            while(j < len)
            {
                if(k != -1 && s[k] != s[j])
                {
                    k = next[k];
                }
                else
                {
                    ++k;
                    ++j;

                    if(s[k] == s[j])
                    {
                        next[j] = next[k];
                    }
                    else
                    {
                        next[j] = k;
                    }
                }
            }
        }

        char *strStr(char *haystack, char *needle)
        {
            if(haystack == NULL || needle == NULL)return NULL;

            int len1 = strlen(haystack);
            int len2 = strlen(needle);

//			printf("%d %d\n", len1, len2);

            if(len2 == 0)
            {
                return haystack;
            }

            vector<int> next;
            next.reserve(len2 + 1);

            for(int i = 0, n = len2 + 1; i < n; i++) {next.push_back(0);}

            getNext(needle, len2, next);

            int i = 0, j = 0;

            while(i < len1)
            {
                if(j == -1 ||  haystack[i] == needle[j])
                {
                    ++j;
                    ++i;

                    if(j == len2)
                    {
                        return haystack + (i - len2);
                    }
                }
                else
                {
                    j = next[j];
                }
            }

            return NULL;
        }
};
