class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int n = prices.size();

            if(n == 0)return 0;

            int ans = 0;

            for(int i = 1, temp; i < n; i++)
            {
                temp = prices[i] - prices[i - 1];

                if(temp > 0)ans += temp;
            }

            return ans;
        }
};
