#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, arr[2][1002];

int main(){
	while(scanf("%d", &n), n){
		
		for(int i=0;i<n;i++){
			scanf("%d", &arr[0][i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d", &arr[1][i]);
		}
		sort(arr[0], arr[0]+n);
		sort(arr[1], arr[1]+n);
		
		int ans=0, j=n-1, cnt=0;
		for(int i=n-1;i>=0;i--){
			while(j >= 0 && arr[1][j] > arr[0][i])j--;
			if(j>=0){
				if(arr[1][j]==arr[0][i])cnt++;
				else {
					ans++;
				}
				j--;
			}
			else {
				break;
			}
//			printf("%d %d\n", arr[0][i], arr[1][j+1]);
		}
		printf("%d\n", (ans-(n-cnt-ans))*200);
	}
	return 0;
}

