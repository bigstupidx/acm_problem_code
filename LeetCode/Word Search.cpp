class Solution
{
    private:
        bool check(int i, int j, int n, int m)
        {
            if(i < 0 || j < 0 || i >= n || j >= m)return false;

            return true;
        }
        bool solve(vector<vector<char> > &board, int n, int m, int ii, int jj, string &word, int k, int len, set<int> &path)
        {
            if(k >= len - 1)return true;

//            cout << k << endl;

            static int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1};

            for(int kk = 0; kk < 4; kk++)
            {
                int x = ii + dir[kk][0];
                int y = jj + dir[kk][1];

                if(!check(x, y, n, m))continue;

                //cout << word[k + 1] << " " << board[x][y] << endl;

                if(word[k + 1] != board[x][y])continue;

                int pos = x * m + y;

                if(path.find(pos) != path.end())continue;

                path.insert(pos);

                if(solve(board, n, m, x, y, word, k + 1, len, path))
                {
                    return true;
                }

                path.erase(pos);
            }

            return false;
        }
    public:


        bool exist(vector<vector<char> > &board, string word)
        {
            int n = board.size();

            if(n < 1)
            {
                return word.length() == 0 ? true : false;
            }

            int m = board[0].size();
            int len = word.length();

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(board[i][j] == word[0])
                    {
                        set<int> path;

                        path.insert(i * m + j);

                        if(solve(board, n, m, i, j, word, 0, len, path))
                        {
                            return true;
                        }
                    }
                }
            }

            return false;
        }
};
