class Solution
{
    public:
        vector<int> findSubstring(string S, vector<string> &L)
        {
            int n = S.length(), m = L.size();
            vector<int> ans;
            if (m == 0)
                return ans;
            map<string, int> mp;
            map<string, int> mp_temp;
            map<string, int>::iterator p;
            for (int i = 0; i < m; i++)
            {
                mp[L[i]]++;
            }
            int len = L[0].length(), last_ii = n - m * len;
            for (int i = 0; i <= last_ii; i++)
            {
                mp_temp.clear();
                int k = 0;
                for (int j = i; k < m; j += len, k++)
                {
                    string ss = S.substr(j, len);
                    p = mp.find(ss);
                    if (p == mp.end())
                        break;
                    mp_temp[ss]++;
                    if (mp_temp[ss] > mp[ss])
                        break;
                }
                if (k == m)
                {
                    //cout << i << endl;
                    ans.push_back(i);
                }
            }
            return ans;
        }
};
