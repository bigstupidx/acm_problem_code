#include <cstdio>
#include <cstring>

char map[2][120][120], ch;
int n, m, day, dir[4][2]={-1, 0, 1, 0, 0, -1, 0, 1};

int main(){
	int nca, x=0;
	scanf("%d", &nca);
	while(nca--){
		if(x)puts("");
		else x=1;
		scanf("%d%d%d", &n, &m, &day);
		for(int i=0;i<n;i++){
			scanf("%s", map[0][i]);
		}
		int now=0;
		while(day--){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					int flag=0;
					ch=map[now][i][j];
					for(int k=0;k<4;k++){
						int ii=i+dir[k][0];
						int jj=j+dir[k][1];
						if(ii<0||ii==n||jj<0||jj==m)continue;
						if(ch=='R'&&map[now][ii][jj]=='P'){
							flag=1;
							ch='P';
							break;
						}
						if(ch=='S'&&map[now][ii][jj]=='R'){
							flag=1;
							ch='R';
							break;
						}
						if(ch=='P'&&map[now][ii][jj]=='S'){
							flag=1;
							ch='S';
							break;
						}
					}
					map[1-now][i][j]=ch;
				}
			}
			now=1-now;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				putchar(map[now][i][j]);
			}
			puts("");
		}
	}
	return 0;
}
