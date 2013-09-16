#include <cstdio>
#include <cstring>

#define MAXN 101

using namespace std;

int n, mp[MAXN][MAXN], sum[MAXN][MAXN], arr[MAXN];

int main() {
//	freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &mp[i][j]);
				if (j == 0) {
					sum[i][0] = mp[i][0];
				} else {
					sum[i][j] = mp[i][j] + sum[i][j - 1];
				}
			}
		}
		int ans = -1000000000;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (i == 0) {
						arr[k] = sum[k][j];
					} else {
						arr[k] = sum[k][j] - sum[k][i - 1];
					}
				}
				int maxi = -1000000000, total = 0;
				for (int k = 0; k < n; k++) {
					total += arr[k];
					if (total < 0)
						total = 0;
					maxi = total > maxi ? total : maxi;
				}
				ans = ans > maxi ? ans : maxi;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
