class Solution
{
    public:
        int searchInsert(int A[], int n, int target)
        {
            int ll = 0, rr = n - 1, mid;

            while(ll <= rr)
            {
                mid = (ll + rr) / 2;

                if(A[mid] >= target)
                {
                    rr = mid - 1;
                }
                else
                {
                    ll = mid + 1;
                }
            }

            return ll;
        }
};
