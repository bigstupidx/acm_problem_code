
class Solution
{
    public:
        int my_search(int A[], int ll, int rr, int target)
        {
            if(ll > rr)return -1;

            if(A[ll] == target)return ll;

            if(A[rr] == target)return rr;

            int mid = (ll + rr) / 2, index;

            if(A[mid] == target)return mid;


            bool need_search = true;

            if(ll < mid && A[ll] < A[mid])
            {
                if( target < A[mid] && target > A[ll])
                    return my_search(A, ll, mid - 1, target);

                need_search = false;
            }

            if(need_search && (index = my_search(A, ll, mid - 1, target)) != -1)return index;

            need_search = true;

            if(rr > mid && A[rr] > A[mid] )
            {
                if(target > A[mid] && target < A[rr])
                    return my_search(A, mid + 1, rr, target);

                need_search = false;
            }

            if(need_search && (index = my_search(A, mid + 1, rr, target)) != -1)return index;

            return -1;
        }

        int search(int A[], int n, int target)
        {
            return my_search(A, 0, n - 1, target);
        }
};
