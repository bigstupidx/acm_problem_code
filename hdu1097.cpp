#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n, m, arr[10];

void solve(){
	vector<int>ans;
	memset(arr, -1, sizeof(arr));
	int count = 0, fic = 1;
	do{
		fic*=m;
		fic%=10;
		if(arr[fic]==-1){
			ans.push_back(fic);
			arr[fic] = 1;
		}else{
			printf("%d\n", ans[(n-1)%ans.size()]);
			break;
		}
	}while(++count<n);
	if(ans.size()==n){
		printf("%d\n", ans[n-1]);
	}
}

int main(){
	while(scanf("%d%d", &m, &n)!=EOF){
		m%=10;
		solve();
	}
	return 0;
}
