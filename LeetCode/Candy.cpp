class Solution
{
    public:
        int candy(vector<int> &ratings)
        {
            vector<int> lf;
            vector<int> rt;

            int n = ratings.size(), sum = 0;

            for (int i = 0; i < n; i++)
            {
                lf.push_back(0);
                rt.push_back(0);
            }

            for (int tmp = 0, i = 0; i < n; i++)
            {
                if (i == 0 || ratings[i] <= ratings[i - 1])
                {
                    tmp = 0;
                }
                else if (ratings[i] > ratings[i - 1])
                {
                    ++tmp;
                }

                lf[i] = tmp;
            }

            for (int tmp, i = n - 1; i >= 0; i--)
            {
                if (i == n - 1 || ratings[i] <= ratings[i + 1])
                {
                    tmp = 0;
                }
                else if (ratings[i] > ratings[i + 1])
                {
                    ++tmp;
                }

                rt[i] = tmp;

            }

            for (int i = 0; i < n; i++)
            {
                if (lf[i] < rt[i])
                {
                    sum += rt[i] + 1;
                }
                else
                {
                    sum += lf[i] + 1;
                }
            }

            return sum;
        }
};
