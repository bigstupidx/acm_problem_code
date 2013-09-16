#include <cstdio>
#include <cstring>

char map[7][250][250];
int n, fic[7]={1,1, 3, 9, 27, 81, 243};

void pre_done(){
	map[1][0][0]='X';
	for(int i=2;i<7;i++){
		int m=fic[i], x=m/3;
		for(int j=0;j<m;j++){
			for(int k=0;k<m;k++){
				map[i][j][k]=' ';
			}
			map[i][j][m]=0;
		}
		for(int j=0;j<x;j++){
			for(int k=0;k<x;k++){
				map[i][j][k]=map[i-1][j][k];
				map[i][j][k+2*x]=map[i-1][j][k];
				map[i][j+2*x][k]=map[i-1][j][k];
				map[i][j+x][k+x]=map[i-1][j][k];
				map[i][j+2*x][k+2*x]=map[i-1][j][k];
			}
		}
	}
}

int main(){
	pre_done();
	while(scanf("%d", &n), n!=-1){
		int m=fic[n];
		for(int i=0;i<m;i++){
			puts(map[n][i]);
		}
		puts("-");
	}
	return 0;
}
