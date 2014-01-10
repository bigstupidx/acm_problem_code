
class Solution
{
    public:
        void solve(vector<vector<char>> &board)
        {
            vector<vector<int>>mark;

            for(int i = 0, n = board.size(); i < n; i++)
            {
                vector<int> xx;

                for(int j = 0, m = board[i].size(); j < m; j++)
                {
                    if(board[i][j] == 'X')
                        xx.push_back(1);
                    else
                        xx.push_back(0);
                }

                mark.push_back(xx);
            }

            static int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1};

            for(int i = 0, n = board.size(); i < n; i++)
            {
                for(int j = 0, m = board[i].size(); j < m; j++)
                {
                    if(mark[i][j] == 0 && ( i == 0 || j == 0 || i == board.size() - 1 || j == board[i].size() - 1 ))
                    {
                        //printf("test %d %d\n", i, j);
                        queue<int> Q;
                        mark[i][j] = -1;
                        Q.push(i * m + j);

                        while(!Q.empty())
                        {
                            int pos = Q.front();
                            Q.pop();
                            int x = pos / m;
                            int y = pos % m;

                            for(int k = 0; k < 4; k++)
                            {
                                int ii = dir[k][0] + x;
                                int jj = dir[k][1] + y;

                                if(ii < 0 || ii >= n || jj < 0 || jj >= m || board[ii][jj] == 'X' || mark[ii][jj] == -1)continue;

                                mark[ii][jj] = -1;
                                Q.push(ii * m + jj);
                            }
                        }
                    }
                }
            }

            for(int i = 0, n = board.size(); i < n; i++)
            {
                for(int j = 0, m = board[i].size(); j < m; j++)
                {
                    if(mark[i][j] == -1)
                    {
                        board[i][j] = 'O';
                    }
                    else
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
};
