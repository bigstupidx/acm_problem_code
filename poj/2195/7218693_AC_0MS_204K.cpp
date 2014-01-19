#include <cstdio>
#include <cstring>

struct node{
	int x, y;
}hou[102], man[102];
char str[102];
const int inf = 100000000;

int Lx[102], Ly[102], n, m;
int xflag[102], yflag[102], map[102][102], oppo[102];

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
						if(!yflag[k]&&mini>Lx[j]+Ly[k]-map[j][k]){
							mini=Lx[j]+Ly[k]-map[j][k];
						}
					}
				}
			}
			for(int j=0;j<n;j++){
				if(xflag[j]){
					Lx[j]-=mini;
				}
				if(yflag[j]){
					Ly[j]+=mini;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=inf-map[oppo[i]][i];
	}
	return ans;
}

int ABS(int x){
	return x>0?x:-x;
}

int main(){
	while(scanf("%d%d", &n, &m), n||m){
		int cnt1=0, cnt2=0;
		for(int i=0;i<n;i++){
			scanf("%s", str);
			for(int j=0;j<m;j++){
				if(str[j]=='H'){
					hou[cnt1].x=i;
					hou[cnt1].y=j;
					cnt1++;
				}
				else if(str[j]=='m'){
					man[cnt2].x=i;
					man[cnt2].y=j;
					cnt2++;
				}
			}
		}
		memset(Lx, 0, sizeof(Lx));
		memset(Ly, 0, sizeof(Ly));
		memset(map, 0, sizeof(map));
		for(int i=0;i<cnt1;i++){
			for(int j=0;j<cnt2;j++){
				map[i][j]=ABS(hou[i].x-man[j].x);
				map[i][j]+=ABS(hou[i].y-man[j].y);
//				printf("%d ", map[i][j]);
				map[i][j]=inf-map[i][j];
				if(map[i][j]>Lx[i]){
					Lx[i]=map[i][j];
				}
			}
//			puts("");
		}
		n=cnt1;
		printf("%d\n", km_match());
	}
	return 0;
}
