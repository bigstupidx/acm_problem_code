class Solution
{
    public:
        vector<vector<int> > subsets(vector<int> &S)
        {
            vector<vector<int> >ans;
            int n = S.size();

            if(n < 1)return ans;

            sort(S.begin(), S.end());

            vector<int> flag;
            flag.reserve(n);

            for(int i = 0; i < n; i++)flag.push_back(0);


            do
            {
                vector<int> arr;

                for(int i = 0; i < n; i++)
                {
                    if(flag[i] == 1)arr.push_back(S[i]);
                }

                ans.push_back(arr);
                //update

                int carry = 1;
                bool check = false;

                for(int temp, i = 0; i < n; i++)
                {
                    temp = flag[i] + carry;
                    flag[i] = temp % 2;
                    carry = temp / 2;

                    if(flag[i] == 1)check = true;
                }

                if(!check)break;
            }
            while(true);;

            return ans;
        }
};
