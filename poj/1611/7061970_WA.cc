#include <cstdio>
#include <cstring>

int n, m, par[30002], rank[30002];

int my_find(int x){
    if(par[x]==-1){
	return x;
    }
    return par[x]=my_find(par[x]);
}

void my_union(int i, int j){
    if(rank[i]>rank[j]){
	par[j]=i;
    }
    else {
	par[i]=j;
	if(rank[i]==rank[j]){
	    rank[j]++;
	}
    }
    return ;
}

int main(){
    while(scanf("%d%d", &n, &m), n||m){
	for(int i=0;i<n;i++){
	    par[i]=-1;
	    rank[i]=0;
	}
	for(int i=0;i<m;i++){
	    int mm, ii, jj, u, v;
	    scanf("%d", &mm);
	    if(mm){
		scanf("%d", &u);
		ii=my_find(u);
	    }
	    for(int j=1;j<mm;j++){
		scanf("%d", &v);
		jj=my_find(v);
		if(ii!=jj){
		    my_union(ii, jj);
		}
	    }
	}
	int ans=1, ii=my_find(0);
	for(int i=1;i<n;i++){
	    if(my_find(i)==ii){
		ans++;
	    }
	}
	printf("%d\n", ans);
    }
    return 0;
}
