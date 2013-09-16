#include <cstdio>
#include <cstring>

int n;
char map[102][102], str[10010], tem[100];

void shake_matrix(){
	char ch;
	for(int i=1;i<=n;i++){
		if(i%2){
			ch=map[1][i];
			for(int j=1;j<n;j++){
				map[j][i]=map[j+1][i];
			}
			map[n][i]=ch;
		}
		else{
			ch=map[n][i];
			for(int j=n;j>1;j--){
				map[j][i]=map[j-1][i];
			}
			map[1][i]=ch;
		}
	}
}

void rattle_matrix(){
	char ch;
	for(int i=1;i<=n;i++){
		if(i%2){
			ch=map[i][n];
			for(int j=n;j>1;j--){
				map[i][j]=map[i][j-1];
			}
			map[i][1]=ch;
		}
		else{
			ch=map[i][1];
			for(int j=1;j<n;j++){
				map[i][j]=map[i][j+1];
			}
			map[i][n]=ch;
		}
	}
}

void roll_matrix(){
	char ch;
	int m=n/2+1, x;
	for(int i=1;i<m;i++){
		if(i%2){
			ch=map[i][i];
			x=n-i+1;
			for(int j=i;j<x;j++){
				map[j][i]=map[j+1][i];
			}
			for(int j=i;j<x;j++){
				map[x][j]=map[x][j+1];
			}
			for(int j=x;j>i;j--){
				map[j][x]=map[j-1][x];
			}
			for(int j=x;j>i;j--){
				map[i][j]=map[i][j-1];
			}
			map[i][i+1]=ch;
		}
		else{
			ch=map[i][i];
			x=n-i+1;
			for(int j=i;j<x;j++){
				map[i][j]=map[i][j+1];
			}
			for(int j=i;j<x;j++){
				map[j][x]=map[j+1][x];
			}
			for(int j=x;j>i;j--){
				map[x][j]=map[x][j-1];
			}
			for(int j=x;j>i;j--){
				map[j][i]=map[j-1][i];
			}
			map[i+1][i]=ch;
		}
	}
}

int main(){
	while(scanf("%s", tem)!=EOF){
		getchar();
		gets(str);
		if(tem[0]=='0'&&tem[1]=='0') {
			n=100;
		}
		else{
			n=(tem[0]-'0')*10+tem[1]-'0';
		}
		int ii=1, jj=1;
		int len=strlen(str);
		for(int i=0;i<len;i++){
			if(str[i]<='z'&&str[i]>='a'){
				str[i]+='A'-'a';
			}
			map[ii][jj]=str[i];
			if(++jj>n){
				jj=1;
				ii++;
			}
		}
		int cnt=0;
		while(ii<=n){
			map[ii][jj]='A'+cnt%26;
			cnt++;
			if(++jj>n){
				jj=1;
				ii++;
			}
		}
		len=strlen(tem);
		for(int i=2;i<len;i++){
			if(tem[i]=='S'){
				shake_matrix();
			}
			else if(tem[i]=='R'){
				rattle_matrix();
			}
			else if(tem[i]=='L'){
				roll_matrix();
			}
			/*for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					putchar(map[j][k]);
				}
				puts("");
			}
			puts("");
			*/
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				putchar(map[i][j]);
			}
		}
		puts("");
	}
	return 0;
}
