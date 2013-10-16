#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char g[1001][1001], str[1010];

int n, m, mm, cnt[60];
int dir[8][2]={-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

struct node{
	int x, y;
	node *next;
}nod[1000002], *vert[60];

void add(int x, int y, int ii, int &top){
	node *p=&nod[++top];
	p->x=x;
	p->y=y;
	p->next=vert[ii];	vert[ii]=p;
}

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
		int top=-1;
		memset(vert, 0, sizeof(vert));
		for(int i=0;i<n;i++){
			scanf("%s", g[i]);
			for(int j=0;j<m;j++){
				int v;
				if(g[i][j]<='Z'&&g[i][j]>='A'){
					v=g[i][j]-'A';
				}
				else {
					v=g[i][j]-'a'+26;
				}
				add(i, j, v, top);
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
			for(node *p=vert[k];p;p=p->next){
				for(int l=0;l<8 && !flag;l++){
					int x=p->x;
					int y=p->y;
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
