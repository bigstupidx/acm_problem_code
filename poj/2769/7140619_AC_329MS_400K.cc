#include <cstdio>
#include <cstring>

bool flag[1000010];
int n, arr[1000010];

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d", &arr[i]);
		}
		int ans=n;
		for(;;ans++){
			for(int i=0;i<ans;i++){
				flag[i]=false;
			}
			bool test=false;
			for(int i=0;i<n;i++){
				if(flag[arr[i]%ans]){
					test=true;
					break;
				}
				flag[arr[i]%ans]=true;
			}
			if(!test)break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
