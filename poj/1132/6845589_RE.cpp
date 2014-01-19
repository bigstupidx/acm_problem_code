#include <cstdio>
#include <cstring>

char str[40][40], tem[200];

int main(){
	int nca;
	scanf("%d", &nca);
	for(int ii=1;ii<=nca;ii++){
		int r, c;
		scanf("%d%d%s", &r, &c, tem);
		for(int i=0;i<32;i++){
			for(int j=0;j<32;j++){
				str[i][j]='.';
			}
		}
		int len=strlen(tem)-1;
		for(int i=0;i<len;i++){
			if(tem[i]=='E'){
				c++;
				str[r-2][c]='X';
			}
			else if(tem[i]=='W'){
				c--;
				str[r-1][c+1]='X';
			}
			else if(tem[i]=='S'){
				str[r-2][c]='X';
				r--;
			}
			else{
				str[r-1][c+1]='X';
				r++;
			}
		}
		printf("Bitmap #%d\n", ii);
		for(int i=31;i>=0;i--){
			for(int j=0;j<32;j++){
				putchar(str[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
