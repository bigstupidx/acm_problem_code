class Solution
{
    public:
        int numDistinct(string S, string T)
        {
            int n = S.length();
            int m = T.length();
            vector<int> f[2];
            for(int j = 0; j <= n; j++)
            {
                f[0].push_back(0);
                f[1].push_back(1);
            }
            int now = 0;
            for(int i = 1; i <= m; i++)
            {
                f[now][0] = 0;
                for(int j = 1; j <= n; j++)
                {
                    f[now][j] = f[now][j - 1] + (S[j - 1] == T[i - 1] ? f[1 - now][j - 1] : 0);
                }
                now = 1 - now;
            }
            return f[1 - now][n];
        }
};
