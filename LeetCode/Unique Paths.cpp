class Solution
{
    public:
        int uniquePaths(int m, int n)
        {
            if(n == 0 && m == 0)return 0;
            vector<int> f[2];
            ++m; ++n;

            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < m; j++)
                    f[i].push_back(0);
            }

            for(int j = 0; j < m; j++)f[0][j] = 1;

            int now = 0;
            for(int i = 1; i < n; i++)
            {
                for(int j = 1; j < m; j++)
                {
                    if(j == 1)f[1 - now][j] = 1;
                    else f[1 - now][j] = f[now][j] + f[1 - now][j - 1];
                }
                now = 1 - now;
            }
            return f[1 - now][m - 1];
        }
};
