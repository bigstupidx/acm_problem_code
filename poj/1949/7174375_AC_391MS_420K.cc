#include <cstdio>
#include <cstring>

int n, m, tim[10010];

int main(){
	while(scanf("%d", &n)!=EOF){
		int ans=-1;
		for(int i=0;i<n;i++){
			scanf("%d%d", &tim[i], &m);
			if(m==0){
				if(ans<tim[i]){
					ans=tim[i];
				}
			}
			else {
				int maxi=-1, k;
				for(int j=0;j<m;j++){
					scanf("%d", &k);
					k--;
					if(maxi<tim[k]){
						maxi=tim[k];
					}
				}
				tim[i]+=maxi;
				if(ans<tim[i]){
					ans=tim[i];
				}
			}
		}
		//for(int i=0;i<n;i++){
		//	printf("%d ", tim[i]);
		//}
		printf("%d\n", ans);
	}
	return 0;
}
