#include <cstdio>
#include <cstdlib>

int n, L, K, arr[102];

int solve(){
	int sum = 0, count = 0;
	for(int i = 0;i<2*n;i++){
		sum+=arr[i];
		if(sum<0){
			sum = 0;
			count = 0;
		}else{
			++count;
			if(count>=n) return i - n + 2;
		}
	}
	return -1;
}

int main(){
	while(scanf("%d", &n)!=EOF){
		for(int i = 0;i<n;i++){
			scanf("%d", arr+i);
		}
		scanf("%d%d", &L, &K);
		for(int i = 0;i<n;i++){
			arr[i] -= K*L;
			arr[i+n] = arr[i];
		}
		
		printf("%d\n", solve());
	}
	return 0;
}
