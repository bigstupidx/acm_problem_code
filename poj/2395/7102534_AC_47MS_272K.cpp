#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge{
    int x, y, d;
    bool operator <(const edge &a)const{
	return a.d > d;
    }
}edg[10010];

int n, m, par[2002];

int my_find(int x){
    if(par[x]==-1){
	return x;
    }
    return par[x]=my_find(par[x]);
}

int main(){
    while(scanf("%d%d", &n, &m)!=EOF){
	memset(par, -1, sizeof(par));
	for(int i=0;i<m;i++){
	    scanf("%d%d%d", &edg[i].x, &edg[i].y, &edg[i].d);
	}
	
	sort(edg, edg+m);

	int cnt=1, ans=0;
	memset(par, -1, sizeof(par));
	for(int i=0;i<m;i++){
	    int ii=my_find(edg[i].x);
	    int jj=my_find(edg[i].y);
	    if(ii!=jj){
		par[ii]=jj;
		if(++cnt==n){
		    ans=edg[i].d;
		    break;
		}
	    }
	}
	printf("%d\n", ans);
    }
    return 0;
}
