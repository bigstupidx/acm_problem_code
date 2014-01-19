class Solution
{
    public:
        int binary_search(int A[], int n, int target, bool lager)
        {
            int ll = 0, rr = n - 1, mid;

            while(ll <= rr)
            {
                mid = (ll + rr) / 2;

                if(lager)
                {
                    if(A[mid] > target)
                    {
                        rr = mid - 1;
                    }
                    else
                    {
                        ll = mid + 1;
                    }
                }
                else
                {
                    if(A[mid] >= target)
                    {
                        rr = mid - 1;
                    }
                    else
                    {
                        ll = mid + 1;
                    }
                }
            }

            return ll - 1;
        }

        vector<int> searchRange(int A[], int n, int target)
        {
            vector<int>ans;
            int rr = binary_search(A, n , target, true);

            if(A[rr] != target)
            {
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }

            int ll = binary_search(A, n, target, false) + 1;
            ans.push_back(ll);
            ans.push_back(rr);
            return ans;
        }
};
