#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

struct edge{
	int s, t, c, w, next;
}e[1000010];

const int inf = 1000000000;
int n, m, dis[1002], flag[1002], pre[1002], head[1002];

struct node{
	int lf, rt, va;
}nod[2010];

void add_edge(int x, int y, int c, int w, int &top){
	//printf("%d -> %d %d %d\n", x, y, c, w);
	e[++top].s=x;	e[top].t=y;				e[top].c=c;
	e[top].w=w;		e[top].next=head[x]; 	head[x]=top;
	
	e[++top].s=y;	e[top].t=x;				e[top].c=0;
	e[top].w=-w;	e[top].next=head[y];	head[y]=top;
}

bool spfa(int s, int t){
	queue <int> Q;
	for(int i=0;i<=t;i++){
		dis[i]=inf;
		flag[i]=0;
		pre[i]=-1;
	}
	dis[s]=0;
	flag[s]=1;
	Q.push(s);
	while(!Q.empty()){
		int i=Q.front();Q.pop();
		//printf("%d ", dis[i]);
		for(int j=head[i];j!=-1;j=e[j].next){
			if(e[j].c > 0 && dis[e[j].t] > dis[e[j].s] + e[j].w){
				dis[e[j].t]=dis[e[j].s]+e[j].w;
				pre[e[j].t]=j;
				if(!flag[e[j].t]){
					flag[e[j].t]=1;
					Q.push(e[j].t);
				}
			}
		}
		flag[i]=0;
	}
	//printf("%d\n", dis[t]);
	return dis[t]!=inf;
}

int main(){
	while(scanf("%d%d", &n, &m)!=EOF){
		int top=-1;
		memset(head, -1, sizeof(head));
		map <int, int> mp;
		map <int, int> ::iterator p;
		for(int i=0;i<n;i++){
			int hh, mm, ss;
			scanf("%d:%d:%d", &hh, &mm, &ss);
			nod[i].lf = hh*3600+mm*60+ss;
			scanf("%d:%d:%d", &hh, &mm, &ss);
			nod[i].rt = hh*3600+mm*60+ss;
			scanf("%d", &nod[i].va);
			mp[nod[i].lf] = 1;
			mp[nod[i].rt] = 1;
		}
		int k=1;
		for(p=mp.begin();p!=mp.end();p++){
			p->second=k++;
		}
		for(int i=0;i<n;i++){
			int u = mp.find(nod[i].lf)->second;
			int v = mp.find(nod[i].rt)->second;
			add_edge(u, v, 1, -nod[i].va, top);
		}
		for(int i=2;i<k;i++){
			add_edge(i-1, i, m, 0, top);
		}
		add_edge(0, 1, m, 0, top);
		add_edge(k-1, k, m, 0, top);
		int ans=0;
		while(spfa(0, k)){
			int mini=inf;
			for(int i=k;i!=0;i=e[pre[i]].s){
				if(mini > e[pre[i]].c){
					mini = e[pre[i]].c;
				}
			}
			for(int i=k;i!=0;i=e[pre[i]].s){
				e[pre[i]].c -= mini;
				e[pre[i]^1].c += mini;
			}
			if(dis[k]>=0)break;
			//puts("");
			//printf("%d %d\n", mini, dis[k]);
			ans+=dis[k];
		}
		printf("%d\n", -ans);
	}
	return 0;
}

