class Solution
{
    private:
        void solve(vector<int> &num, int start, int size, int k, vector<int> &fic)
        {
            if(size <= 1)return;
            int index = start;
            sort(num.begin() + start, num.end());
            while(k >= fic[size - 1])
            {
                k -= fic[size - 1];
                ++index;
            }
            int temp = num[start];
            num[start] = num[index];
            num[index] = temp;
            solve(num, start + 1, size - 1, k, fic);
        }
    public:
        string getPermutation(int n, int k)
        {
            vector<int> fic;
            fic.push_back(0);
            fic.push_back(1);
            for(int i = 2; i <= n; i++)fic.push_back(fic[i - 1]*i);

            if(k < 1 || k > fic[n])return "";

            vector<int> num;
            for(int i = 1; i <= n; i++)num.push_back(i);
            solve(num, 0, n, k - 1, fic);
            string result;
            for(int i = 0; i < n; i++)
            {
                //cout << num[i] << " ";
                result += (char)(num[i] + '0');
            }
            //cout << endl;
            return result;
        }
};
