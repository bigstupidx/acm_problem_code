class Solution
{
    private:
        void generate(vector<string> &ans, int ii, int n, int pre_pos, vector<int> &pos)
        {
            if(ii == n)
            {
                string xx = "";
                for(int i = 0, m = 2 * n; i < m; i++)
                {
                    xx += '.';
                }
                for(int i = 0; i < pos.size(); i++)xx[pos[i]] = '(';
                for(int i = 0, m = n * 2; i < m; i++)
                {
                    if(xx[i] == '.')xx[i] = ')';
                }
                ans.push_back(xx);
                return;
            }
            for(int i = pre_pos + 1, m = ii * 2; i <= m; i++)
            {
                pos.push_back(i);
                generate(ans, ii + 1, n, i, pos);
                pos.pop_back();
            }
        }
    public:
        vector<string> generateParenthesis(int n)
        {
            vector<string> ans;
            vector<int> pos;
            generate(ans, 0, n, -1, pos);

            return ans;
        }
};
