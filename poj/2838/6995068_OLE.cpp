#include <cstdio>
#include <cstring>

char str[3];
int n;
bool visit[1002];

struct edge{
	int to;
	edge *next;
}edg[1000010], *vert[1002];

void add_edge(int x, int y, int &top){
	edge *p=&edg[++top];
	p->to=y;
	p->next=vert[x];	vert[x]=p;
	
	p=&edg[++top];
	p->to=x;
	p->next=vert[y];	vert[y]=p;
}

void delete_edge(int x, int y){
	edge *q=NULL;
	for(edge *p=vert[x];p;q=p, p=p->next){
		if(p->to==y){
			break;
		}
	}
	if(q){
		q->next=q->next->next;
	}
	else{
		vert[x]=vert[x]->next;
	}
	q=NULL;
	for(edge *p=vert[y];p;p=p->next){
		if(p->to==x){
			break;
		}
	}
	if(q){
		q->next=q->next->next;
	}
	else{
		vert[y]=vert[y]->next;
	}
}

bool DFS(int s, int t){
	if(s==t)return true;
	visit[s]=true;
	for(edge *p=vert[s];p;p=p->next){
		if(!visit[p->to]&&DFS(p->to, t)){
			return true;
		}
	}
	return false;
}

int main(){
	while(scanf("%d", &n), n){
		int mm, u, v, top=-1;
		scanf("%d", &mm);
		for(int i=1;i<=n;i++){vert[i]=NULL;}
		
		while(mm--){
			scanf("%s%d%d", str, &u, &v);
			if(str[0]=='Q'){
				memset(visit, false, sizeof(visit));
				if(DFS(u,v)){
					puts("Y");
				}
				else {
					puts("N");
				}
			}
			else if(str[0]=='I'){
				add_edge(u, v, top);
			}
			else {
				delete_edge(u, v);
			}
		}
	}
	return 0;
}
