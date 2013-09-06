#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge{
    int to, c, next;
}e[100010];

const int inf = 100000000;
int n, m, head[120], p[120][2], L[120], c[120][120];

void add_edge(int x, int y, int va, int &top){
    e[++top].to=y;	    e[top].c=va;
    e[top].next=head[x];    head[x]=top;

    e[++top].to=x;	    e[top].c=0;
    e[top].next=head[y];    head[y]=top;
}

void build_g(){
    int top=-1;
    memset(head, -1, sizeof(head));
    for(int i=0;i<102;i++){
	for(int j=0;j<102;j++){
	    if(c[i][j]){
		add_edge(i, j, c[i][j], top);
	    }
	}
    }
}

int max_flow(int s, int t){
    int flow=0;
    while(1){
	queue<int>Q;
	memset(L, -1, sizeof(L));
	Q.push(s);
	L[s]=0;
	while(!Q.empty()){
	    int i=Q.front();Q.pop();
	    for(int j=head[i];j!=-1;j=e[j].next){
		if(L[e[j].to]==-1&&e[j].c>0){
		    L[e[j].to]=L[i]+1;
		    Q.push(e[j].to);
		}
	    }
	}
	if(L[t]==-1)return flow;
	int top=0;
	p[0][0]=s;  p[0][1]=head[s];
	while(top>=0){
	    if(p[top][0]!=t){
		while(p[top][1]>=0){
		    int j=p[top][1];
		    if(L[e[j].to]>L[p[top][0]]&&e[j].c>0){
			p[top+1][0]=e[j].to;
			p[top+1][1]=head[e[j].to];
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
		int mini=inf, k;
		for(int i=0;i<top;i++){
		    if(mini>e[p[i][1]].c){
			mini=e[p[i][1]].c;
			k=i;
		    }
		}
		flow+=mini;
		for(int i=0;i<top;i++){
		    e[p[i][1]].c-=mini;
		    e[p[i][1]^1].c+=mini;
		}
		top=k;
		p[top][1]=e[p[top][1]].next;
	    }
	}
    }
}

int main(){
    int nca;
    scanf("%d", &nca);
    while(nca--){
	int top=-1;
	memset(c, 0, sizeof(c));
	scanf("%d%d", &m, &n);
	n/=2;
	for(int s, t, i=0;i<m;i++){
	    scanf("%d%d", &s, &t);
	    for(int j=s;j<t;j++){
		c[j][j+1]++;
	    }
	    c[t][101]++;
	}
	for(int i=1;i<101;i++){
	    if(i%7!=0&&i%7!=6){
		c[0][i]=n;
	    }
	}
	build_g();
	if(max_flow(0, 101)==m){
	    puts("fine");
	}
	else {
	    for(int i=1;i<101;i++){
		c[0][i]=n;
	    }
	    build_g();
	    if(max_flow(0, 101)==m){
		puts("weekend work");
	    }
	    else {
		puts("serious trouble");
	    }
	}
    }
    return 0;
}
