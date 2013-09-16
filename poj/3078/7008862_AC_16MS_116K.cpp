#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char tem[12];

struct node{
	int id;
	char str[12];
	bool operator <(const node &a)const{
		return a.id > id;
	}
}nod[22];

int flag[2][22];

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=1;i<=n;i++){
			scanf("%s", nod[i].str);
			nod[i].id=i;
		}
		memset(flag, 0, sizeof(flag));
		for(int i=0;i<m;i++){
			int x, y;
			scanf("%d%d", &x, &y);
			nod[x].id=y;
			flag[0][x]=1;
			flag[1][y]=1;
		}
		int x=1;
		for(int i=1;i<=n;i++){
			if(!flag[0][i]){
				while(flag[1][x])x++;
				nod[i].id=x;
				x++;
			}
		}
		sort(nod+1, nod+n+1);
		for(int i=1;i<=n;i++){
			printf("%s ", nod[i].str);
		}
		puts("");
	}
	return 0;
}
