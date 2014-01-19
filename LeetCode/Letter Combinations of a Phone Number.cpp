
class Solution
{
    private:
        void solve(vector<string> &mp, string &digits, int index, int size, vector<string> &ans, vector<char> &path)
        {
            if(index == size)
            {
                string xx = "";
                for(int i = 0; i < path.size(); i++)xx += path[i];
                ans.push_back(xx);
                return;
            }
            int ii = digits[index] - '0';
            if(ii == 0)
            {
                solve(mp, digits, index + 1, size, ans, path);
            }
            else
            {
                for(int i = 0; i < mp[ii].size(); i++)
                {
                    char ch = mp[ii][i];
                    path.push_back(ch);
                    solve(mp, digits, index + 1, size, ans, path);
                    path.pop_back();
                }
            }
        }
    public:
        vector<string> letterCombinations(string digits)
        {
            vector<string> mp;
            mp.push_back(" ");//0
            mp.push_back("");//1
            mp.push_back("abc");//2
            mp.push_back("def");//3
            mp.push_back("ghi");//4
            mp.push_back("jkl");//5
            mp.push_back("mno");//6
            mp.push_back("pqrs");//7
            mp.push_back("tuv");//8
            mp.push_back("wxyz");//9

            vector<string> ans;
            vector<char>path;
            solve(mp, digits, 0, digits.length(), ans, path);
            return ans;
        }
};
