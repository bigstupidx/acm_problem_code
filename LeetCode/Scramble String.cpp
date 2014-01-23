class Solution
{
    private:
        bool check(string x, string y)
        {
            int len = x.length();
            map<char, int> mp1, mp2;
            for(int j = 0; j < len; j++)
            {
                mp1[x[j]]++;
            }
            for(int j = 0; j < len; j++)
            {
                if(mp1.find(y[j]) == mp1.end())
                {
                    return false;
                }
                mp2[y[j]]++;
                if(mp2[y[j]] > mp1[y[j]])
                {
                    return false;
                }
            }
            return true;
        }
    public:
        bool isScramble(string s1, string s2)
        {
            int len = s1.length();
            if(len != s2.length())return false;
            if(len == 0)return true;
            if(len == 1) return s1[0] == s2[0];

            map<char, int> mp1, mp2;
            for(int i = 1; i < len; i++)
            {
                string sx = s1.substr(0, i);
                string sy = s1.substr(i, len - i);
                string bx = s2.substr(0, i);
                string by = s2.substr(i, len - i);

                bool ok = check(sx, bx) && check(sy, by);
                if(ok && isScramble(sx, bx) && isScramble(sy, by))
                {
                    return true;
                }

                string ax = s2.substr(len - i, i);
                string ay = s2.substr(0, len - i);

                ok = check(sx, ax) && check(sy, ay);
                if(ok && isScramble(sx, ax) && isScramble(sy, ay))
                {
                    return true;
                }
            }

            return false;
        }
};
