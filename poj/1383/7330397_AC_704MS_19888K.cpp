#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 1000010

using namespace std;

struct edge{
	int to;
	edge *next;
}edg[2*maxn], *vert[maxn];

char str[1002][1002];
int n, m, deg[maxn], dir[4][2]={-1, 0, 0, 1, 1, 0, 0, -1};
int que[2][maxn], mark[maxn];

void add_edge(int x, int y, int &top){
	edge *p=&edg[++top];
	p->to=y;
	p->next=vert[x];	vert[x]=p;
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		int top=-1;
		scanf("%d%d", &m, &n);
		memset(deg, 0, sizeof(deg));
		memset(mark, 0, sizeof(mark));
		memset(vert, 0, sizeof(vert));
		for(int i=0;i<n;i++){
			scanf("%s", str[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(str[i][j]=='.'){
					for(int k=0;k<4;k++){
						int ii=dir[k][0]+i;
						int jj=dir[k][1]+j;
						if(ii<0||ii==n||jj==m||jj<0)continue;
						if(str[ii][jj]=='.'){
							add_edge(i*m+j, ii*m+jj, top);
							deg[i*m+j]++;
						}
					}
				}
			}
		}
		int ans=0;
		n=n*m-1, top=0;
		for(int i=0;i<n;i++){
			if(deg[i]==1){
				mark[i]=1;
				que[0][top++]=i;
			}
		}
		int now=0;
		while(top){
			int tot=0;
			for(int i=0;i<top;i++){
				deg[que[now][i]]=0;
				//printf("%d ", que[now][i]);
				for(edge *p=vert[que[now][i]];p;p=p->next){
					if(!mark[p->to]&&(--deg[p->to]==1)){
						mark[p->to]=1;
						que[1-now][tot++]=p->to;
					}
				}
			}
			//puts("");
			if(tot==0){
				ans++;
				break;
			}
			else if(tot==1){
				ans+=2;
				break;
			}
			ans+=2;
			now=1-now;
			top=tot;
		}
		printf("Maximum rope length is %d.\n", ans);
	}
	return 0;
}

