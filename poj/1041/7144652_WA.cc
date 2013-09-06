#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

int deg[50], flag[2000];

struct node{
	int to;
	int st;
	bool operator <(const node &a)const{
		return a.st > st;
	}
}now;

vector <node> mp[50];

void DFS(int s){
	int top=mp[s].size();
	for(int i=0;i<top;i++){
		int st=mp[s][i].st;
		if(flag[st])continue;
		printf("%d ", st);
		flag[st]=1;
		DFS(mp[s][i].to);
	}
}

int main(){
	int x, y, z;
	while(scanf("%d%d", &x, &y), x||y){
		int s;
		scanf("%d", &z);
		memset(deg, 0, sizeof(deg));
		deg[x]++, deg[y]++;

		for(int i=1;i<45;i++){
			mp[i].clear();
		}
		now.st = z;
		now.to = y;
		mp[x].push_back(now);
		now.to = x;
		mp[y].push_back(now);
		s = x > y ? y : x;

		while(scanf("%d%d", &x, &y), x||y){
			scanf("%d", &z);
			deg[x]++, deg[y]++;
			now.st = z;
			now.to = y;
			mp[x].push_back(now);
			now.to = x;
			mp[y].push_back(now);
		}
		int xflag=0;
		for(int i=1;i<45;i++){
			if(deg[i]%2){
				xflag=1;
				break;
			}
		}
		if(xflag){
			puts("Round trip does not exist.");
		}
		else {
			for(int i=1;i<45;i++){
				sort(mp[i].begin(), mp[i].end());
			}
			memset(flag, 0, sizeof(flag));
			DFS(s);
			puts("");
		}
	}
	return 0;
}