#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

char str[30];

struct Node{
	char str[30];
	bool operator <(const Node &a)const{
		return strcmp(a.str, str) > 0;
	}
}now;
vector <Node> arr[30010];

struct Size{
	int ii;
	int cnt;
	char str[30];
	bool operator <(const Size &a)const{
		if(a.cnt==cnt){
			return strcmp(a.str, str) > 0;
		}
		return a.cnt < cnt;
	}
}size[30010];

int main(){
	int id = 0, len;
	map<string, int>mp, pc;
	map<string, int>::iterator p;
	
	while(scanf("%s", str)!=EOF){
		strcpy(now.str, str);
		
		len = strlen(str);
		sort(str, str+len);
		str[len] = '\0';
		//puts(str);
		
		p = mp.find(str);
		if(p==mp.end()){
			mp[str] = id;
			pc[now.str] = 1;
			arr[id].clear();
			arr[id].push_back(now);
			strcpy(size[id].str, now.str);
			size[id].cnt = 1;
			size[id].ii = id;
			id++;
		}
		else{
			if(pc.find(now.str) == pc.end()){
				int ii = p->second;
				size[ii].cnt++;
				pc[now.str] = 1;
				arr[ii].push_back(now);
				if(strcmp(size[ii].str, now.str) < 0){
					strcpy(size[ii].str, now.str);
				}
			}
		}
	}
	
	sort(size, size + id);
	for(int i = 0; i < 5 && i < id; i++){
		int ii = size[i].ii;
		sort(arr[ii].begin(), arr[ii].end());
		printf("Group of size %d: ", size[i].cnt);
		for(int j = 0; j < arr[ii].size(); j++){
			printf("%s ", arr[ii][j].str);
		}
		puts(".");
	}
	system("pause");
	return 0;
}
