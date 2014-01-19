
class Solution
{
    public:
        vector<vector<int> > permuteUnique(vector<int> &num)
        {
            sort(num.begin(), num.end());
            int n = num.size();
            vector<vector<int> > ans;
            if(n > 0)
            {
                vector<int>arr;
                for(int i = 0; i < n; i++)arr.push_back(num[i]);
                ans.push_back(arr);
            }
            while(true)
            {
                int index = -1;
                for(int i = n - 1; i > 0; i--)
                {
                    if(num[i] > num[i - 1])
                    {
                        index = i - 1;
                        break;
                    }
                }
                if(index == -1)break;
                int maxi, index_max = -1;
                for(int i = index + 1; i < n; i++)
                {
                    if(num[i] > num[index])
                    {
                        if(index_max == -1 || num[index_max] - num[index] > num[i] - num[index])
                        {
                            index_max = i;
                        }
                    }
                }
                int temp = num[index];
                num[index] = num[index_max];
                num[index_max] = temp;
                sort(num.begin() + index + 1, num.end());
                vector<int> arr;
                for(int i = 0; i < n; i++)
                {
                    //cout << num[i] << " ";
                    arr.push_back(num[i]);
                }
                //cout << endl;
                ans.push_back(arr);
            }
            return ans;
        }
};
