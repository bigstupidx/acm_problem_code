class Solution
{
    public:
        int minPathSum(vector<vector<int> > &grid)
        {
            vector<vector<int> >sum;
            int n = grid.size();

            if (n == 0)return 0;

            int m = grid[0].size();

            //cout << n << m << endl;

            for (int i = 0; i < n; i++)
            {
                vector<int> row;

                for (int j = 0; j < m; j++)
                {
                    if (j == 0)
                    {
                        if (i == 0)row.push_back(grid[0][0]);
                        else row.push_back(sum[i - 1][0] + grid[i][0]);
                    }
                    else
                    {
                        if (i == 0)row.push_back(row[j - 1] + grid[0][j]);
                        else row.push_back(min(sum[i - 1][j], row[j - 1]) + grid[i][j]);
                    }
                }

                sum.push_back(row);
            }

            return sum[n - 1][m - 1];
        }
};
