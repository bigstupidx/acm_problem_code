class Solution
{
    public:
        int removeDuplicates(int A[], int n)
        {
            int cnt = 0, j = 0;

            for(int i = 0; i < n; i++)
            {
                if(i == 0 || A[i] != A[i - 1])
                {
                    A[j++] = A[i];
                    cnt = 1;
                }
                else if(A[i] == A[i - 1])
                {
                    if(cnt < 2)
                    {
                        A[j++] = A[i];
                    }

                    cnt = 2;
                }
            }
            return j;
        }
};
