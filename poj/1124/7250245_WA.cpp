#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

struct edge{
	int to;
	int flag;
	edge *next;
}edg[100010], *vert[404];

char str[22][22], tem[12];
const int inf = 100000000;
int n, m, dis[2][404], mark[404], que[404];
int deg[404], dir[4][2]={-1, 0, 1, 0, 0, 1, 0, -1};
double map[22][22], ans[22][22];

struct entrance{
	int x, y;
}ent[30];

struct QN{
	int u;
	int d;
	bool operator <(const QN &a)const{
		return a.d < d;
	}
}now;

void add_edge(int x, int y, int &top){
//	printf("%d %d\n", x, y);
	edge *p=&edg[++top];
	p->to=y;
	p->next=vert[x];	vert[x]=p;
}

void dijkstra(int s, int ii){
	priority_queue <QN> Q;
	for(int i=0;i<n;i++){
		dis[ii][i]=inf;
		mark[i]=0;
	}
	now.u=s;
	now.d=0;
	Q.push(now);
	dis[ii][s]=0;
	for(int k, i=1;i<n;i++){
		do{
			if(Q.empty())return ;
			now=Q.top();Q.pop();
			k=now.u;
		}while(mark[k]);
		mark[k]=1;
		for(edge *p=vert[k];p;p=p->next){
			if(!mark[p->to]&&dis[ii][p->to]>dis[ii][k]+1){
				dis[ii][p->to]=dis[ii][k]+1;
				now.u=p->to;
				now.d=dis[ii][p->to];
				Q.push(now);
			}
		}
	}
}

int main(){
	int top=-1, k=0;
	scanf("%d%d", &m, &n);
	for(int i=0;i<n;i++){
		scanf("%s", str[i]);
	}
	int r=n, c=m;
	for(int u, v, i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(str[i][j]=='X')continue;
			u=i*m+j;
			if(str[i][j]!='.'){
				ent[str[i][j]-'A'].x=i;
				ent[str[i][j]-'A'].y=j;
			}
			for(int k=0;k<4;k++){
				int ii=i+dir[k][0];
				int jj=j+dir[k][1];
				if(ii<0||ii==n||jj<0||jj==m)continue;
				if(str[ii][jj]=='X')continue;
				add_edge(u, ii*m+jj, top);
			}
		}
	}
	n=n*m;
	while(scanf("%s", tem)!=EOF){
		if(strcmp(tem, "XX")==0)break;
		int s=ent[tem[0]-'A'].x*m+ent[tem[0]-'A'].y;
		int t=ent[tem[1]-'A'].x*m+ent[tem[1]-'A'].y;
		dijkstra(s, 0);
		dijkstra(t, 1);
		memset(deg, 0, sizeof(deg));
		memset(map, 0, sizeof(map));
		memset(mark, 0, sizeof(mark));
		int dd=dis[0][t]-1;
		for(int i=0;i<n;i++){
			for(edge *p=vert[i];p;p=p->next){
				if(dd==dis[0][i]+dis[1][p->to]){
					mark[i]=1;
					mark[p->to]=1;
					deg[p->to]++;
					p->flag=1;
//					printf("%d %d\n", i, p->to);
				}
				else {
					p->flag=0;
				}
			}
		}
		int load;
		scanf("%d", &load);
		map[s/m][s%m]=load;
		queue <int> Q;
		Q.push(s);
		while(!Q.empty()){
			int i=Q.front();
			Q.pop();
			int cnt=0, tot=0;
			for(edge *p=vert[i];p;p=p->next){
				if(p->flag){
					cnt++;
					que[tot++]=p->to;
					if(--deg[p->to]==0){
						Q.push(p->to);
					}
				}
			}
			double aver=map[i/m][i%m]/cnt;
			for(int j=0;j<tot;j++){
				int u=que[j];
				map[u/m][u%m]+=aver;
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(i*c+j==s)continue;
				if(i*c+j==t)continue;
				ans[i][j]+=map[i][j];
			}
		}
	}
	scanf("%d", &top);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%.2lf ", ans[i][j]);
		}
		puts("");
	}
	system("pause");
	return 0;
}
