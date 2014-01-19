#include <cstdio>
#include <cstring>

int path[102], num[102], best;
int n, m, g[102][102], tem[102][102], x[102];

bool DFS(int *adj, int total, int cnt){
	if(total==0){
		if(cnt>best){
			for(int i=0;i<cnt;i++){
				path[i]=x[i];
			}
			best=cnt;
			return true;
		}
		return false;
	}
	int t[102];
	for(int i=0;i<total;i++){
		if(best >= cnt + num[adj[i]])return false;
		x[cnt]=adj[i];
		int k = 0;
		for(int j=i+1;j<total;j++){
			if(g[adj[i]][adj[j]]){
				t[k++]=adj[j];
			}
		}
		if(DFS(t, k, cnt+1))return true;
	}
	return false;
}

void max_unique(){
	int adj[102];
	best=0;
	for(int i=n-1;i>=0;i--){
		int k=0;
		x[0]=i;
		for(int j=i+1;j<n;j++){
			if(g[i][j]){
				adj[k++]=j;
			}
		}
		DFS(adj, k, 1);
		num[i]=best;
	}
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		scanf("%d%d", &n, &m);
		memset(tem, 0, sizeof(tem));
		for(int x, y, i=0;i<m;i++){
			scanf("%d%d", &x, &y);
			x--, y--;
			tem[x][y]=tem[y][x]=1;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(tem[i][j]){
					g[i][j]=0;
				}
				else {
					g[i][j]=1;
				}
			}
		}
		max_unique();
		printf("%d\n", best);
		for(int i=0;i<best;i++){
			printf("%d ", path[i]+1);
		}
		puts("");
	}
	return 0;
}
