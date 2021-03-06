#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 10010

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[2000010], *vert[maxn];

char str[20], ch;
int n, deg[maxn], m, top, id[maxn], par[maxn], cnt[maxn];

struct node{
	int x, y;
	bool operator <(const node &a)const{
		return a.y > y;
	}
}nod[902];

int my_find(int x){
	if(par[x]==-1){
		return x;
	}
	return par[x]=my_find(par[x]);
}

void add_edge(int x, int y, int &top){
//	printf("%d -> %d\n", x, y);
	edge *p=&edg[++top];
	p->to=y;
	p->next=vert[x];	vert[x]=p;
}

void DFS(int s){
	id[s]=top++;
	for(edge *p=vert[s];p;p=p->next){
		DFS(p->to);
	}
}

void dfs(int s, int fa){
	for(int i=0;i<m;i++){
		if(nod[i].y==id[s]){
			int x=my_find(nod[i].x);
			cnt[x]++;
		}
	}
	for(edge *p=vert[s];p;p=p->next){
		dfs(p->to, s);
	}
	if(fa!=-1){
		par[id[s]]=id[fa];
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		int top = -1;
		memset(deg, 0, sizeof (deg));
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < n; i++) {
			while ((ch = getchar()) == ' ' || ch == '\n' || ch == '\t');
			int u = ch - '0';
			while ((ch = getchar()) != ':') {
				if (ch == ' ' || ch == '\t' || ch == '\n')continue;
				u *= 10;
				u += ch - '0';
			}
			while ((ch = getchar()) != '(');
			m = 0;
			while ((ch = getchar()) != ')') {
				if (ch == ' ' || ch == '\n' || ch == '\t')continue;
				m *= 10;
				m += ch - '0';
			}
			for (int j = 0; j < m; j++) {
				while ((ch = getchar()) == ' ' || ch == '\n' || ch == '\t');
				int v = ch - '0';
				while ((ch = getchar()) != ' ' && ch != '\n' && ch != '\t') {
					v *= 10;
					v += ch - '0';
				}
				add_edge(u, v, top);
				deg[v]++;
			}
		}
		scanf("%d", &m);
		for(int i=0;i<m;i++){
			while((ch=getchar())!='(');
			while((ch=getchar())==' '||ch=='\t'||ch=='\n');
			nod[i].x=ch-'0';
			while((ch=getchar())!=' '&&ch!='\t'&&ch!='\n'){
				nod[i].x*=10;
				nod[i].x+=ch-'0';
			}
			while((ch=getchar())==' '||ch=='\t'||ch=='\n');
			nod[i].y=ch-'0';
			while((ch=getchar())!=')'){
				if(ch==' '||ch=='\n'||ch=='\t')continue;
				nod[i].y*=10;
				nod[i].y+=ch-'0';
			}
		}
//		for(int i=0;i<m;i++){
//			printf("%d %d\n", nod[i].x , nod[i].y);
//		}
//		puts("");
		int root;
		for(int i=1;i<=n;i++){
			if(deg[i]==0){
				root=i;
				break;
			}
		}
		top=0;
		DFS(root);
		for(int i=0;i<m;i++){
			nod[i].x=id[nod[i].x];
			nod[i].y=id[nod[i].y];
			if(nod[i].x>nod[i].y){
				int tem=nod[i].x;
				nod[i].x=nod[i].y;
				nod[i].y=tem;
			}
//			printf("%d %d\n", nod[i].x ,nod[i].y);
		}
		sort(nod, nod+m);
		/*
		for(int i=0;i<m;i++){
			printf("%d %d\n", nod[i].x, nod[i].y);
		}
		*/
		memset(cnt, 0, sizeof(cnt));
		memset(par, -1, sizeof(par));
		dfs(root, -1);
		for(int i=1;i<=n;i++){
			if(cnt[id[i]]){
				printf("%d:%d\n", i, cnt[id[i]]);
			}
		}
	}
	return 0;
}
