#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, arr[250002];

int main(){
	while(scanf("%d", &n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d", arr+i);
		}
		sort(arr, arr+n);
		if(n%2){
			printf("%.1lf\n", (double)(arr[n/2]));
		}
		else{
			double ax=arr[n/2];
			ax+=arr[n/2-1];
			printf("%.1lf\n", ax/2);
		}
	}
	return 0;
}
