

class Solution
{
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S)
        {
            vector<vector<int> > ans;
            int n = S.size();

            if(n == 0)return ans;

            sort(S.begin(), S.end());
            vector<int> cnt;
            vector<int> arr;
            vector<int> count;
            int top = 0;

            for(int i = 0; i < n; i++)
            {
                if(i == 0 || S[i] != S[i - 1])
                {
                    arr.push_back(S[i]);
                    cnt.push_back(2);
                    count.push_back(0);
                    ++top;
                }
                else
                {
                    ++cnt[top - 1];
                }
            }

            n = top;

            do
            {
                vector<int> brr;

                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < count[i]; j++)
                    {
                        brr.push_back(arr[i]);
                    }
                }

                ans.push_back(brr);

                int carry = 1, temp = 0;

                bool flag = false;

                for(int i = 0; i < n; i++)
                {
                    temp = carry + count[i];
                    count[i] = temp % cnt[i];
                    carry = temp / cnt[i];

                    if(count[i] > 0)flag = true;
                }

                if(!flag)break;
            }
            while(true);

            return ans;
        }
};
