#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, arr[100010], m;

bool solve(int cnt){
	int ans = 0, i=0, j=n-1;
	for(;;){
		if(i==j){
			if(++ans>cnt)return false;
			return true;
		}
		if(i>j)return true;
		if(arr[i]+arr[j]<=m){
			i++, j--;
			if(++ans>cnt)return false;
		}
		else {
			j--;
			if(++ans>cnt)return false;
		}
	}
	return true;
}

int main(){
	while(scanf("%d", &n)!=EOF){
		scanf("%d", &m);
		for(int i=0;i<n;i++){
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+n);
		int lf=1, rt=n;
		while(lf<=rt){
			int mid=(lf+rt)/2;
			if(solve(mid)){
				rt=mid-1;
			}
			else {
				lf=mid+1;
			}
		}
		printf("%d\n", lf);
	}
	return 0;
}
