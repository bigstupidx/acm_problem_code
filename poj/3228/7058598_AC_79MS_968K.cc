#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge{
    int to, c, f, next;
}e[100000];

const int inf = 1000000000;
int n, m, head[202], p[202][2], L[202], va[202], wi[202], dis[202][202];

void add_edge(int x, int y, int va, int &top){
    e[++top].to=y;  e[top].c=va;
    e[top].f=0;	    e[top].next=head[x];    head[x]=top;

    e[++top].to=x;  e[top].c=0;
    e[top].f=0;	    e[top].next=head[y];    head[y]=top;
}

void build_g(int mid){
    int top=-1, t=n+1;
    memset(head, -1, sizeof(head));
    for(int i=1;i<t;i++){
	if(va[i]){
	    add_edge(0, i, va[i], top);
	}
	if(wi[i]){
	    add_edge(i, t, wi[i], top);
	}
    }
    for(int i=1;i<=n;i++){
	for(int j=1;j<i;j++){
	    if(dis[i][j]<=mid){
		add_edge(i, j, inf, top);
		add_edge(j, i, inf, top);
	    }
	}
    }
}

int max_flow(int s, int t){
    int flow=0;
    while(1){
	queue<int>Q;
	memset(L, -1, sizeof(L));
	L[s]=0;
	Q.push(s);
	while(!Q.empty()){
	    int i=Q.front();Q.pop();
	    for(int j=head[i];j!=-1;j=e[j].next){
		if(L[e[j].to]==-1&&e[j].c>e[j].f){
		    L[e[j].to]=L[i]+1;
		    Q.push(e[j].to);
		}
	    }
	}
	if(L[t]==-1){
	    //printf(" %d \n", flow);
	    return flow;
	}
	int top=0;
	p[0][0]=s;  p[0][1]=head[s];
	while(top>=0){
	    if(p[top][0]!=t){
		while(p[top][1]>=0){
		    int j=p[top][1];
		    if(L[e[j].to]>L[p[top][0]]&&e[j].c>e[j].f){
			p[top+1][0]=e[j].to;
			p[top+1][1]=head[p[top+1][0]];
			top++;
			break;
		    }
		    p[top][1]=e[j].next;
		}
		if(p[top][1]<0){
		    if(--top<0)break;
		    p[top][1]=e[p[top][1]].next;
		}
	    }
	    else {
		int mini=inf, k=top;
		for(int i=0;i<top;i++){
		    int j=p[i][1];
		    if(mini>e[j].c-e[j].f){
			mini=e[j].c-e[j].f;
			k=i;
		    }
		}
		flow+=mini;
		for(int i=top-1;i>=0;i--){
		    e[p[i][1]].f+=mini;
		    e[p[i][1]^1].f-=mini;
		}
		top=k;
		p[top][1]=e[p[top][1]].next;
	    }
	}
    }
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
	    sum2+=wi[i];
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
	    if(d>maxi)maxi=d;
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
	while(lf <= rt){
	    mid=(lf+rt)/2;
	    build_g(mid);
	    //printf("try mid: %d ", mid);
	    if(max_flow(0, n+1)==sum1){
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
