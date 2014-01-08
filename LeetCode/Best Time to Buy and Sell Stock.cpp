class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int mini = -1, ans = 0;
        for(int i = 0, tmp, n = prices.size();i<n;i++){
            if(mini==-1 || mini>prices[i])mini = prices[i];
            tmp = prices[i] - mini;
            if(tmp>ans)ans = tmp;
        }
        return ans;
    }
};
