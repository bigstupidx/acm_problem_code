class Solution
{
    public:
        int my_search(int x, int dir)
        {
            int ans = 0;

            while (st.find(x) != st.end())
            {
                st.erase(x);
                x += dir;
                ++ans;
            }

            return ans;
        }

        int longestConsecutive(vector<int> &num)
        {
            int n = num.size();

            st.clear();

            for (int i = 0; i < n; i++)
            {
                st.insert(num[i]);
            }

            int ans = 1;

            for (int temp, i = 0; i < n; i++)
            {
                temp = my_search(num[i] - 1, -1) + my_search(num[i] + 1, 1) + 1;
                ans = max(ans, temp);
                st.erase(num[i]);
            }

            return ans;
        }

        unordered_set<int> st;
};
