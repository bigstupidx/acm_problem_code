#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	int u,v,bh;
}a[10010];
int du[10010],p[10010],top,bhtop;
int f(int x)
{
	if(x!=p[x])p[x]=f(p[x]);
	return p[x];
}
bool op(node x,node y){return x.v<y.v;}
struct treenode{
	int to;
	treenode*next;
}*list[10010],edge[10010];
struct checknode{
	int source,target,ns,nt,ans;
}check[10010];
int newbh[10010];
void doit(int k,int from) {
	for (treenode*p=list[k];p;p=p->next) if (p->to!=from) {
		doit(p->to,k);
	}
	newbh[k]=++bhtop;
}
void doit2(int k,int from) {
	if (check[1].nt==newbh[k]) 
	check[1].ans=f(check[1].source);
	for (treenode*poi=list[k];poi;poi=poi->next) if (poi->to!=from) {
		doit2(poi->to,k);
		p[poi->to]=f(k);
	}
}

int main()
{
	int nn,n,m,source,target;
	//freopen("c:\\input.txt","r",stdin);
	scanf("%d",&nn);
	while (nn--) {
		scanf("%d",&n);
		memset(du,0,sizeof(du));
		memset(list,0,sizeof(list));
		top=bhtop=0;
		for (int i=1;i<n;i++) {
			scanf("%d%d",&a[i].u,&a[i].v);
			du[a[i].v]++;
			
			edge[++top].to=a[i].v;
			edge[top].next=list[a[i].u];
			list[a[i].u]=edge+top;
			
			edge[++top].to=a[i].u;
			edge[top].next=list[a[i].v];
			list[a[i].v]=edge+top;
		}
		//scanf("%d",&m);
		m=1;
		for (int i=1;i<=m;i++) scanf("%d%d",&check[i].source,&check[i].target);
		int root;
		for (int i=1;i<=n;i++) if (du[i]==0) {root=i;break;}
		for (int i=1;i<=n;i++) p[i]=i;
		doit(root,0);
		for (int i=1;i<=n;i++) {
			check[i].ns=newbh[check[i].source];
			check[i].nt=newbh[check[i].target];
			if (check[i].ns>check[i].nt) swap(check[i].ns,check[i].nt);
		}
		doit2(root,0);
		printf("%d\n",check[1].ans);
	}
}
