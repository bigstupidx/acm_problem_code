
class Solution
{
    public:
        bool isInterleave(string s1, string s2, string s3)
        {
            int n = s1.length();
            int m = s2.length();
            int len = s3.length();

            if(n + m != len)return false;

            if(n == 0)
            {
                if(s2 == s3)return true;

                return false;
            }

            if(m == 0)
            {
                if(s1 == s3)return true;

                return false;
            }

            vector<vector<bool> >flag;

            ++m; ++n;

            for(int i = 0; i < n; i++)
            {
                vector<bool> arr;

                for(int j = 0; j < m; j++)
                {
                    arr.push_back(false);
                }

                flag.push_back(arr);
            }

            flag[0][0] = true;

            for(int i = 0; i < n; i++)
            {
                for(int j  = 0; j < m; j++)
                {
                    if(i == 0 && j == 0)continue;

                    if(i == 0 && flag[i][j - 1] && s3[j - 1] == s2[j - 1])
                    {
                        flag[i][j] = true;
                    }

                    if(j == 0 && flag[i - 1][j] && s3[i - 1] == s1[i - 1])
                    {
                        flag[i][j] = true;
                    }

                    if(i > 0 && j > 0 && flag[i - 1][j] && s3[i + j - 1] == s1[i - 1])
                        flag[i][j] = true;

                    if(i > 0 && j > 0 && flag[i][j - 1] && s3[i + j - 1] == s2[j - 1])
                        flag[i][j] = true;
                }
            }

            //for(int i = 0; i < n; i++)
            //{
            //    for(int j = 0; j < m; j++)
            //    {
            //        cout << flag[i][j] << " ";
            //    }

            //    puts("");
            //}

            return flag[n - 1][m - 1];
        }
};
