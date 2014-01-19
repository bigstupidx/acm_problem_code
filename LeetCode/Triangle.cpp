
class Solution
{
    public:
        int minimumTotal(vector<vector<int> > &triangle)
        {
            if(triangle.size() == 0)return 0;

            for(int i = 1, n = triangle.size(); i < n; i++)
            {
                for(int j = 0, m = triangle[i].size(); j < m; j++)
                {
                    if(j == 0)
                    {
                        triangle[i][0] += triangle[i - 1][0];
                    }
                    else if(j == m - 1)
                    {
                        triangle[i][j] += triangle[i - 1][j - 1];
                    }
                    else
                    {
                        triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                    }
                }
            }

            int mini, n = triangle.size() - 1;

            for(int i = 0, m = triangle[n].size(); i < m; i++)
            {
                //printf("%d ", triangle[n][i]);
                if(i == 0 || mini > triangle[n][i])
                {
                    mini = triangle[n][i];
                }
            }

            return mini;
        }
};
