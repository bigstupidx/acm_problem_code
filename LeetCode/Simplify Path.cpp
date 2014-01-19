
class Solution
{
    public:
        string simplifyPath(string path)
        {
            stack<string> st;

            path.append("/");

            for(int last_index = 1, i = 1; i < path.length(); i++)
            {
                if(path[i] == '/')
                {
                    if(i - last_index > 0)
                    {
                        string xx = path.substr(last_index, i - last_index);

                        if(xx == ".")
                        {
                        }
                        else if(xx == "..")
                        {
                            if(st.size() > 0)st.pop();
                        }
                        else
                        {
                            st.push(xx);
                        }
                    }

                    last_index = i + 1;

                }
            }

            string ans;

            if(!st.empty())
            {
                ans = st.top();
                st.pop();
            }
            else
            {
                ans = "";
            }

            while(!st.empty())
            {
                ans = st.top() + "/" + ans;
                st.pop();
            }

            ans = "/" + ans;
            return ans;
        }
};
