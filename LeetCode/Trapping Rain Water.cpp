class Solution
{
    public:
        int trap(int A[], int n)
        {
            vector<int> pre, next;
            for(int i = 0; i < n; i++)
            {
                pre.push_back(0);
                next.push_back(0);
            }
            for(int i = 0; i < n; i++)
            {
                if(i == 0 || A[i] >= pre[i - 1])pre[i] = A[i];
                else pre[i] = pre[i - 1];
            }
            for(int i = n - 1; i >= 0; i--)
            {
                if(i == n - 1 || A[i] >= next[i + 1])next[i] = A[i];
                else next[i] = next[i + 1];
            }
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += min(next[i], pre[i]) - A[i];
            }
            return sum;
        }
};
