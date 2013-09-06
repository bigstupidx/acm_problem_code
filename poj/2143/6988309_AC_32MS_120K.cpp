#include <cstdio>
#include <cstring>

int dir[13][3]={
	1,0,0,
	0,1,0,
	0,0,1,
	
	1,0,1,
	1,0,-1,
	0,1,1,
	0,-1,1,
	1,1,0,
	1,-1,0,
	
	-1,1,1,
	1,1,1,
	1,-1,1,
	-1,-1,1
};
int n, m, cnt[10][10], map[10][10][10];

bool check(int x, int y, int z){
	int xx=x, yy=y, zz=z, pl=map[x][y][z];
	for(int i=0;i<13;i++){
		int count=-1;
		x=xx;
		y=yy;
		z=zz;
		while(map[x][y][z]==pl){
			count++;
			x+=dir[i][0];
			if(x<0||x==n)break;
			y+=dir[i][1];
			if(y<0||y==n)break;
			z+=dir[i][2];
			if(z<0||z==n)break;
		}
		x=xx;
		y=yy;
		z=zz;
		while(map[x][y][z]==pl){
			count++;
			x-=dir[i][0];
			if(x<0||x==n)break;
			y-=dir[i][1];
			if(y<0||y==n)break;
			z-=dir[i][2];
			if(z<0||z==n)break;
		}
		//printf("%d ", count);
		if(count>=m)return true;
	}
	//puts("");
	return false;
}

int main(){
	int p;
	while(scanf("%d%d%d", &n, &m, &p), n||m||p){
		int x, y, round, flag=0, now=0;
		memset(cnt, 0, sizeof(cnt));
		memset(map, -1, sizeof(map));
		for(int i=0;i<p;i++){
			scanf("%d%d", &x, &y);
			x--, y--;
			map[x][y][cnt[x][y]]=now;
			if(flag)continue;
			if(check(x, y, cnt[x][y])){
				round=i+1;
				flag=1;
				continue;
			}
			cnt[x][y]++;
			now=(now+1)%2;
		}
		if(!flag)puts("Draw");
		else{
			if(now==0){
				printf("Black %d\n", round);
			}
			else{
				printf("White %d\n", round);
			}
		}
	}
	return 0;
}
