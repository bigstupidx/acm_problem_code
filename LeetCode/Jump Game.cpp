class Solution
{
    public:
        bool canJump(int A[], int n)
        {
            if(n == 0)return true;

            int last_index = A[0];

            for(int i = 1; i < n; i++)
            {
                if(i > last_index)return false;

                last_index = max(last_index, A[i] + i);

                if(last_index >= n - 1)return true;
            }

            return true;
        }
};
