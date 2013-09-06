#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

char str[1002];
const int inf = 100000000;
int n, dis[22][22], pre[22][22], arr[102];

struct node{
	int t;
	int d;
	bool operator <(const node &a)const {
		return a.d > d;
	}
}nod[102];

void get_ans(int s, int t){
	if(pre[s][t]==-1)return ;
	int k=pre[s][t];
	get_ans(s, k);
	printf("%d\t", k);
	get_ans(k, t);
}

int main(){
	while(scanf("%d", &n)!=EOF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d", &dis[i][j]);
				if(dis[i][j]==-1){
					dis[i][j]=inf;
				}
			}
		}
		memset(pre, -1, sizeof(pre));
		for(int w=1;w<=n;w++){
			for(int u=1;u<=n;u++){
				if(dis[u][w]!=inf){
					for(int v=1;v<=n;v++){
						if(dis[u][v]>dis[u][w]+dis[w][v]){
							dis[u][v]=dis[u][w]+dis[w][v];
							pre[u][v]=w;
						}
					}
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				printf("%d ", dis[i][j]);
//			}
//			puts("");
//		}
		int s, t, top=0;
		scanf("%d", &s);
		gets(str);
		string st(str);
		istringstream in(st);
		while(in>>t){
			nod[top].t=t;
			nod[top].d=dis[t][s];
			top++;
		}
		sort(nod, nod+top);
//		for(int i=0;i<top;i++){
//			printf("%d %d\n", nod[i].t, nod[i].d);
//		}
		printf("Org	Dest	Time	Path\n");
		for(int i=0;i<top;i++){
			printf("%d\t%d\t%d\t", nod[i].t, s, nod[i].d);
			if(s==nod[i].t){
				printf("%d\n", s);
			}
			else {
				printf("%d\t", nod[i].t);
				get_ans(nod[i].t, s);
				printf("%d\n", s);
			}
		}
	}
	return 0;
}

