

class Solution
{
    private:
        int getNum(string s, int start, int end)
        {
            int num = 0;
            if(end != start && s[start] == '0')return 256;
            for(int i = start; i <= end; i++)
            {
                num = num * 10 + (s[i] - '0');
                if(num > 255)return 256;
            }
            return num;
        }
        void solve(string s, int cnt, int start, int len, vector<int> &pos, vector<string> &ans)
        {
            if(cnt == 3 && start < len)
            {
                int num = getNum(s, start, len - 1);
                if(num <= 255)
                {
                    string result = "";
                    for(int j = 0, i = 0; i < len; i++)
                    {
                        result += s[i];
                        if(j < 3 && pos[j] == i)
                        {
                            result += ".";
                            ++j;
                        }
                    }
                    ans.push_back(result);
                }
                return;
            }
            for(int i = start; i < len; i++)
            {
                int num = getNum(s, start, i);
                if(num > 255)break;
                pos.push_back(i);
                solve(s, cnt + 1, i + 1, len, pos, ans);
                pos.pop_back();
            }
        }
    public:
        vector<string> restoreIpAddresses(string s)
        {
            vector<string> ans;
            vector<int> pos;
            solve(s, 0, 0, s.length(), pos, ans);
            //for(int i = 0; i < ans.size(); i++)cout << ans[i] << endl;
            return ans;
        }
};

