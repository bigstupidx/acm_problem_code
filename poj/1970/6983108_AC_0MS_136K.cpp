#include <cstdio>
#include <cstring>

int map[30][30], sx, sy, ex, ey;
int mark[30][30][4], dir[4][2]={1,-1,1,0,1,1,0,1};

bool check(int i, int j, int k){
	int cnt=0, x=map[i][j];
	do{
		if(map[i][j]==x)cnt++;
		else break;
		mark[i][j][k]=1;
		i+=dir[k][0];
		if(i==0||i>19)break;
		j+=dir[k][1];
		if(j==0||j>19)break;
	}while(1);
	if(cnt==5){
		ex=i-dir[k][0];
		ey=j-dir[k][1];
		return true;
	}
	return false;
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		int flag = 0;
		memset(mark, 0, sizeof(mark));
		for(int i=1;i<=19;i++){
			for(int j=1;j<=19;j++){
				scanf("%d", map[i]+j);
			}
		}
		for(int i=1;i<=19;i++){
			for(int j=1;j<=19;j++){
				if(map[i][j]){
					for(int k=0;k<4;k++){
						if(!mark[i][j][k]){
							if(check(i,j,k)){
								sx=i;
								sy=j;
								flag=map[i][j];
								goto exit;
							}
						}
					}
				}
			}
		}
	exit:
		printf("%d\n", flag);
		if(flag){
			if(sy==ey){
				printf("%d %d\n", sx>ex?ex:sx, sy);
			}
			else{
				if(sy<ey){
					printf("%d %d\n", sx, sy);
				}
				else {
					printf("%d %d\n", ex, ey);
				}
			}
		}
	}
	return 0;
}
