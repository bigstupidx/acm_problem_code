#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 100010

struct node{
	int x,y;
}nodes[MAX];

int used[MAX],a[MAX];
int E[MAX][2],L;

bool cmp1(int i,int j)
{
	if(nodes[i].x==nodes[j].x)
		return nodes[i].y<nodes[j].y;
	return nodes[i].x<nodes[j].x;
}
bool cmp2(int i,int j)
{
	if(nodes[i].y==nodes[j].y)
		return nodes[i].x<nodes[j].x;
	return nodes[i].y<nodes[j].y;
}
void work(int x)
{
	L++;
	used[x]=1;
	if(!used[E[x][0]])work(E[x][0]);
	if(!used[E[x][1]])work(E[x][1]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int i,n,flag=0,ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&nodes[i].x,&nodes[i].y);
			used[i]=0;
			E[i][0]=E[i][1]=-1;
			a[i]=i;
		}
		if(n&1)flag=1;
		else{
			L=1;
			sort(a,a+n,cmp1);
			for(i=0;i<n;i+=2){
				if(nodes[a[i]].x!=nodes[a[i+1]].x){
					flag=1;
					break;
				}
				ans+=nodes[a[i+1]].y-nodes[a[i]].y;
				E[a[i+1]][0]=a[i];
				E[a[i]][0]=a[i+1];
			}
			if(!flag){
				sort(a,a+n,cmp2);
				for(i=0;i<n;i+=2){
					if(nodes[a[i]].y!=nodes[a[i+1]].y){
						flag=1;
						break;
					}
					ans+=nodes[a[i+1]].x-nodes[a[i]].x;
					E[a[i+1]][1]=a[i];
					E[a[i]][1]=a[i+1];
				}
			}
			used[0]=1;
			if(!flag)work(E[0][0]);
		}
		if(flag||L<n)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}