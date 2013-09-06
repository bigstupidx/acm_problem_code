#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge{
	int s, t, c, w, next;
}e[1000010];

const int inf = 1000000000;
int n, m, dis[4010], flag[4010], head[4010], pre[4010];
int in[4010], out[4010];

struct node{
	int lf, rt, va;
	bool operator <(const node &a)const{
		if(a.lf==lf)return a.rt > rt;
		return a.lf > lf;
	}
}nod[2010];

void add_edge(int x, int y, int c, int w, int &top){
	//printf("%d -> %d %d %d\n", x, y, c, w);
	e[++top].s=x;	e[top].t=y;				e[top].c=c;
	e[top].w=w;		e[top].next=head[x];	head[x]=top;

	e[++top].s=y;	e[top].t=x;				e[top].c=0;
	e[top].w=-w;	e[top].next=head[y];	head[y]=top;
}

bool conflict(int i, int j){
	if(nod[i].lf>=nod[j].rt||nod[i].rt<=nod[j].lf)return true;
	return true;
}

void spfa(int s, int t){
	queue<int>Q;
	for(int i=0;i<=t;i++){
		dis[i] = inf;
		pre[i] = -1;
		flag[i] = 0;
	}
	dis[s]=0;
	flag[s]=1;
	Q.push(s);
	while(!Q.empty()){
		int i=Q.front();Q.pop();
		for(int j=head[i];j!=-1;j=e[j].next){
			if(e[j].c>0&&dis[e[j].t]>dis[e[j].s]+e[j].w){
				dis[e[j].t] = dis[e[j].s] + e[j].w;
				pre[e[j].t] = j;
				if(!flag[e[j].t]){
					flag[e[j].t]=1;
					Q.push(e[j].t);
				}
			}
		}
		flag[i]=0;
	}
}

int main(){
	while(scanf("%d%d", &n, &m)!=EOF){
		int top=-1, s=0, t = 2*n+1;
		memset(head, -1, sizeof(head));
		for(int i=1;i<=n;i++){
			int hh, mm, ss;
			scanf("%d%*c%d%*c%d", &hh, &mm, &ss);
			nod[i].lf = hh*3600+mm*60+ss;
			scanf("%d%*c%d%*c%d", &hh, &mm, &ss);
			nod[i].rt = hh*3600+mm*60+ss;
			scanf("%d", &nod[i].va);
		}
		sort(nod+1, nod+n+1);
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(nod[i].rt <= nod[j].lf){
					++in[j];
					++out[i];
					add_edge(i+n, j, 1, 0, top);
				}
			}
			add_edge(i, i+n, 1, -nod[i].va, top);
		}
		for(int i=1;i<=n;i++){
			if(in[i]==0){
				add_edge(s, i, 1, 0, top);
			}
			if(out[i]==0){
				add_edge(i+n, t, 1, 0, top);
			}
		}
		__int64 ans=0;
		while(m--){
			spfa(s, t);
			for(int j=pre[t];j!=-1;j=pre[e[j].s]){
				e[j].c-=1;
				e[j^1].c+=1;
				if(e[j].s==0)break;
			}
			if(dis[t]<0)ans+=dis[t];
			else break;
		}
		printf("%I64d\n", -ans);
	}
	return 0;
}

