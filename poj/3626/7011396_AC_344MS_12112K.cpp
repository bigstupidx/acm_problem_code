#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int inf = 1000000000;
int m, mark[1010][1010], map[1010][1010];
int dis[1010][1010], dir[4][2]={-1,0,1,0,0,-1,0,1};

struct QN{
    int ii,jj;
    int d;
    bool operator <(const QN &a)const{
	return a.d < d;
    }
}now;

int dijkstra(int si,int sj){
    priority_queue<QN>Q;
    for(int i=0;i<1001;i++){
	for(int j=0;j<1001;j++){
	    dis[i][j]=inf;
	    mark[i][j]=0;
	}
    }
    now.ii=500;
    now.jj=500;
    now.d=0;
    Q.push(now);
    dis[500][500]=0;
    while(!Q.empty()){
	now=Q.top();Q.pop();
	int ii=now.ii;
	int jj=now.jj;
	if(mark[ii][jj])continue;
	mark[ii][jj]=1;
	if(ii==si&&jj==sj)return now.d;
	for(int k=0;k<4;k++){
	    int x=ii+dir[k][0];
	    int y=jj+dir[k][1];
	    if(x<0||x>1000||y<0||y>1000)continue;
	    if(!map[x][y]&&dis[x][y]>dis[ii][jj]+1){
		dis[x][y]=dis[ii][jj]+1;
		now.ii=x;
		now.jj=y;
		now.d=dis[x][y];
		Q.push(now);
	    }
	}
    }
}
int main(){
    int x, y;
    while(scanf("%d%d%d", &x, &y, &m)!=EOF){
	memset(map, 0, sizeof(map));
	for(int i=0;i<m;i++){
	    int ii, jj;
	    scanf("%d%d", &ii, &jj);
	    map[ii+500][jj+500]=1;
	}
	printf("%d\n", dijkstra(x+500, y+500));
    }
    return 0;
}