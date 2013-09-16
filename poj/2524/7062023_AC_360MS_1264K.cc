#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int n, m, par[50002], rank[50002];

int my_find(int x){
    if(par[x]==-1){
	return x;
    }
    return par[x]=my_find(par[x]);
}

int my_union(int i, int j){
    if(rank[i]>rank[j]){
	par[j]=i;
    }
    else {
	par[i]=j;
	if(rank[i]==rank[j]){
	    rank[j]++;
	}
    }
}
int main(){
    int nca=1;
    while(scanf("%d%d", &n, &m), n||m){
	for(int i=1;i<=n;i++){
	    par[i]=-1;
	    rank[i]=0;
	}
	for(int i=0; i<m;i++){
	    int x, y, ii, jj;
	    scanf("%d%d", &x, &y);
	    ii=my_find(x);
	    jj=my_find(y);
	    if(ii!=jj){
		my_union(ii, jj);
	    }
	}
	map<int, int>ans;
	for(int ii, i=1;i<=n;i++){
	    ii=my_find(i);
	    ans[ii]=1;
	}
	printf("Case %d: %d\n", nca++, ans.size());
    }
    return 0;
}
