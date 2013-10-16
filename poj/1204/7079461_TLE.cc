#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char g[1001][1001], str[1010];

int n, m, mm, dir[8][2]={-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

struct node{
	int x, y;
}now;

vector <node> pos[60];

bool check(int x, int y, int l, int len){
	for(int i=0;i<len;i++){
		if(str[i]!=g[x][y]){
			return false;
		}
		x+=dir[l][0];
		y+=dir[l][1];
	}
	return true;
}

int main(){
	while(scanf("%d%d%d", &n, &m, &mm)!=EOF){
		for(int i=0;i<52;i++){
			pos[i].clear();
		}
		for(int i=0;i<n;i++){
			scanf("%s", g[i]);
			for(int j=0;j<m;j++){
				char ch=g[i][j];
				now.x=i;
				now.y=j;
				if(ch<='Z'&&ch>='A'){
					pos[ch-'A'].push_back(now);
				}
				else {
					pos[ch-'a'+26].push_back(now);
				}
			}
		}
		for(int i=0;i<mm;i++){
			scanf("%s", str);
			int len=strlen(str), k, flag=0;
			if(str[0]<='Z'&&str[0]>='A'){
				k=str[0]-'A';
			}
			else {
				k=str[0]-'a'+26;
			}
			int top=pos[k].size();
			for(int j=0;j<top && !flag;j++){
				for(int l=0;l<8 && !flag;l++){
					int x=pos[k][j].x;
					int y=pos[k][j].y;
					x+=dir[l][0]*(len-1);
					y+=dir[l][1]*(len-1);
					if(x<0||x>=n||y>=m||y<0)continue;
					x-=dir[l][0]*(len-1);
					y-=dir[l][1]*(len-1);
					if(check(x, y, l, len)){
						flag=1;
						printf("%d %d %c\n", x, y, l+'A');
					}
				}
			}
		}
	}
	return 0;
}
