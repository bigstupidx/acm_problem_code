#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

char ans[300][300];
int n, map[20][20];

int main()
{
	int nca = 0;
	while(scanf("%d",&n), n){
		
		queue<int>Q;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				scanf("%d",&map[i][j]);
				if(!map[i][j]){
					Q.push(n*i+j);
				}
			}
		}
		for(int i=0;i<n;i++)
			map[i][n]==-1;
		while(!Q.empty()){
			int x = Q.front();Q.pop();
			int i=x/n;
			int j=x%n;
			if(i==0){
				if(j==0)
					map[0][0]=3;
				else if(map[i][j-1]==3||map[i][j+1]==3||map[i][j+1]==1)
					map[i][j]=3;
				else if(map[i][j-1]==4||map[i][j+1]==4||map[i][j-1]==1)
					map[i][j]=4;
				else Q.push(x);
			}
			else if(j==0){
				if(map[i-1][0]==3||map[i+1][0]==3||map[i+1][0]==1)
					map[i][j]=3;
				else if(map[i-1][0]==2||map[i+1][0]==2||map[i-1][0]==1)
					map[i][j]=2;
				else Q.push(x);
			}
			else{
				int up=-1, left=-1;
				if(map[i-1][j]==2||map[i-1][j]==5||map[i-1][j]==1)
					up=1;
				else if(map[i+1][j]==2||map[i+1][j]==5||map[i+1][j]==-1)
					up=1;
				else if(map[i-1][j]==3||map[i-1][j]==4||map[i+1][j]==1)
					up=0;
				else if(map[i+1][j]==3||map[i+1][j]==4||map[i-1][j]==-1)
					up=0;
				if(up!=-1){
					if(map[i][j-1]==2||map[i][j-1]==3||map[i][j+1]==1)
						left=1;
					else if(map[i][j+1]==2||map[i][j+1]==3||map[i][j-1]==-1)
						left=1;
					else if(map[i][j+1]==5||map[i][j+1]==4||map[i][j-1]==1)
						left=0;
					else if(map[i][j-1]==5||map[i][j-1]==4||map[i][j+1]==-1)
						left=0;
					if(left!=-1){
						if(up==1&&left==1)map[i][j]=2;
						else if(up==1&&left==0)map[i][j]=5;
						else if(up==0&&left==1)map[i][j]=3;
						else map[i][j]=4;
					}
					else Q.push(x);
				}
				else Q.push(x);
			}
		}
		int r = 4*n-3, c= 4*n+3;
		for(int i=0;i<r;i++){
			for(int j=1;j<c;j++){
				ans[i][j]=' ';
				if(i%2==0&&j%2==0){
					if(i%4==0&&j%4==0)
						ans[i][j]='O';
					else if(i%4!=0&&j%4==0||i%4==0)
						ans[i][j]='H';
				}
			}
			ans[i][1]='*';
			ans[i][c]='*';
			ans[i][c+1]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]==1){
					ans[i*4][(j+1)*4-1]='-';
					ans[i*4][(j+1)*4+1]='-';
				}
				else if(map[i][j]==-1){
					ans[i*4-1][(j+1)*4]='|';
					ans[i*4+1][(j+1)*4]='|';
				}
				else if(map[i][j]==2){
					ans[i*4-1][(j+1)*4]='|';
					ans[i*4][(j+1)*4-1]='-';
				}
				else if(map[i][j]==3){
					ans[i*4][(j+1)*4-1]='-';
					ans[i*4+1][(j+1)*4]='|';
				}
				else if(map[i][j]==4){
					ans[i*4+1][(j+1)*4]='|';
					ans[i*4][(j+1)*4+1]='-';
				}
				else{
					ans[i*4][(j+1)*4+1]='-';
					ans[i*4-1][(j+1)*4]='|';
				}
			}
		}
		if(nca!=0)puts("");
		printf("Case %d:\n\n",++nca);
		for(int i=0;i<c;i++)putchar('*');
		puts("");
		for(int i=0;i<r;i++){
			puts(ans[i]+1);
		}
		for(int i=0;i<c;i++)putchar('*');
		puts("");
	}
	return 0;
}
