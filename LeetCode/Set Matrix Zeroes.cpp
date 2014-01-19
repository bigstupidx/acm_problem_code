
class Solution
{
    public:
        void setZeroes(vector<vector<int> > &matrix)
        {
            int n = matrix.size();

            if(n < 1)return;

            int m = matrix[0].size();

            vector<bool> flag_col, flag_row;

            for(int i = 0; i < n; i++) flag_row.push_back(false);

            for(int i = 0; i < m; i++)flag_col.push_back(false);

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        flag_row[i] = true;
                        flag_col[j] = true;
                    }
                }
            }

            for(int j = 0; j < m; j++)
            {
                for(int i = 0; i < n; i++)
                {
                    if(flag_row[i] || flag_col[j])
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
};
