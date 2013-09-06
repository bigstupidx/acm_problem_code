#include <cstdio>
#include <cstring>

int num[2], arr[2][10];

int main(){
	while(scanf("%d%d", &num[0], &num[1]), num[0]||num[1]){
		int tem;
		if(num[0]>num[1]){
			tem=num[0];num[0]=num[1];num[1]=tem;
		}
		memset(arr, 0, sizeof(arr));
		for(int i=0;i<2;i++){
			for(int j=0;j<10;j++){
				int n=num[i], k=1, x, y;
				while(n){
					x=n%10;
						if(n<10){
							if(j<x){
								arr[i][j]+=k;
							}
							else if(j==x){
								arr[i][j]+=num[i]%k+1;
							}
						}
						else{
							if(j<x){
								arr[i][j]+=(n/10+1)*k;
							}
							else {
								arr[i][j]+=(n/10)*k;
							}
							if(j==x){
								arr[i][j]+=num[i]%k+1;
							}
						}
						k*=10;
						n/=10;
				}
			}
			int n=num[i], fi=10;;
			while(n){
				n/=10;
				if(n<10)break;
				arr[i][0]-=fi;
				fi*=10;
			}
		}
		/*
		for(int i=0;i<2;i++){
			for(int j=0;j<10;j++){
				printf("%d ", arr[i][j]);
			}
			puts("");
		}
		*/
		//printf("%d %d\n", arr[0][0], arr[1][0]);
		while(num[0]){
			tem=num[0]%10;
			arr[0][tem]--;
			num[0]/=10;
		}
		for(int i=0;i<10;i++){
			printf("%d ", arr[1][i]-arr[0][i]);
		}
		puts("");
	}
	return 0;
}
