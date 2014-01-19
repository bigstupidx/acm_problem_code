#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

int n, m;
bool visit[10010];

set <int> mp[10010];

void DFS(int s){
    if(visit[s])return ;
    visit[s]=1;
    for(int i=1;i<=n;i++){
	if(mp[s].find(i)==mp[s].end()){
	    DFS(i);
	}
    }
}

int main(){
    int nca=1;
    while(scanf("%d%d", &n, &m), n||m){
	for(int i=1;i<=n;i++){
	    mp[i].clear();
	}
	for(int i=0;i<m;i++){
	    int u, v;
	    scanf("%d%d", &u, &v);
	    mp[u].insert(v);
	    mp[v].insert(u);
	}
	memset(visit, 0, sizeof(visit));
	DFS(1);
	int cnt=0;
	for(int i=2;i<=n;i++){
	    if(visit[i]) {
		cnt++;
	    }
	}
	printf("Case %d: %d\n", nca++, cnt);
    }
    return 0;
}
