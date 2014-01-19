
class Solution
{
    private:
        string change(int x)
        {
            string result = "";
            if(x == 0)result += "0";
            else
            {
                while(x > 0)
                {
                    result += (char)(x % 10 + '0');
                    x /= 10;
                }
            }
            result += "|";
            return result;
        }
    public:
        vector<string> anagrams(vector<string> &strs)
        {
            vector<int> flag;
            for(int i = 0; i < 26; i++)flag.push_back(0);
            int n = strs.size();
            map<string, int> mp;
            map<string, int> ::iterator p;
            vector<int> pos;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < 26; j++)flag[j] = 0;
                for(int j = 0, m = strs[i].length(); j < m; j++)
                {
                    ++flag[strs[i][j] - 'a'];
                }
                string xx = "";
                for(int j = 0; j < 26; j++)xx += change(flag[j]);
                //cout << xx << endl;
                p = mp.find(xx);
                if(p == mp.end())
                {
                    mp.insert(make_pair(xx, i));
                }
                else
                {
                    pos.push_back(p->second);
                    pos.push_back(i);
                }
            }
            vector<string>ans;
            sort(pos.begin(), pos.end());
            for(int i = 0, m = pos.size(); i < m; i++)
            {
                if(i == 0 || pos[i] != pos[i - 1])
                {
                    ans.push_back(strs[pos[i]]);
                }
            }
            return ans;
        }
};
