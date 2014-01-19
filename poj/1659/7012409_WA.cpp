#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
    int ii;
    int nn;
    bool operator <(const node &a)const{
	return a.nn < nn;
    }
}adj[12];
int n, map[12][12];

bool solve(){
    for(int i=0;i<n;i++){
	sort(adj, adj+n);
	for(int j=i+1;j<n&&adj[i].nn;j++){
	    if(--adj[j].nn<0)return false;
	    adj[i].nn--;
	    map[adj[i].ii][adj[j].ii]=1;
	    map[adj[j].ii][adj[i].ii]=1;
	}
	if(adj[i].nn)return false;
    }
    return true;
}

int main(){
    int nca, flag=0;
    scanf("%d", &nca);
    while(nca--){
	if(flag)puts("");
	else flag=1;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
	    scanf("%d", &adj[i].nn);
	    adj[i].ii=i;
	}
	memset(map, 0, sizeof(map));
	if(solve()){
	    puts("YES");
	    for(int i=0;i<n;i++){
		printf("%d", map[i][0]);
		for(int j=1;j<n;j++){
		    printf(" %d", map[i][j]);
		}
		puts("");
	    }
	}
	else{
	    puts("NO");
	}
    }
    return 0;
}