
class Solution
{
    public:
        void merge(int A[], int m, int B[], int n)
        {
            vector<int> ans;
            int i = 0, j = 0;

            while(i < m || j < n)
            {
                int temp;

                if(i < m && j < n)
                {
                    if(A[i] < B[j])
                    {
                        temp = A[i++];
                    }
                    else
                    {
                        temp = B[j++];
                    }
                }
                else if(i < m)
                {
                    temp = A[i++];
                }
                else
                {
                    temp = B[j++];
                }

                ans.push_back(temp);
            }

            m += n;

            for(int i = 0; i < m; i++)
            {
                A[i] = ans[i];
            }
        }
};
