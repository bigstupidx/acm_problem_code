
class Solution
{
    private:
        int xfind(vector<int> &num, int n, int target)
        {
            int ll = 0, rr = n - 1, mid;
            while(ll <= rr)
            {
                mid = (ll + rr) / 2;
                if(target > num[mid])
                    ll = mid + 1;
                else
                    rr = mid - 1;
            }
            return ll;
        }
    public:
        int threeSumClosest(vector<int> &num, int target)
        {
            sort(num.begin(), num.end());
            int n = num.size(), maxi, ans;
            bool flag  = false;
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 1; j < n; j++)
                {
                    int sum = (num[i] + num[j]);
                    int xtarget = target - sum;
                    int index  = xfind(num, n, xtarget);
                    for(int k = index; k < n && k < index + 4; k++)
                    {
                        if(k == i || k == j)continue;
                        int temp = abs(target - sum - num[k]);
                        if(!flag ||  maxi > temp)
                        {
                            flag = true;
                            maxi = temp;
                            ans = sum + num[k];
                        }
                    }
                    for(int k = index - 1; k > index - 3 && k >= 0; k--)
                    {
                        if(k == i || k == j)continue;
                        int temp = abs(target - sum - num[k]);
                        if(!flag || maxi > temp)
                        {
                            flag = true;
                            maxi = temp;
                            ans = sum + num[k];
                        }
                    }
                }
            }
            return ans;
        }
};
