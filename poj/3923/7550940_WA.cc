#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char str[102][102];
int n, m, visit[102][102], dir[4][2]={-1, 0, 0, 1, 1, 0, 0, -1};

bool check(int s, int s_father, char ch){
	visit[s/m][s%m]=1;
	for(int k=0;k<4;k++){
		int ii=s/m+dir[k][0];
		int jj=s%m+dir[k][1];
		if(ii<0||ii==n||jj<0||jj==m)continue;
		if(ii*m+jj==s_father||str[ii][jj]!=ch)continue;
		if(visit[ii][jj])return true;
		if(check(ii*m+jj, s, ch))return true;
	}
	return false;
}

void solve(){
	for(int i=0;i<n;i++){
		scanf("%s", str[i]);
	}
	memset(visit, 0, sizeof(visit));
	vector <int> ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(str[i][j]!='.'&&!visit[i][j]){
				if(check(i*m+j, -1, str[i][j])){
					ans.push_back(str[i][j]);
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++){
		printf("%c", ans[i]);
	}
	puts("");
}

int main(){
	while(scanf("%d%d", &n, &m), n||m){
		solve();
	}
	return 0;
}
