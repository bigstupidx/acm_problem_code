#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
	char name[22];
	int weight;
	bool operator <(const node &a)const{
		return a.weight < weight;
	}
}nod[22];

char str[22];

int main(){
	int flag=0;
	while(scanf("%s", str)!=EOF){
		if(flag)puts("");
		else flag=1;
		
		int top=0, day, sta;
		while(scanf("%s", str), strcmp(str, "END")!=0){
			strcpy(nod[top].name, str);
			scanf("%d%d", &day, &sta);
			nod[top].weight=sta-day;
			top++;
		}
		sort(nod, nod+top);
		for(int i=0;i<top;i++){
			printf("%s\n", nod[i].name);
		}
	}
	return 0;
}
