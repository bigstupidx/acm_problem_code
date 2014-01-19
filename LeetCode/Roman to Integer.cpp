
class Solution
{
    private:
        int getNum(string &s, int ll, int rr)
        {
            if(ll > rr)return 0;
            if(ll == rr)
            {
                switch(s[ll])
                {
                    case 'I': return 1;
                    case 'V': return 5;
                    case 'X': return 10;
                    case 'L': return 50;
                    case 'C': return 100;
                    case 'D': return 500;
                    case 'M': return 1000;
                }
            }
            int maxi = 0, index = -1;
            for(int i = ll; i <= rr; i++)
            {
                if(s[i] == 'I' && maxi < 1) {maxi = 1; index = i;}
                else if(s[i] == 'V' && maxi < 5) {maxi = 5; index = i;}
                else if(s[i] == 'X' && maxi < 10) {maxi = 10; index = i;}
                else if(s[i] == 'L' && maxi < 50) {maxi = 50; index = i;}
                else if(s[i] == 'C' && maxi < 100) {maxi = 100; index = i;}
                else if(s[i] == 'D' && maxi < 500) {maxi = 500; index = i;}
                else if(s[i] == 'M' && maxi < 1000) {maxi = 1000; index = i;}
            }
            return maxi - getNum(s, ll, index - 1) + getNum(s, index + 1, rr);
        }
    public:
        int romanToInt(string s)
        {
            return getNum(s, 0, s.length() - 1);
        }
};
