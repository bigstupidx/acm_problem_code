class Solution
{
    private:
        struct Node
        {
            int index;
            int sum;
        };
    public:
        int longestValidParentheses(string s)
        {
            int maxi = 0, len = s.length(), curBonus = 0;
            stack<Node> st;
            for(int i = 0; i < len; i++)
            {
                if(s[i] == '(')
                {
                    Node nod;
                    nod.index = i;
                    nod.sum = curBonus;
                    curBonus = 0;
                    st.push(nod);
                }
                else
                {
                    if(st.size() > 0)
                    {
                        Node nod = st.top();
                        st.pop();
                        int temp = i - nod.index + 1 + nod.sum;
                        curBonus = temp;
						//cout<<nod.sum<<endl;
                        maxi = max(maxi, temp);
                    }
                    else
                    {
                        curBonus = 0;
                    }
                }
            }
            return maxi;
        }
};
