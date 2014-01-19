#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge{
    int x, y, d;
    bool operator <(const edge &a)const{
	return a.d < d;
    }
}edg[1000010];

bool visit[1002];
int n, m, par[1002], ans;

struct node{
    int to;
    int d;
    node *next;
}e[2002], *vert[1002];

int my_find(int x){
    if(par[x]==-1){
	return x;
    }
    return par[x]=my_find(par[x]);
}

void add_edge(int x, int y, int va, int &top){
    node *p=&e[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];	vert[x]=p;
}

bool DFS(int s, int t){
    visit[s]=1;
    if(s==t)return true;
    for(node *p=vert[s];p;p=p->next){
	if(!visit[p->to]){
	    if(DFS(p->to, t)){
		if(p->d < ans)ans=p->d;
		return true;
	    }
	}
    }
    return false;
}

int main(){
    int nca;
    scanf("%d", &nca);
    for(int ii=1;ii<=nca;ii++){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
	    scanf("%d%d%d", &edg[i].x, &edg[i].y, &edg[i].d);
	}
	sort(edg, edg+m);
	memset(par, -1, sizeof(par));
	memset(vert, 0, sizeof(vert));
	int cnt=1, top=-1;
	for(int i=0;i<m;i++){
	    int ii=my_find(edg[i].x);
	    int jj=my_find(edg[i].y);
	    if(ii!=jj){
		add_edge(edg[i].y, edg[i].x, edg[i].d, top);
		add_edge(edg[i].x, edg[i].y, edg[i].d, top);
		par[ii]=jj;
		if(++cnt==n)break;
	    }
	}
	ans = 100000000;
	memset(visit, 0, sizeof(visit));
	DFS(1, n);
	printf("Scenario #%d:\n%d\n\n", ii, ans);
    }
    return 0;
}
