#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char g[1002][1002], str[2002];
int n, m, mm, dir[8][2]={-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

struct node{
	int x, y;
}now;

vector <node> pos[60];

bool check(int k, int j, int l){
	int len=strlen(str);
	int x=pos[k][j].x;
	int y=pos[k][j].y;
	for(int i=0;i<len;i++, x+=dir[l][0], y+=dir[l][1]){
		if(x<0||x==n||y<0||y==m)return false;
		if(str[i]!=g[x][y]){
			return false;
		}
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
				now.x=i;
				now.y=j;
				if(g[i][j]<='Z'&&g[i][j]>='A'){
					pos[g[i][j]-'A'].push_back(now);
				}
				else {
					pos[g[i][j]-'a'+26].push_back(now);
				}
			}
		}
		for(int i=0;i<mm;i++){
			scanf("%s", str);
			int k, flag=0;
			if(str[0]<='Z'){
				k=str[0]-'A';
			}
			else {
				k=str[0]-'a'+26;
			}
			for(int j=0;j<pos[k].size()&&!flag;j++){
				for(int l=0;l<8&&!flag;l++){
					if(check(k, j, l)){
						flag=1;
						printf("%d %d %c\n", pos[k][j].x, pos[k][j].y, l+'A');
					}
				}
			}
		}
	}
	return 0;
}
