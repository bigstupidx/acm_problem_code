#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		bool dig[10];
		for (int index, i = 0; i < 9; i++) {
			memset(dig, false, sizeof(dig));
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					continue;
				index = board[i][j] - '0';
				if (dig[index])
					return false;
				dig[index] = true;
			}

			memset(dig, false, sizeof(dig));
			for (int j = 0; j < 9; j++) {
				if (board[j][i] == '.')
					continue;
				index = board[j][i] - '0';
				if (dig[index])
					return false;
				dig[index] = true;
			}

			int ii = (i / 3) * 3;
			int jj = (i % 3) * 3;
			memset(dig, false, sizeof(dig));
			for (int j = 0; j < 9; j++) {
				int xx = j / 3 + ii;
				int yy = j % 3 + jj;
				if (board[xx][yy] == '.')
					continue;
				index = board[xx][yy] - '0';
				if (dig[index])
					return false;
				dig[index] = true;
			}
		}
		return true;
	}
};

int main() {
	return 0;
}
