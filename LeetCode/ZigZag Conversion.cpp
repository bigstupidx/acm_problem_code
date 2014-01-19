class Solution
{
    public:
        string convert(string s, int nRows)
        {
            if(nRows == 1)return s;
            int len = s.length();
            vector<vector<char> > ans;
            for(int i = 0; i < nRows; i++)
            {
                vector<char> x;
                ans.push_back(x);
            }
            for(int j = 0, speed = 1, i = 0; i < len; i++)
            {
                ans[j].push_back(s[i]);
                j += speed;
                if(speed == 1 && j == nRows)
                {
                    speed = -1;
                    j = nRows - 2;
                }
                else if(speed == -1 && j == -1)
                {
                    speed = 1;
                    j = 1;
                }
            }
            string result = "";
            for(int i = 0; i < nRows; i++)
            {
                for(int j = 0; j < ans[i].size(); j++)
                {
                    result += ans[i][j];
                }
            }

            return result;
        }
};
