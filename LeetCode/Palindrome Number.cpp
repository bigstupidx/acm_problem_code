class Solution
{
    public:
        bool isPalindrome(int x)
        {
            if(x < 0)return false;
            if(x < 10)return true;
            long long fic = 10;
            while(fic < x)fic *= 10;
            fic /= 10;
            //cout << fic << endl;
            while(x > 0)
            {
                if(x < 10)return true;
                int aa = x / fic;
                int bb = x % 10;
                if(aa != bb)return false;
                x %= fic;
                x /= 10;
                fic /= 100;
            }
            return true;
        }
};
