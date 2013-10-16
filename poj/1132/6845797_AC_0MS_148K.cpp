#include <cstdio>
#include <cstring>

char str[1010], ans[40][40];

int main(){
	int nca;
	scanf("%d", &nca);
	for(int ii=1;ii<=nca;ii++){
		int r, c, len;
		scanf("%d%d%s", &c, &r, str);
		for(int i=0;i<32;i++){
			for(int j=0;j<32;j++){
				ans[i][j]='.';
			}
		}
		len=strlen(str)-1;
		for(int i=0;i<len;i++){
			if(str[i]=='E'){
				c++;
				ans[r-1][c-1]='X';
			}
			else if(str[i]=='W'){
				ans[r][c-1]='X';
				c--;
			}
			else if(str[i]=='N'){
				r++;
				ans[r-1][c]='X';
			}
			else if(str[i]=='S'){
				r--;
				ans[r][c-1]='X';
			}
			//printf("%d %d %c\n", r, c, str[i]);
		}
		printf("Bitmap #%d\n", ii);
		for(int i=31;i>=0;i--){
			for(int j=0;j<32;j++){
				putchar(ans[i][j]);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
