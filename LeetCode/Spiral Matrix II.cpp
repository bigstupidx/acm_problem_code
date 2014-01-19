class Solution
{
    public:
        vector<vector<int> > generateMatrix(int n)
        {
            vector<vector<int> >ans;

            for(int i = 0; i < n; i++)
            {
                vector<int> arr;

                for(int j = 0; j < n; j++)
                {
                    arr.push_back(0);
                }

                ans.push_back(arr);
            }

            int cnt = 1, i = 0, j = 0, len = n - 1;

            while(true)
            {
                if(len < 0)break;

                if(len == 0)
                {
                    ans[i][j] = cnt;
                    break;
                }

                int xlen = len;

                while(xlen > 0)
                {
                    ans[i][j] = cnt++;
                    --xlen, ++j;
                }

                xlen = len; while(xlen > 0)
                {
                    ans[i][j] = cnt++;
                    --xlen, ++i;
                }

                xlen = len; while(xlen > 0)
                {
                    ans[i][j] = cnt++;
                    --xlen, --j;
                }

                xlen = len; while(xlen > 0)
                {
                    ans[i][j] = cnt++;
                    --xlen, --i;
                }

                ++i, ++j;

                len -= 2;
            }

            return ans;
        }
};
