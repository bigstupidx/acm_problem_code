#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

struct edge{
	int to;
	int id;
	edge *next;
}edg[2000010], *vert[1002];

bool visit[1002], map[1002][1002];
int n, m, cnt;
queue <int> Q;

void add_edge(int x, int y, int &top){
	edge *p=&edg[++top];
	p->to=y;
	p->id=top;
	p->next=vert[x];	vert[x]=p;
	
	p=&edg[++top];
	p->to=x;
	p->id=top;
	p->next=vert[y];	vert[y]=p;
}

bool DFS(int s, int t){
	if(s==t){
		return true;
	}
	visit[s]=true;
	for(edge *p=vert[s];p;p=p->next){
		if(!visit[p->to]&&DFS(p->to, t)){
			return true;
		}
	}
	return false;
}

void delete_edge(int x, int y){
	edge *q=NULL, *p=NULL;
	for(p=vert[x];p;q=p, p=p->next){
		if(p->to==y){
			break;
		}
	}
	if(p&&p->to==y){
		cnt++;
		Q.push(p->id);
		if(q){
			q->next=q->next->next;
		}
		else {
			vert[x]=vert[x]->next;
		}
	}
	p=NULL;
	q=NULL;
	for(p=vert[y];p;q=p, p=p->next){
		if(p->to==x){
			break;
		}
	}
	if(p&&p->to==x){
		if(q){
			q->next=q->next->next;
		}
		else{
			vert[y]=vert[y]->next;
		}
	}
}

int main(){
	char str[3];
	int top = -1, u, v; 
	while(!Q.empty())Q.pop();
	memset(vert, 0, sizeof(vert));
	memset(map, 0, sizeof(map));
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%s%d%d", str, &u, &v);
		if(str[0]=='Q'){
			if(u==v||map[u][v]){
				puts("Y");
				continue;
			}
			memset(visit, 0, sizeof(visit));
			if(DFS(u, v)){
				puts("Y");
			}
			else {
				puts("N");
			}
		}
		else if(str[0]=='I'){
			if(u==v)continue;
			if(map[u][v])continue;
			map[u][v]=true;
			map[v][u]=true;
			if(!cnt){
				add_edge(u, v, top);
			}
			else{
				int x=Q.front();
				Q.pop();
				cnt--;
				if(x%2){
					x-=3;
				}
				else{
					x--;
				}
				add_edge(u, v, x);
			}
		}
		else {
			if(u==v)continue;
			map[u][v]=false;
			map[v][u]=false;
			delete_edge(u, v);
		}
	}
	//system("pause");
	return 0;
}
