
class Solution
{
    public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {
            int n = numbers.size();

            vector<int> arr;

            for (int i = 0; i < n; i++)
            {
                arr.push_back(numbers[i]);
            }

            sort(arr.begin(), arr.end());

            int xx, yy;

            for (int j = n - 1, i = 0; i < n && i < j; i++)
            {
                xx = arr[i];
                yy = target - xx;

                while (arr[j] > yy)--j;

                if (arr[j] == yy)break;
            }

            vector<int> ans;
            bool flag1 = false, flag2 = false;

            //cout << xx << "  " << yy << endl;

            for (int i = 0; i < n; i++)
            {
                if (!flag1 && numbers[i] == xx)
                {
                    flag1 = true;
                    ans.push_back(i + 1);
                }

                else if (!flag2 && numbers[i] == yy)
                {
                    flag2 = true;
                    ans.push_back(i + 1);
                }
            }

            return ans;
        }
};
