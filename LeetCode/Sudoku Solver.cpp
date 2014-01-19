
class Solution
{
    public:
        bool flag[10];
        vector<int> canBeSure(int ii, int jj, vector<vector<char>> &board)
        {
            memset(flag, false, sizeof(flag));

            int x = ii / 3 * 3, y = jj / 3 * 3;

            for(int i = 0; i < 9; i++)
            {
                if(board[i][jj] != '.')
                {
                    flag[board[i][jj] - '0'] = true;
                }

                if(board[ii][i] != '.')
                {
                    flag[board[ii][i] - '0'] = true;
                }

                if(board[x + i / 3][y + i % 3] != '.')
                {
                    flag[board[x + i / 3][y + i % 3] - '0'] = true;
                }
            }

            vector<int> ans;

            for(int i = 1; i < 10; i++)
            {
                if(!flag[i])
                {
                    ans.push_back(i);
                }
            }

            return ans;
        }

        bool solve(vector<vector<char>> &board, vector<int> &queue, int index)
        {
            if(index >= queue.size())return true;

            int i = queue[index] / 9;
            int j = queue[index] % 9;

            vector<int> ans = canBeSure(i, j, board);

            if(ans.size() == 0)return false;

            for(int k = 0; k < ans.size(); k++)
            {
                board[i][j] = ans[k] + '0';

                if(solve(board, queue, index + 1))
                {
                    return true;
                }
            }

            board[i][j] = '.';

            return false;
        }

        void solveSudoku(vector<vector<char> > &board)
        {
            vector<int> input;

            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    if(board[i][j] == '.')
                    {
                        input.push_back(i * 9 + j);
                    }
                }
            }


            solve(board, input, 0);
        }
};
