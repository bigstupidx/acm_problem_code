#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge{
	int to;
	edge *next;
}edg[10010], *vert[30], *r_vert[30];

char str[5], ans[30];
int n, m, deg[30];

void add_edge(int x, int y, int &top){
//	printf("%d -> %d\n", x, y);
	edge *p=&edg[++top];
	p->to=y;
	p->next=vert[x];	vert[x]=p;
	
	p=&edg[++top];
	p->to=x;
	p->next=r_vert[y];	r_vert[y]=p;
}

bool dfs(int s, int t){
	if(s==t)return true;
	for(edge *p=vert[s];p;p=p->next){
		if(dfs(p->to, t)){
			return true;
		}
	}
	return false;
}

void DFS(int s, int &cnt){
	cnt++;
	deg[s]=1;
	for(edge *p=vert[s];p;p=p->next){
		if(!deg[p->to]){
			DFS(p->to, cnt);
		}
	}
}

void DFS_RG(int s, int &cnt){
	cnt++;
	deg[s]=1;
	for(edge *p=r_vert[s];p;p=p->next){
		if(!deg[p->to]){
			DFS_RG(p->to, cnt);
		}
	}
}

bool judge(){
	for(int i=0;i<n;i++){
		int cnt1=0, cnt2=0;
		memset(deg, 0, sizeof(deg));
		DFS(i, cnt1);
		memset(deg, 0, sizeof(deg));
		DFS_RG(i, cnt2);
//		printf("%d %d\n", cnt1, cnt2);
		if(cnt1+cnt2!=n+1)return false;
	}
	return true;
}

int main(){
	while(scanf("%d%d", &n, &m), n||m){
		int top=-1, xflag=0, k=-1;
		memset(vert, 0, sizeof(vert));
		memset(r_vert, 0, sizeof(r_vert));
		for(int i=0;i<m;i++){
			scanf("%s", str);
			if(xflag==1||xflag==2){
				continue;
			}
			if(str[1]=='<'){
				if(dfs(str[2]-'A', str[0]-'A')){
					xflag=2;
					k=i;
				}
				else {
					add_edge(str[0]-'A', str[2]-'A', top);
					if(judge()){
						xflag=1;
						k=i;
					}
				}
			}
			else {
				if(dfs(str[0]-'A', str[2]-'A')){
					xflag=2;
					k=i;
				}
				else {
					add_edge(str[2]-'A', str[0]-'A', top);
					if(judge()){
						xflag=1;
						k=i;
					}
				}
			}
		}
		if(xflag==1){
			printf("Sorted sequence determined after %d relations: ", k+1);
			memset(deg, 0, sizeof(deg));
			for(int i=0;i<n;i++){
				for(edge *p=vert[i];p;p=p->next){
					deg[p->to]++;
				}
			}
			queue<int>Q;
			for(int i=0;i<n;i++){
				if(deg[i]==0){
					Q.push(i);
				}
			}
			top=0;
			while(!Q.empty()){
				int i=Q.front();Q.pop();
				ans[top++]=i+'A';
				for(edge *p=vert[i];p;p=p->next){
					if(--deg[p->to]==0){
						Q.push(p->to);
					}
				}
			}
			for(int i=0;i<top;i++){
				putchar(ans[i]);
			}
			puts(".");
		}
		else if(xflag==0){
			puts("Sorted sequence cannot be determined.");
		}
		else {
			printf("Inconsistency found after %d relations.\n", k+1);
		}
	}
	return 0;
}

