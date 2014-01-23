class Solution
{
    public:
        int maximalRectangle(vector<vector<char> > &matrix)
        {
            int n  = matrix.size();
            if(n == 0)return 0;
            int m = matrix[0].size();

            vector<vector<int> > sum;

            for(int i = 0; i < n; i++)
            {
                vector<int>arr;
                for(int j = 0; j < m; j++)
                {
                    arr.push_back(0);
                }
                sum.push_back(arr);
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(j == 0)
                        sum[i][0] = (matrix[i][0] == '0' ? 0 : 1);
                    else
                        sum[i][j] = matrix[i][j] == '0' ? 0 : sum[i][j - 1] +  1;
                }
            }

            int maxi = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    int k = i, width = m;

                    while(k >= 0)
                    {
                        if(sum[k][j] == 0)break;
                        width = min(width, sum[k][j]);
                        maxi = max(maxi, width * (i - k + 1));
                        k--;
                    }
                }
            }
            return maxi;
        }
};
