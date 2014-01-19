class Solution
{
    public:
        void solve(vector<int> &arr, vector<int> &index_selected, vector<vector<int>> &ans, int n, int index,  int target)
        {
            if(target == 0)
            {
                vector<int> xx;

                for(int i = 0; i < index_selected.size(); i++)
                {
                    xx.push_back(arr[index_selected[i]]);
                }

                ans.push_back(xx);

                return;
            }

            if(index >= n || target < 0 || arr[index] > target)return ;

            int cnt = target / arr[index] + 1;

            for(int i = 0; i < cnt; i++)
            {
                for(int j = 0; j < i; j++)index_selected.push_back(index);

                solve(arr, index_selected, ans, n, index + 1, target - i * arr[index]);

                for(int j  = 0; j < i; j++)index_selected.pop_back();
            }

        }
        vector<vector<int> > combinationSum(vector<int> &candidates, int target)
        {
            vector<vector<int>>ans;
            vector<int>index;
            vector<int> zz;

            for(int i = 0; i < candidates.size(); i++)
            {
                if(i == 0 || candidates[i] != candidates[i - 1])
                {
                    zz.push_back(candidates[i]);
                }
            }

            sort(zz.begin(), zz.end());

            solve(zz, index, ans, candidates.size(), 0, target);
            return ans;
        }
};
