class Solution
{
    public:
        int firstMissingPositive(int A[], int n)
        {
            int cnt = 0;
            for(int i = 0, j = 0; i < n; i++)
            {
                if(A[i] <= 0 || A[i] > n + 1)continue;
                if(A[i] > 0)
                {
                    A[j++] = A[i];
                    ++cnt;
                }
            }
            for(int i = 0; i < cnt; i++)
            {
                int index = abs(A[i]);
                if(index > cnt)
                    continue;
                else if(A[index - 1] > 0)
                {
                    A[index - 1] *= -1;
                }
            }
            for(int i = 0; i < cnt; i++)
            {
                if(A[i] > 0)return i + 1;
            }
            return cnt + 1;
        }
};
