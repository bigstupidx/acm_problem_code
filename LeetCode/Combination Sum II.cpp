class Solution
{
    public:

        //bool sameArr(vector<int>arr, vector<int>brr)
        //{
        //    if(arr.size() != brr.size())return false;

        //    for(int i = 0; i < arr.size(); i++)
        //    {
        //        if(arr[i] != brr[i])return false;
        //    }

        //    return true;
        //}


        void solve(vector<int> &arr, vector<int> &index_selected, vector<vector<int>> &ans, int n, int index,  int target)
        {
            if(target == 0)
            {
                vector<int> xx;

                for(int i = 0; i < index_selected.size(); i++)
                {
                    xx.push_back(arr[index_selected[i]]);
                }

                //if(ans.size() == 0 || ans.size() > 0 && !sameArr(ans[ans.size() - 1], xx))
                ans.push_back(xx);

                return;
            }

            if(index >= n || target < 0 || arr[index] > target)return ;

            index_selected.push_back(index);
            solve(arr, index_selected, ans, n, index + 1, target - arr[index]);
            index_selected.pop_back();

            int j = index;

            while(j < n && arr[j] == arr[index])++j;

            solve(arr, index_selected, ans, n, j, target );
        }
        vector<vector<int> > combinationSum2(vector<int> &num, int target)
        {
            vector<vector<int>>ans;
            vector<int>index;

            sort(num.begin(), num.end());

            solve(num, index, ans, num.size(), 0, target);
            return ans;
        }
};
