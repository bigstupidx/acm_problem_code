class Solution
{
    public:
        int sqrt(int x)
        {
            if (x <= 0)return 0;

            long long left = 0, right = x, mid;

            while (left <= right)
            {
                mid = (left + right) / 2;

                if (mid * mid > x)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            return left - 1;
        }
};
