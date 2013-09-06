#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char str[5], ans[30];
int n, m, deg[30], map[30][30], tem[30];

int judge(){
	int top=0, xflag=0;
	stack<int>S;
	for(int i=0;i<n;i++){
		tem[i]=deg[i];
		if(deg[i]==0){
			xflag++;
			S.push(i);
		}
	}
	if(xflag==1)xflag=0;
	while(!S.empty()){
		int i=S.top();S.pop();
		ans[top++]=i+'A';
		for(int cnt=0, j=0;j<n;j++){
			if(map[i][j]&&(--tem[j])==0){
				if(++cnt>1){
					xflag++;
				}
				S.push(j);
			}
		}
	}
	ans[n]=0;
	if(top==n){
		if(!xflag) return 1;
		return 0;
	}
	return 2;
}

int main(){
	while(scanf("%d%d", &n, &m), n||m){
		int xflag=0, k;
		memset(deg, 0, sizeof(deg));
		memset(map, 0, sizeof(map));
		for(int i=0;i<m;i++){
			scanf("%s", str);
			if(xflag==1||xflag==2)continue;
			if(str[1]=='<'){
				map[str[0]-'A'][str[2]-'A']=1;
				deg[str[2]-'A']++;
			}
			else {
				map[str[2]-'A'][str[0]-'A']=1;
				deg[str[0]-'A']++;
			}
			k=i+1;
			xflag=judge();
		}
		if(xflag==0){
			puts("Sorted sequence cannot be determined.");
		}
		else if(xflag==2){
			printf("Inconsistency found after %d relations.\n", k);
		}
		else {
			printf("Sorted sequence determined after %d relations: %s.\n", k, ans);
		}
	}
	return 0;
}

