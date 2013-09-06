#include <cstdio>
#include <cstring>

struct edge{
	int to;
	edge *next;
}edg[20010], *vert[102];

bool cut[102];
int n, anc[102], dep[102], color[102];

void add_edge(int x, int y, int &top){
	edge *p=&edg[++top];
	p->to=y;
	p->next=vert[x];	vert[x]=p;
}

void DFS(int k, int k_father, int depth){
	anc[k]=depth;
	dep[k]=depth;
	int tot=0;
	color[k]=1;
	for(edge *p=vert[k];p;p=p->next){
		if(color[p->to]==1){
			if(p->to!=k_father&&dep[p->to]<anc[k]){
				anc[k]=dep[p->to];
			}
		}
		else if(color[p->to]==0){
			tot++;
			DFS(p->to, k, depth+1);
			anc[k]=anc[p->to]<anc[k]?anc[p->to]:anc[k];
			if(k_father==-1&&tot>1||k_father!=-1&&anc[p->to]>=dep[k]){
				cut[k]=true;
			}
		}
	}
	color[k]=2;
}

int main(){
	while(scanf("%d", &n), n){
		int x, y, top=-1;
		memset(vert, 0, sizeof(vert));
		while(scanf("%d", &x), x){
			char ch;
			while(1){
				scanf("%d%c", &y, &ch);
				add_edge(x, y, top);
				add_edge(y, x, top);
				if(ch=='\n')break;
			}
		}
		memset(cut, 0, sizeof(cut));
		memset(anc, 0, sizeof(anc));
		memset(dep, 0, sizeof(dep));
		memset(color, 0, sizeof(color));
		DFS(1, -1, 1);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(cut[i]){
				//printf("%d ", i);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

