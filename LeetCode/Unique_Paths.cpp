class Solution
{
    public:
        int uniquePaths(int m, int n)
        {
            int ans[102][102];
            memset(ans, 0, sizeof(ans));

            for (int i = 1; i < 101; i++)
            {
                ans[i][1] = 1;
                ans[1][i] = 1;
            }

            for (int i = 2; i <= m; i++)
            {
                for (int j = 2; j <= n; j++)
                {
                    ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
                }
            }

            return ans[m][n];
        }
};
