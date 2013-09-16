#include <cstdio>
#include <cstring>

int n, arr[1002][1002], tem[1002][1002];
int que[2][4002];

bool judge(int top){
    int x=que[0][0], k=-1;
    for(int i=0;i<top;i++){
	if(que[1][i]==x){
	    k=i;
	    break;
	}
    }
    if(k==-1)return false;
    for(int i=0;i<top;i++){
	if(que[0][i]!=que[1][k]){
	    return false;
	}
	k=(k+1)%top;
    }
    return true;
}

bool solve(){
    int m=(n+1)/2;
    for(int i=0;i<m;i++){
	int x=n-i, y=i+1, top=0;
	que[0][top]=tem[y][y];
	que[1][top++]=arr[y][y];
	for(int j=i+2;j<x;j++){
	    que[0][top]=tem[y][j];
	    que[1][top]=arr[y][j];
	    top++;
	}
	for(int j=i+1;j<x;j++){
	    que[0][top]=tem[j][x];
	    que[1][top]=arr[j][x];
	    top++;
	}
	for(int j=x;j>y;j--){
	    que[0][top]=tem[x][j];
	    que[1][top]=arr[x][j];
	    top++;
	}
	for(int j=x;j>y;j--){
	    que[0][top]=tem[j][y];
	    que[1][top]=arr[j][y];
	    top++;
	}
	//for(int i=0;i<top;i++){
	//    printf("%d ", que[0][i]);
	//}
	//puts("");
	if(!judge(top)){
	    return false;
	}
    }
    return true;
}

int main(){
    int nca=1;
    while(scanf("%d", &n), n){
	int k=1;
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
		tem[i][j]=k++;
		scanf("%d", &arr[i][j]);
	    }
	}
	if(solve()){
	    printf("%d. YES\n", nca++);
	}
	else {
	    printf("%d. NO\n", nca++);
	}
    }
    return 0;
}