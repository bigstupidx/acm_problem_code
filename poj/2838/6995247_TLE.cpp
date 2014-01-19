#include <cstdio>
#include <cstring>
#include <cstdlib>

bool map[1002][1002], visit[1002];

int n, m;

bool DFS(int s, int t){
	if(s==t)return true;
	visit[s]=true;
	for(int i=1;i<=n;i++){
		if(!visit[i]&&map[s][i]&&DFS(i, t)){
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		char str[3];
		int u, v;
		scanf("%s%d%d", str, &u, &v);
		if(str[0]=='Q'){
			memset(visit, 0, sizeof(visit));
			if(DFS(u, v)){
				puts("Y");
			}
			else{
				puts("N");
			}
		}
		else if(str[0]=='I'){
			map[u][v]=true;
			map[v][u]=true;
		}
		else {
			map[u][v]=false;
			map[v][u]=false;
		}
	}
	system("pause");
	return 0;
}
