class Solution
{
    private:
        bool conflict(int ii, int jj, int x, int y)
        {
            if(ii == x || jj == y)return true;

            if(abs(ii - x) == abs(jj - y))return true;

            return false;
        }

        bool check(vector<int> &pos, int k)
        {
            for(int i = 0; i < k; i++)
            {
                if(conflict(i, pos[i], k, pos[k]))
                {
                    return false;
                }
            }

            return true;
        }


    public:
        vector<vector<string> > solveNQueens(int n)
        {
            vector<vector<string> > ans;
            vector<int> pos;

            for(int i = 0; i < n; i++)
            {
                pos.push_back(-1);
            }

            int k = 0;

            while(k >= 0)
            {
                ++pos[k];

                while(pos[k] < n && !check(pos, k))
                {
                    ++pos[k];
                }

                if(pos[k] >= n)
                {
                    --k;
                }
                else
                {
                    if(k == n - 1)
                    {
                        vector<string> arr;

                        for(int i = 0; i < n; i++)
                        {
                            string ss;

                            for(int j = 0; j < n; j++)
                            {
                                ss.append(".");
                            }

                            arr.push_back(ss);
                        }

                        for(int i = 0; i < n; i++)
                        {
                            arr[i][pos[i]] = 'Q';
                        }

                        ans.push_back(arr);
                    }
                    else
                    {
                        ++k;
                        pos[k] = -1;
                    }
                }
            }

            return ans;
        }
};
