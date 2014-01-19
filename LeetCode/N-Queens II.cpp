
class Solution
{
    private:
        bool conflict(int x1, int y1, int x2, int y2)
        {
            if(x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2))return true;

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
        int totalNQueens(int n)
        {
            vector<int> pos;

            for(int i = 0; i < n; i++)pos.push_back(-1);

            int k = 0, ans = 0;

            while(k >= 0)
            {
                ++pos[k];

                while(pos[k] < n && !check(pos, k))
                {
                    ++pos[k];
                }

                if(pos[k] >= n)--k;
                else
                {
                    if(k == n - 1)++ans;
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
