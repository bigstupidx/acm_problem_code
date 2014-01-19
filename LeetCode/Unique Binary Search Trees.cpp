class Solution
{
    public:
        int numTrees(int n)
        {
            if(n == 0)return 0;

            vector<int> ans;
            ans.push_back(1);
            ans.push_back(1);

            for(int i = 2; i <= n; i++)
            {
                int sum = 0;

                for(int j = i ; j > 0; j--)
                {
                    sum += ans[j - 1] * ans[i - j];
                }

                ans.push_back(sum);
            }

            return ans[n];
        }
};
