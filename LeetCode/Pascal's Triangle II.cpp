class Solution
{
    public:
        vector<int> getRow(int rowIndex)
        {
            vector<int> ans;

            if(rowIndex >= 0)
            {
                ans.push_back(1);
            }

            for(int i = 0; i < rowIndex; i++)
            {
                ans.push_back(1);
                int pre_i_1 = ans[0], pre_i;

                for(int j = 1, m = i + 1; j < m; j++)
                {
                    pre_i = ans[j];
                    ans[j] = pre_i_1 + pre_i;
                    pre_i_1 = pre_i;
                }
            }

            return ans;
        }
};
