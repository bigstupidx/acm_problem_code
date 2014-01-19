class Solution
{
    public:
        void nextPermutation(vector<int> &num)
        {
            bool flag = false;
            int n = num.size();

            for(int i = n - 1; i > 0; i--)
            {
                if(num[i] > num[i - 1])
                {
                    int j = i;

                    while(j < n && num[j] > num[i - 1])++j;

                    --j;
                    int temp = num[j];
                    num[j] = num[i - 1];
                    num[i - 1] = temp;
                    sort(num.begin() + i, num.end());
                    flag = true;
                    break;
                }
            }

            if(!flag)sort(num.begin(), num.end());
        }
};
