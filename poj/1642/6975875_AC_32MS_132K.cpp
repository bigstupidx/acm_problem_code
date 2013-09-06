#include <cstdio>
#include <cstring>

int n, map[22][22], ans[22][22];

int main(){
	int flag=0;
	while(scanf("%d", &n), n){
		
		if(flag)puts("\n");
		else flag=1;
		memset(map, 0, sizeof(map));
		for(int j,t,i=0;i<n;i++){
			j=0;
			while(scanf("%d", &t), t){
				map[i][j++]=t;
			}
		}
		int i, j;
		memset(ans, 0, sizeof(ans));
		for(i=0;i<n;i++){
			j=0;
			while(map[i][j]){
				for(int k=0;k<map[i][j];k++){
					ans[k][i]++;
				}
				j++;
			}
		}
		i=0;
		while(ans[i][0]){
			j=0;
			while(ans[i][j]){
				printf("%d ", ans[i][j]);
				j++;
			}
			puts("");
			i++;
		}
		puts("");
		
		memset(ans, 0, sizeof(ans));
		for(i=0;i<n;i++){
			j=0;
			while(map[i][j]){
				for(int k=0;k<map[i][j];k++){
					ans[j][k]++;
				}
				j++;
			}
		}
		
		i=0;
		while(ans[i][0]){
			j=0;
			while(ans[i][j]){
				printf("%d ", ans[i][j]);
				j++;
			}
			puts("");
			i++;
		}
	}
	return 0;
}
