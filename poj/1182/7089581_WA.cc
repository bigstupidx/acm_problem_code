#include <cstdio>
#include <cstring>

int par[50010], rel[50010], n, m, sum;

int my_find(int x){
    if(par[x]==-1){
	sum=0;
	return x;
    }
    par[x]=my_find(par[x]);
    sum+=rel[x];
    rel[x]=sum%3;
    return par[x];
}

int main(){
    while(scanf("%d%d", &n, &m)!=EOF){
	int cnt=0;
	memset(par, -1, sizeof(par));
	for(int i=0;i<m;i++){
	    int d, x, y;
	    scanf("%d%d%d", &d, &x, &y);
	    if(x>n||y>n||x<1||y<1){
		cnt++;
		continue;
	    }
	    int ii=my_find(x);
	    int jj=my_find(y);
	    if(ii==jj){
		if(d==2&&rel[x]==rel[y]){
		    cnt++;
		}
		else if(d==1&&rel[x]!=rel[y]){
		    cnt++;
		}
	    }
	    else {
		par[jj]=ii;
		rel[jj]=(d-1+rel[x])%3;
	    }
	}
	printf("%d\n", cnt);
    }
    return 0;
}
