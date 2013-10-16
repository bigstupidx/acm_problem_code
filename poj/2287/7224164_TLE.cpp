#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 10000000;
int Lx[1002], Ly[1002], oppo[1002];
int n, arr[2][1002], map[1002][1002], xflag[1002], yflag[1002];

bool path(int s){
	xflag[s]=1;
	for(int i=0;i<n;i++){
		if(!yflag[i]&&Lx[s]+Ly[i]==map[s][i]){
			yflag[i]=1;
			if(oppo[i]==-1||path(oppo[i])){
				oppo[i]=s;
				return true;
			}
		}
	}
	return false;
}

int km_match(){
	memset(oppo, -1, sizeof(oppo));
	for(int i=0;i<n;i++){
		while(1){
			memset(xflag, 0, sizeof(xflag));
			memset(yflag, 0, sizeof(yflag));
			if(path(i))break;
			int mini=inf;
			for(int j=0;j<n;j++){
				if(xflag[j]){
					for(int k=0;k<n;k++){
						if(!yflag[k]&&Lx[j]+Ly[k]-map[j][k]<mini){
							mini=Lx[j]+Ly[k]-map[j][k];
						}
					}
				}
			}
			for(int j=0;j<n;j++){
				if(xflag[j]){
					Lx[j]-=mini;
				}
			}
			for(int j=0;j<n;j++){
				if(yflag[j]){
					Ly[j]+=mini;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(oppo[i]!=-1){
			ans+=map[oppo[i]][i];
		}
	}
	return ans;
}

int main(){
	while(scanf("%d", &n), n){
		for(int i=0;i<n;i++){
			scanf("%d", &arr[0][i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d", &arr[1][i]);
		}
		sort(arr[0], arr[0]+n);
		sort(arr[1], arr[1]+n);
		memset(Ly, 0, sizeof(Ly));
		for(int i=0;i<n;i++){
			Lx[i]=-inf;
			for(int j=0;j<n;j++){
				if(arr[0][i]<arr[1][j]){
					map[i][j]=-1;
				}
				else if(arr[0][i]>arr[1][j]){
					map[i][j]=1;
				}
				else {
					map[i][j]=0;
				}
				if(Lx[i]<map[i][j]){
					Lx[i]=map[i][j];
				}
			}
		}
		printf("%d\n", 200*km_match());
	}
	return 0;
}

