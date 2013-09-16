#include <cstdio>
#include <cstring>
/**
 * dp[i][j]表示第一个串的前i个字符和第二个串的前j个字符能否组成第三个串的前i+j个字符
 * 成立条件如下：
 * dp[i][j-1]==true && str[1][j]==str[2][i+j];
 * or
 * dp[i-1][j]==true && str[0][i]==str[2][i+j];
 * */

bool dp[1000][1000];
char str[3][1002];

int main() {
//	freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		scanf("%s%s%s", str[0], str[1], str[2]);
		int n = strlen(str[0]);
		int m = strlen(str[1]);

		memset(dp, false, sizeof(dp));
		dp[0][0] = true;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (j > 0 && dp[i][j - 1] && str[1][j - 1] == str[2][i + j - 1]) {
					dp[i][j] = true;

				} else if (i > 0 && dp[i - 1][j] && str[0][i - 1] == str[2][i + j - 1]) {
					dp[i][j] = true;
				}
			}
		}
		printf("Data set %d: %s\n", ii, dp[n][m] ? "yes" : "no");
	}
	return 0;
}
