#include <cstdio>
#include <cstring>

const int inf = 10000000;
int n, m, par[202], va[202], wi[202], dis[202][202], visit[202];

int my_find(int x){
    if(par[x]==-1){
	return x;
    }
    return par[x]=my_find(par[x]);
}

bool solve(int mid){
    memset(par, -1, sizeof(par));
    memset(visit, 0, sizeof(visit));
    for(int i=1;i<=n;i++){
	for(int j=1;j<i;j++){
	    if(dis[i][j]<=mid){
		int ii=my_find(i);
		int jj=my_find(j);
		if(ii!=jj){
		    par[ii]=jj;
		}
	    }
	}
    }
    for(int i=1;i<=n;i++){
	if(va[i]==0||visit[i])continue;
	int ii=my_find(i);
	int sum1=0, sum2=0;
	for(int j=1;j<=n;j++){
	    int jj=my_find(j);
	    if(jj==ii){
		sum1+=va[j];
		sum2+=wi[j];
		visit[j]=1;
	    }
	}
	if(sum1>sum2)return false;
    }
    return true;
}

int main(){
    while(scanf("%d", &n), n){
	int sum1=0, sum2=0;
	for(int i=1;i<=n;i++){
	    scanf("%d", &va[i]);
	    sum1+=va[i];
	}
	for(int i=1;i<=n;i++){
	    scanf("%d", &wi[i]);
	    sum2+=va[i];
	}
	for(int i=1;i<=n;i++){
	    for(int j=1;j<i;j++){
		dis[i][j]=dis[j][i]=inf;
	    }
	    dis[i][i]=0;
	}
	int maxi=-1;
	scanf("%d", &m);
	for(int u, v, d, i=0;i<m;i++){
	    scanf("%d%d%d", &u, &v, &d);
	    if(maxi < d)maxi=d;
	    if(dis[u][v]>d){
		dis[u][v]=d;
		dis[v][u]=d;
	    }
	}
	if(sum1>sum2){
	    puts("No Solution");
	    continue;
	}
	int lf=0, rt=maxi, mid;
	while(lf<=rt){
	    mid=(lf+rt)/2;
	    if(solve(mid)){
		rt=mid-1;
	    }
	    else {
		lf=mid+1;
	    }
	}
	if(lf>maxi){
	    puts("No Solution");
	}
	else {
	    printf("%d\n", lf);
	}
    }
    return 0;
}
