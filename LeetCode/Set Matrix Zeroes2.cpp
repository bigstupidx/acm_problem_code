
class Solution
{
    public:
        void setZeroes(vector<vector<int> > &matrix)
        {
            int n = matrix.size();

            if(n < 1)return;

            int m = matrix[0].size();

            vector<bool> flag_col;

            for(int i = 0; i < m; i++)flag_col.push_back(false);

            for(int i = 0; i < n; i++)
            {
                bool flag = false;

                for(int j = 0; j < m; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        flag = true;
                        flag_col[j] = true;
                    }
                }

                if(!flag)continue;

                for(int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(flag_col[j])
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
};
