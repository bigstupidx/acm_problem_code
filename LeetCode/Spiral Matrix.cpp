class Solution
{
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix)
        {
            vector<int>ans;
            int n = matrix.size();

            if(n == 0)return ans;

            int m = matrix[0].size();
            int i = 0, j = 0, len_row = n - 1, len_col = m - 1;

            while(true)
            {
                if(len_row < 0 || len_col < 0)
                {
                    break;
                }

                if(len_col == 0 && len_row == 0)
                {
                    ans.push_back(matrix[i][j]);
                    break;
                }

                if(len_col == 0)
                {
                    int k = 0;

                    while(k <= len_row)
                    {
                        ans.push_back(matrix[i + k][j]);
                        k++;
                    }

                    break;
                }

                if(len_row == 0)
                {
                    int k = 0;

                    while(k <= len_col)
                    {
                        ans.push_back(matrix[i][j + k]);
                        k++;
                    }

                    break;
                }


                int len = len_col;

                while(len > 0)
                {
                    ans.push_back(matrix[i][j]);
                    --len, ++j;
                }

                len = len_row;

                while(len > 0)
                {
                    ans.push_back(matrix[i][j]);
                    --len, ++i;
                }

                len = len_col;

                while(len > 0)
                {
                    ans.push_back(matrix[i][j]);
                    --len, --j;
                }

                len = len_row;

                while(len > 0)
                {
                    ans.push_back(matrix[i][j]);
                    --len, --i;
                }

                ++i, ++j;

                len_row -= 2;
                len_col -= 2;
            }

            return ans;
        }
};
