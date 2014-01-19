
class Solution
{
    private :
        int xfind(vector<int> &num, int n, int target)
        {
            int ll = 0, rr = n - 1, mid;
            while(ll <= rr)
            {
                mid = (ll + rr) / 2;
                if(num[mid] <= target)
                {
                    ll = mid + 1;
                }
                else
                {
                    rr = mid - 1;
                }
            }
            return ll - 1;
        }
        bool isFoundInAns(vector<vector<int> > &ans, vector<int> &xx)
        {
            if(ans.size() == 0)return false;
            vector<int>yy = ans[ans.size() - 1];
            for(int i = 0; i < 4; i++)
            {
                if(xx[i] != yy[i])return false;
            }
            return true;
        }
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target)
        {
            sort(num.begin(), num.end());
            int n = num.size();
            vector<vector<int> > ans;
            for(int i = 0; i < n ; i++)
            {
                for(int j = i + 1; j < n; j++)
                {
                    for(int k = j + 1; k < n; k++)
                    {
                        int sum = num[i] + num[j] + num[k];
                        if(target - sum < num[k])
                            break;
                        int index = xfind(num, n, target - sum);
                        if(index > k && index < n && num[index] == target - sum)
                        {
                            cout << num[i] << num[j] << num[k] << endl;
                            vector<int> arr;
                            arr.push_back(num[i]);
                            arr.push_back(num[j]);
                            arr.push_back(num[k]);
                            arr.push_back(num[index]);
                            if(!isFoundInAns(ans, arr))
                                ans.push_back(arr);
                        }
                        while(k + 1 < n && num[k] == num[k + 1])++k;
                    }
                    while(j + 1 < n && num[j] == num[j + 1])++j;
                }
                while(i + 1 < n && num[i] == num[i + 1])++i;
            }
            return ans;
        }
};

