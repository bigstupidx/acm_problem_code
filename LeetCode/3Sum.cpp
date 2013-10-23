class Solution
{
    public:
        vector<vector<int> > threeSum(vector<int> &num)
        {
            sort(num.begin(), num.end());

            vector<vector<int> > ans;

            vector<int> last_ans;

            int len = num.size(), i = 0, j, k, sum;

            while (i < len)
            {
                if (num[i] > 0)
                    break;

                j = i + 1, k = len - 1, sum = -num[i];

                while (j < k)
                {
                    int temp = num[j] + num[k];

                    if (temp == sum)
                    {
                        vector<int> yy;
                        yy.push_back(num[i]);
                        yy.push_back(num[j]);
                        yy.push_back(num[k]);
                        ans.push_back(yy);

                        j++;

                        while (j < k && num[j] == num[j - 1])++j;

                        --k;

                        while (j < k && num[k] == num[k + 1])--k;
                    }

                    else if (temp > sum)
                    {
                        --k;

                        while (j < k && num[k] == num[k + 1])--k;
                    }
                    else
                    {
                        ++j;

                        while (j < k && num[j] == num[j - 1])++j;
                    }
                }

                ++i;

                while (i < len && num[i] == num[i - 1])++i;
            }

            return ans;
        }
};
