class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int ans = 0, n = prices.size();

            vector<int> profit[2];
            profit[0].reserve(n);
            profit[1].reserve(n);

            for(int i = 0; i < n; i++)
            {
                profit[0][i] = profit[1][i] = 0;
            }

            static int inf = 1000000000;

            int ans1 = 0, ans2 = 0, mini = inf, maxi = inf;

            for(int i = 0, j; i < n; i++)
            {
                j = n - i - 1;

                if(mini == inf || mini > prices[i])mini = prices[i];

                profit[0][i] = ans1 = max(prices[i] - mini, ans1);

                if(maxi == inf || maxi < prices[j])maxi = prices[j];

                profit[1][j] = ans2 = max(ans2, maxi - prices[j]);
            }

            for(int i = 0; i < n; i++)
            {
                ans = max(ans, profit[0][i] + profit[1][i]);
            }

            return ans;
        }
};
