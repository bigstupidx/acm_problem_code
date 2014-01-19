#include <cstdio>
#include <cstring>

char str[2][102];
int ans[102][102], pre[102][102][2], flag[102];

int main(){
	str[0][0]=str[1][0]=' ';
	while(scanf("%s%s", str[0]+1, str[1]+1)!=EOF){
		int n=strlen(str[0]);
		int m=strlen(str[1]);
		memset(ans, 0, sizeof(ans));
		memset(pre, -1, sizeof(pre));
		memset(flag, 0, sizeof(flag));
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				if(str[0][i]==str[1][j]){
					ans[i][j]=ans[i-1][j-1]+1;
					pre[i][j][0]=i-1;
					pre[i][j][1]=j-1;
				}
				else {
					ans[i][j]=ans[i][j-1];
					pre[i][j][0]=i;
					pre[i][j][1]=j-1;
					if(ans[i-1][j]>ans[i][j-1]){
						ans[i][j]=ans[i-1][j];
						pre[i][j][0]--;
						pre[i][j][1]++;
					}
				}
			}
		}
		int ii=n-1, jj=m-1;
		while(pre[ii][jj][0]!=-1){
			int i=ii, j=jj;
			ii=pre[i][j][0];
			jj=pre[i][j][1];
			if(ans[ii][jj]!=ans[i][j]){
				flag[i]=j;
			}
			//printf("%d %d %d\n", ii, jj, ans[ii][jj]);
		}
		int j=1;
		for(int i=1;i<n;i++){
			if(flag[i]){
				int x=flag[i];
				for(int k=j;k<x;k++){
					putchar(str[1][k]);
				}
				j=x+1;
			}
			putchar(str[0][i]);
		}
		while(j<m){
			putchar(str[1][j]);
			j++;
		}
		puts("");
	}
	return 0;
}
