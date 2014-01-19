#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge{
	int s, t, c, w, next;
}e[40010];

const int inf = 1000000000;
int n, m, dis[1002], pre[1002], flag[1002], head[1002];

void add_edge(int x, int y, int c, int w, int &top){
	e[++top].s=x;	e[top].t=y;				e[top].c=c;
	e[top].w=w;		e[top].next=head[x];	head[x]=top;

	e[++top].s=y;	e[top].t=x;				e[top].c=0;
	e[top].w=-w;	e[top].next=head[y];	head[y]=top;
}

void spfa(){
	queue <int> Q;
	for(int i=1;i<=n;i++){
		dis[i]=inf;
		flag[i]=0;
	}
	dis[1]=0;
	Q.push(1);
	flag[1]=1;
	while(!Q.empty()){
		int s=Q.front();Q.pop();
		for(int j=head[s];j!=-1;j=e[j].next){
			if(e[j].c > 0 && dis[e[j].t] > dis[s] + e[j].w){
				dis[e[j].t] = dis[s]+e[j].w;
				pre[e[j].t] = j;
				if(!flag[e[j].t]){
					flag[e[j].t]=1;
					Q.push(e[j].t);
				}
			}
		}
		flag[s]=0;
	}
}

int main(){
	while(scanf("%d%d", &n, &m)!=EOF){
		int top=-1;
		memset(head, -1, sizeof(head));
		for(int i=0;i<m;i++){
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			add_edge(u, v, 1, va, top);
			add_edge(v, u, 1, va, top);
		}
		__int64 ans=0;
		for(int i=0;i<2;i++){
			spfa();
			for(int j=pre[n];;j=pre[e[j].s]){
				e[j].c-=1;
				e[j^1].c+=1;
				if(e[j].s==1)break;
			}
			ans += dis[n];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
