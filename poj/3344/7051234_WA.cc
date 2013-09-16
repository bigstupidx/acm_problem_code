#include <cstdio>
#include <cstring>

char map[12][12], que[12], tem[12];
int x, y, d, dir[4][2]={0, 1, 1, 0, 0, -1, -1, 0};

void my_move(int len){
    int top=0, cnt=0, ii, jj, k=1;
    while(1){
	int xx=x+k*dir[d][0];
	int yy=y+k*dir[d][1];
	if(xx<0||xx>7||yy<0||yy>7)break;
	if(map[xx][yy]=='.'){
	    if(++cnt==len){
		ii=xx, jj=yy;
		break;
	    }
	}
	else {
	    que[top++]=map[xx][yy];
	}
	k++;
    }
    if(cnt==len){
	k=len+1;
	while(1){
	    int xx=x+k*dir[d][0];
	    int yy=y+k*dir[d][1];
	    if(d==3&&xx<ii||d==1&&xx>ii||d==2&&yy<jj||d==0&&yy>jj)break;
	    map[xx][yy]=que[k-len-1];
	    k++;
	}
    }
    else {
	k=len+1;
	while(1){
	    int xx=x+k*dir[d][0];
	    int yy=y+k*dir[d][1];
	    if(xx<0||xx>7||yy<0||yy>7)break;
	    map[xx][yy]=que[k-len-1];
	    k++;
	}
    }
    for(int i=1;i<=len;i++){
	int xx=x+dir[d][0];
	int yy=y+dir[d][1];
	if(xx<0||xx==8||yy<0||yy==8)break;
	x=xx;
	y=yy;
	map[x][y]='.';
    }
}

int main(){
    while(scanf("%s", tem), strcmp(tem, "--")!=0){
	strcpy(map[0], tem);
	for(int i=1;i<8;i++){
	    scanf("%s", map[i]);
	}
	for(int i=0;i<8;i++){
	    for(int j=0;j<8;j++){
		if(map[i][j]=='>'){
		    x=i, y=j;
		    d=0;
		    break;
		}
		else if(map[i][j]=='v'){
		    x=i, y=j;
		    d=1;
		    break;
		}
		else if(map[i][j]=='<'){
		    x=i, y=j;
		    d=2;
		    break;
		}
		else if(map[i][j]=='^'){
		    x=i, y=j;
		    d=3;
		    break;
		}
	    }
	}
	map[x][y]='.';
	while(scanf("%s", &tem), strcmp(tem, "#")!=0){
	    if(strcmp(tem, "move")==0){
		int len;
		scanf("%d", &len);
		if(len){
		    my_move(len);
		}
	    }
	    else {
		scanf("%s", tem);
		if(strcmp(tem, "right")==0){
		    d=(d+1)%4;
		}
		else {
		    d=(d+3)%4;
		}
	    }
	}
	if(d==0){
	    map[x][y]='>';
	}
	else if(d==1){
	    map[x][y]='v';
	}
	else if(d==2){
	    map[x][y]='<';
	}
	else {
	    map[x][y]='^';
	}
	for(int i=0;i<8;i++){
	    for(int j=0;j<8;j++){
		printf("%c", map[i][j]);
	    }
	    puts("");
	}
	puts("");
    }
    return 0;
}
