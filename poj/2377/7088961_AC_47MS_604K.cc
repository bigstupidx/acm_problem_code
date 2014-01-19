#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge{
    int x, y, d;
    bool operator <(const edge &a)const{
	return a.d < d;
    }
}edg[20010];

int n, m, par[1010];

int my_find(int x){
    if(par[x]==-1){
	return x;
    }
    return par[x]=my_find(par[x]);
}

int kruskral(){
    int cnt=1, sum=0;
    sort(edg, edg+m);
    for(int i=0;i<m;i++){
	int ii=my_find(edg[i].x);
	int jj=my_find(edg[i].y);
	if(ii!=jj){
	    par[ii]=jj;
	    sum+=edg[i].d;
	    if(++cnt==n)break;
	}
    }
    if(cnt==n)return sum;
    return -1;
}

int main(){
    while(scanf("%d%d", &n, &m)!=EOF){
	memset(par, -1, sizeof(par));
	for(int i=0;i<m;i++){
	    scanf("%d%d%d", &edg[i].x, &edg[i].y, &edg[i].d);
	}
	printf("%d\n", kruskral());
    }
    return 0;
}
