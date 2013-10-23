class Solution
{
    public:
        static const int N = 3;
        int singleNumber(int A[], int n)
        {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int bits[32] = { 0 };

            for (int tmp, j, i = 0; i < n; i++)
            {
                tmp = A[i];

                if (tmp < 0)
                {
                    ++bits[31];
                    tmp = ~tmp;
                }

                j = 0;

                while (tmp != 0)
                {
                    bits[j] += tmp % 2;
                    tmp >>= 1;
                    ++j;
                }
            }

            int ans = 0;

            for (int i = 30; i >= 0; i--)
            {
                ans = (ans << 1) + bits[i] % N;
            }

            return bits[31] % N == 1 ? -ans - 1 : ans;
        }
};
