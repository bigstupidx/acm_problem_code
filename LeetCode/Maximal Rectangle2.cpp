class Solution
{
    public:
        int maximalRectangle(vector<vector<char> > &matrix)
        {
            int n  = matrix.size();
            if(n == 0)return 0;
            int m = matrix[0].size();

            vector<int> sum, pre, next;
            for(int i = 0; i < m; i++)
            {
                sum.push_back(0);
                pre.push_back(0);
                next.push_back(0);
            }

            int maxi = 0;
            stack<int> st;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(matrix[i][j] == '0')sum[j] = 0;
                    else sum[j] += 1;
                }
                while(!st.empty())st.pop();
                for(int j = 0; j < m; j++)
                {
                    while(!st.empty() && sum[st.top()] >= sum[j])st.pop();
                    if(st.empty())pre[j] = -1;
                    else pre[j] = st.top();
                    st.push(j);
                }
                while(!st.empty())st.pop();
                for(int j = m - 1; j >= 0; j--)
                {
                    while(!st.empty() && sum[st.top()] >= sum[j])st.pop();
                    if(st.empty())next[j] = m;
                    else next[j] = st.top();
                    st.push(j);
                }
                for(int j = 0; j < m; j++)
                {
                    maxi = max(maxi, sum[j] * (next[j] - pre[j] - 1));
                }
            }
            return maxi;
        }
};
