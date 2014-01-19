class Solution
{
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
        {
            int n = obstacleGrid.size();

            if(n == 0)return 0;

            int m = obstacleGrid[0].size();

            vector<int> f[2];

            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < m; j++)
                    f[i].push_back(0);
            }

            int now = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(obstacleGrid[i][j] == 1)
                        f[1 - now][j] = 0;
                    else
                    {
                        if(i == 0 && j == 0)f[1 - now][0] = 1;
                        else if(i == 0)
                        {
                            f[1 - now][j] = f[1 - now][j - 1];
                        }
                        else if(j == 0)
                        {
                            f[1 - now][0] = f[now][0];
                        }
                        else
                        {
                            f[1 - now][j] = f[now][j] + f[1 - now][j - 1];
                        }
                    }
                }
                now = 1 - now;
            }
            return f[now][m - 1];
        }
};
