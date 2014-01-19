
class Solution
{
    public:
        string solve(vector<string> &words, int start, int end, int total_len, int len, bool last)
        {
            int cnt = end - start + 1;
            //cout << cnt << "  " << len << "  " << total_len << "  " << endl;
            string result;

            total_len -= cnt;

            if(cnt == 1 || last)
            {
                for(int i = start; i <= end; i++)
                {
                    result.append(words[i]);
                    len -= words[i].length();

                    if(len > 0)
                    {
                        --len; result.append(" ");
                    }

                }

                while(len > 0) {--len; result.append(" ");}
            }
            else
            {
                int xwidth = (len - total_len) / (cnt - 1);
                result.append(words[start]);
                int xx = (len - total_len) % (cnt - 1);

                for(int i = start + 1; i <= end; i++)
                {
                    if(xx > 0) {result.append(" "); --xx;}

                    int yy = xwidth;

                    while(yy) {result.append(" "); --yy;}

                    result.append(words[i]);
                }
            }

            return result;
        }


        vector<string> fullJustify(vector<string> &words, int len)
        {
            vector<string> ans;
            int index = 0, total_length = 0, cnt = 0;
            int n = words.size();

            for(int i = 0; i < n; i++)
            {
                string word = words[i];

                if(total_length + word.length() > len)
                {
                    ans.push_back(solve(words, index, i - 1, total_length, len, false));
                    total_length = word.length() + 1;
                    cnt = 1;
                    index = i;
                }
                else
                {
                    total_length += word.length() + 1;
                    ++cnt;
                }

                //cout << word << endl;
            }

            if(index < n) {ans.push_back(solve(words, index, n - 1, total_length, len, true));}

            return ans;
        }
};
