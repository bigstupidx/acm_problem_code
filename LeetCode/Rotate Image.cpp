class Solution
{
    public:
        void rotate(vector<vector<int> > &matrix)
        {
            int n = matrix.size(), m = n / 2;
            for(int i = 0; i < m; i++)
            {
                for(int j = i, x = n - i - 1; j < x; j++)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[n - j - 1][i];
                    matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                    matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                    matrix[j][n - i - 1] = temp;
                }
            }
        }
};
