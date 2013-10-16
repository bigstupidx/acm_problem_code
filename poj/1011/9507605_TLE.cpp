#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

bool used[65];
int n, arr[65];

bool DFS(int i, int sum, int totalLength, int length){
	if(totalLength==0){
		sum-=length;
		totalLength = length;
		i = n-1;
	}
	if(sum==0 && totalLength==length){
		return true;
	}
	if(i<0)return false;
	if(used[i]){
		return DFS(i-1, sum, totalLength, length);
	}
	if(arr[i]<=totalLength){
		used[i] = true;
		if(DFS(i-1, sum, totalLength - arr[i], length)){
			return true;
		}
		used[i] = false;
		return DFS(i-1, sum, totalLength, length);
	}
	while(i>=0&&arr[i]>totalLength)--i;
	return DFS(i, sum, totalLength, length);
}

int main(){
	while(scanf("%d", &n), n){
		int sum = 0;
		for(int i = 0;i<n;i++){
			scanf("%d", arr+i);
			sum+=arr[i];
		}
		sort(arr, arr + n);
		for(int i = arr[n-1];i<=sum;i++){
			if(sum%i==0){
				memset(used, 0, sizeof(used));
				if(DFS(n-1, sum, i, i)){
					printf("%d\n", i);
					break;		
				}
			}
		}
	}
	return 0;
}
