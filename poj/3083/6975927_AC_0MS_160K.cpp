#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

char map[50][50];
const int inf = 100000000;
int n, m, sx, sy, ex, ey, dd, dir[4][2]={1,0,-1,0,0,-1,0,1}, dis[3000];

struct QN{
	int x;
	int y;
	int d;
	int dir;
	bool operator <(const QN &a)const{
		return a.d < d;
	}
}now;

int left_dfs(){
	priority_queue<QN>Q;
	now.x=sx;
	now.y=sy;
	now.d=1;
	now.dir=dd;
	Q.push(now);
	while(1){
		now=Q.top();
		Q.pop();
		int x=now.x;
		int y=now.y;
		if(x==ex&&y==ey)return now.d;
		//printf("%d %d %d %d\n", x, y, now.d, now.dir);
		//getchar();
		if(now.dir==0){
			if(map[x][y+1]=='#'){
				if(map[x+1][y]=='.'){
					now.x++;
					now.d++;
					Q.push(now);
				}
				else{
					now.dir=2;
					Q.push(now);
				}
			}
			else{
				now.y++;
				now.d++;
				now.dir=3;
				Q.push(now);
			}
		}
		else if(now.dir==1){
			if(map[x][y-1]=='#'){
				if(map[x-1][y]=='.'){
					now.x--;
					now.d++;
					Q.push(now);
				}
				else{
					now.dir=3;
					Q.push(now);
				}
			}
			else{
				now.y--;
				now.d++;
				now.dir=2;
				Q.push(now);
			}
		}
		else if(now.dir==2){
			if(map[x+1][y]=='#'){
				if(map[x][y-1]=='.'){
					now.y--;
					now.d++;
					Q.push(now);
				}
				else{
					now.dir=1;
					Q.push(now);
				}	
			}
			else{
				now.x++;
				now.d++;
				now.dir=0;
				Q.push(now);
			}
		}
		else {
			if(map[x-1][y]=='#'){
				if(map[x][y+1]=='.'){
					now.y++;
					now.d++;
					Q.push(now);
				}
				else{
					now.dir=0;
					Q.push(now);
				}
			}
			else {
				now.x--;
				now.d++;
				now.dir=1;
				Q.push(now);
			}
		}
	}
}
int right_dfs(){
	priority_queue<QN>Q;
	now.x=sx;
	now.y=sy;
	now.d=1;
	now.dir=dd;
	Q.push(now);
	while(1){
		now=Q.top();
		Q.pop();
		int x=now.x;
		int y=now.y;
		if(x==ex&&y==ey)return now.d;
		//printf("%d %d %d %d\n", x, y, now.d, now.dir);
		//getchar();
		if(now.dir==0){
			if(map[x][y-1]=='#'){
				if(map[x+1][y]=='.'){
					now.x++;
					now.d++;
					Q.push(now);
				}
				else{
					now.dir=3;
					Q.push(now);
				}
			}
			else{
				now.y--;
				now.d++;
				now.dir=2;
				Q.push(now);
			}
		}
		else if(now.dir==1){
			if(map[x][y+1]=='#'){
				if(map[x-1][y]=='.'){
					now.x--;
					now.d++;
					Q.push(now);
				}
				else{
					now.dir=2;
					Q.push(now);
				}
			}
			else{
				now.y++;
				now.d++;
				now.dir=3;
				Q.push(now);
			}
		}
		else if(now.dir==2){
			if(map[x-1][y]=='#'){
				if(map[x][y-1]=='.'){
					now.y--;
					now.d++;
					Q.push(now);
				}
				else{
					now.dir=0;
					Q.push(now);
				}	
			}
			else{
				now.x--;
				now.d++;
				now.dir=1;
				Q.push(now);
			}
		}
		else {
			if(map[x+1][y]=='#'){
				if(map[x][y+1]=='.'){
					now.y++;
					now.d++;
					Q.push(now);
				}
				else{
					now.dir=1;
					Q.push(now);
				}
			}
			else {
				now.x++;
				now.d++;
				now.dir=0;
				Q.push(now);
			}
		}
	}
}

int short_dfs(){
	priority_queue<QN>Q;
	for(int i=0;i<n*m;i++)dis[i]=inf;
	dis[sx*m+sy]=1;
	now.x=sx;
	now.y=sy;
	now.d=1;
	Q.push(now);
	while(1){
		now=Q.top();
		Q.pop();
		int x=now.x;
		int y=now.y;
		if(x==ex&&y==ey)return now.d;
		//printf("%d %d %d %d\n", x, y, now.d, now.dir);
		//getchar();
		for(int i=0;i<4;i++){
			int ii=x+dir[i][0];
			int jj=y+dir[i][1];
			if(ii<0||ii==n||jj==m||jj<0||map[ii][jj]=='#')continue;
			if(dis[ii*m+jj]>dis[x*m+y]+1){
				dis[ii*m+jj]=dis[x*m+y]+1;
				now.x=ii;
				now.y=jj;
				now.d=dis[ii*m+jj];
				Q.push(now);
			}
		}
	}
}
int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		scanf("%d%d", &m, &n);
		for(int i=0;i<n;i++){
			scanf("%s", map[i]);
			for(int j=0;j<m;j++){
				if(map[i][j]=='S'){
					sx=i;
					sy=j;
					map[i][j]='.';
				}
				else if(map[i][j]=='E'){
					ex=i;
					ey=j;
					map[i][j]='.';
				}
			}
		}
		if(sx==0)dd=0;
		else if(sx==n-1)dd=1;
		else if(sy==m-1)dd=2;
		else dd=3;
		
		int ans1=left_dfs();
		int ans2=right_dfs();
		int ans3=short_dfs();
		
		printf("%d %d %d\n", ans1, ans2, ans3);
	}
	return 0;
}
