#include <cstdio>
#include <cstring>

char str[12];
int n, x, y, z, p, tem, d;
int dir[6][4]={
	2, 1, 5, 4,
	0, 2, 3, 5,
	0, 4, 3, 1,
	4, 5, 1, 2,
	5, 3, 2, 0,
	1, 3, 4, 0
};

void go_go_go(){
	if(tem==0||tem==3){
		if(dir[tem][p]==2){
			z+=d;
		}
		else if(dir[tem][p]==5){
			z-=d;
		}
		else if(dir[tem][p]==1){
			y+=d;
		}
		else{
			y-=d;
		}
	}
	else if(tem==2||tem==5){
		if(dir[tem][p]==0){
			x+=d;
		}
		else if(dir[tem][p]==4){
			y-=d;
		}
		else if(dir[tem][p]==3){
			x-=d;
		}
		else{
			y+=d;
		}
	}
	else {
		if(dir[tem][p]==0){
			x+=d;
		}
		else if(dir[tem][p]==3){
			x-=d;
		}
		else if(dir[tem][p]==2){
			z+=d;
		}
		else{
			z-=d;
		}
	}
}

void solve(){
	int xx;
	for(int i=0;i<n;i++){
		scanf("%s%d", str, &d);
		if(strcmp(str, "back")==0){
			p=(p+2)%4;
		}
		else if(strcmp(str, "left")==0){
			p=(p+1)%4;
		}
		else if(strcmp(str, "right")==0){
			p=(p+3)%4;
		}
		else if(strcmp(str, "up")==0){
			xx=tem;
			tem=(dir[tem][p]+3)%6;
			for(int j=0;j<4;j++){
				if(dir[tem][j]==xx){
					p=j;
				}
			}
		}
		else if(strcmp(str, "down")==0){
			xx=(tem+3)%6;
			tem=dir[tem][p];
			for(int j=0;j<4;j++){
				if(dir[tem][j]==xx){
					p=j;
				}
			}
		}
		go_go_go();
	}
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		x=0;
		y=0;
		z=0;
		p=0;
		tem=2;
		scanf("%d", &n);
		solve();
		printf("%d %d %d %d\n", x, y, z, dir[tem][p]);
	}
	return 0;
}
