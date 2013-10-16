#include <cstdio>
#include <cstring>

char map[6][6], ans[2][3002][3002];
int n, L;
struct node{
	int ii, jj;
}arr[100010];

void solve(){
	char ch;
	int fi=n*n, now=0, top=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans[now][i][j]=map[i][j];
			if(map[i][j]!=' '){
				ch=map[i][j];
				arr[top].ii=i;
				arr[top].jj=j;
				top++;
			}
		}
	}
	now=1-now;
	for(int i=1;i<L;i++){
		int tt=fi/n;
		for(int j=0;j<fi;j++){
			for(int k=0;k<fi;k++){
				ans[now][j][k]=' ';
			}
			ans[now][j][fi]='\0';
		}
		for(int j=0;j<tt;j++){
			for(int k=0;k<tt;k++){
				if(ans[1-now][j][k]!=' '){
					for(int l=0;l<top;l++){
						ans[now][j+arr[l].ii*tt][k+arr[l].jj*tt]=ch;
					}
				}
			}
		}
		now=1-now;
		fi*=n;
	}
	now=1-now;
	fi/=n;
	for(int i=0;i<fi;i++){
		puts(ans[now][i]);
	}
}

int main(){
	//freopen("out.txt", "w", stdout);
	while(scanf("%d", &n), n){
		getchar();
		for(int i=0;i<n;i++){
			gets(map[i]);
		}
		scanf("%d", &L);
		solve();
		//}
	}
	return 0;
}
