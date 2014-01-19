#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct node{
    int d, arr[2][12];
}nod[51];

const int inf = 1000000000;
int p, n, c[102][102], f[102][102], pre[102];

bool ok(int ii, int jj){
    for(int i=0;i<p;i++){
	if(nod[ii].arr[1][i]==0&&nod[jj].arr[0][i]==1){
	    return false;
	}
	if(nod[ii].arr[1][i]==1&&nod[jj].arr[0][i]==0){
	    return false;
	}
    }
    return true;
}

int max_flow(int s, int t){
    int flow=0;
    while(1){
	int mini=inf;
	queue<int>Q;
	memset(pre, -1, sizeof(pre));
	Q.push(s);
	while(!Q.empty()&&pre[t]==-1){
	    int i=Q.front();Q.pop();
	    for(int j=0;j<=t;j++){
		if(pre[j]==-1&&c[i][j]>f[i][j]){
		    pre[j]=i;
		    Q.push(j);
		}
	    }
	}
	if(pre[t]==-1)return flow;
	for(int i=t;i!=s;i=pre[i]){
	    if(mini>c[pre[i]][i]-f[pre[i]][i]){
		mini=c[pre[i]][i]-f[pre[i]][i];
	    }
	}
	flow+=mini;
	for(int i=t;i!=s;i=pre[i]){
	    f[pre[i]][i]+=mini;
	    f[i][pre[i]]-=mini;
	}
    }
}

int main(){
    while(scanf("%d%d", &p, &n)!=EOF){
	int t=101;
	for(int i=1;i<=n;i++){
	    scanf("%d", &nod[i].d);
	    for(int j=0;j<p;j++){
		scanf("%d", &nod[i].arr[0][j]);
	    }
	    for(int j=0;j<p;j++){
		scanf("%d", &nod[i].arr[1][j]);
	    }
	}
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for(int i=1;i<=n;i++){
	    c[i][i+50]=nod[i].d;
	    for(int j=1;j<i;j++){
		if(ok(i, j)){
		    c[i+50][j]=inf;
		}
		if(ok(j, i)){
		    c[j+50][i]=inf;
		}
	    }
	    int flag=0;
	    for(int j=0;j<p&&!flag;j++){
		if(nod[i].arr[0][j]==1){
		    flag=1;
		}
	    }
	    if(!flag){
		c[0][i]=inf;
	    }
	    flag=0;
	    for(int j=0;j<p&&!flag;j++){
		if(!nod[i].arr[1][j]){
		    flag=1;
		}
	    }
	    if(!flag){
		c[i+50][t]=inf;
	    }
	}
	int tem=max_flow(0, t);
	if(tem){
	    int cnt=0;
	    for(int i=51;i<=n+50;i++){
		for(int j=1;j<=n;j++){
		    if(f[i][j]>0){
			cnt++;
		    }
		}
	    }
	    printf("%d %d\n", tem, cnt);
	    for(int i=51;i<=n+50;i++){
		for(int j=1;j<=n;j++){
		    if(f[i][j]>0){
			printf("%d %d %d\n", i-50, j, f[i][j]);
		    }
		}
	    }
	}
	else {
	    puts("0 0");
	}
    }
    return 0;
}
