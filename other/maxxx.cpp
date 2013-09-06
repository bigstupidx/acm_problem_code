#include <cstdio>
#include <cstdlib>

int n, arr[102];
int f[2][102];

int main(){
	while(scanf("%d", &n)!=EOF){
		for(int i = 0;i<n;i++){
			scanf("%d", arr+i);
		}
		
		for(int i = 0;i<n;i++){
			if(i==0){
				f[0][0] = 0;
				f[1][0] = arr[0]>0?arr[0]:0;
			}
			else{
				f[0][i] = f[0][i-1] > f[1][i-1]? f[0][i-1]:f[1][i-1];
				
				int temp = f[0][i-1] + arr[i];
				f[1][i] = temp>f[1][i-1] ? temp:f[1][i-1];
				f[1][i] = f[1][i]>0?f[1][i]:0;
			}
		}
		printf("%d\n", f[0][n-1] > f[1][n-1]? f[0][n-1]:f[1][n-1]);
	}
	return 0;
}
