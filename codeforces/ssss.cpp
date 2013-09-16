#include <cstdio>
#include <cstring>

using namespace std;

int n, arr[52], dp[2][52];

int main(){
	while(scanf("%d", &n)!=EOF){
		for(int i = 0;i<n;i++){
			scanf("%d", arr+i);
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 0;i<n;i++){
			if(i==0){
				dp[1][0] = arr[0];
			}else{
				dp[0][i] = dp[0][i-1] > dp[1][i-1]? dp[0][i-1]:dp[1][i-1];
				dp[1][i] = dp[0][i-1] + arr[i];
			}
		}
		printf("%d\n", dp[1][n-1] > dp[0][n-1]?dp[1][n-1]:dp[0][n-1]);
	}
	return 0;
}
