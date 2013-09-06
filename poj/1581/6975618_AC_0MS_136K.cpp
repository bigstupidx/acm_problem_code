#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
	char name[100];
	int cnt, pen;
	bool operator <(const node &a)const{
		if(a.cnt==cnt)
			return a.pen > pen;
		return a.cnt < cnt;
	}
}nod[1010];

int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		
		int cnt, time;
		for(int i=0;i<n;i++){
			scanf("%s", nod[i].name);
			nod[i].cnt=0;
			nod[i].pen=0;
			for(int j=0;j<4;j++){
				scanf("%d%d", &cnt, &time);
				if(time){
					nod[i].cnt++;
					nod[i].pen+=(cnt-1)*20+time;
				}
			}
		}
		sort(nod, nod+n);
		printf("%s %d %d\n", nod[0].name, nod[0].cnt, nod[0].pen);
	}
	return 0;
}
