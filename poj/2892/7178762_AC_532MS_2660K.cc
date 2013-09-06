#include <cstdio>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

char str[5];
int n, m, d, arr[500010];

int main(){
	while(scanf("%d%d", &n, &m)!=EOF){
		map <int, int> mp;
		map <int, int> ::iterator p;
		mp[0]=1;
		mp[n+1]=1;
		for(int i=0, top=0;i<m;i++){
			scanf("%s", str);
			if(str[0]=='D'){
				scanf("%d", &d);
				mp[d]=1;
				arr[top++]=d;
			}
			else if(str[0]=='Q'){
				scanf("%d", &d);
				p=mp.lower_bound(d);
				//printf("%d\n", p->first);
				if(p->first==d){
					printf("0\n");
				}
				else {
					int y=p->first;
					p--;
					int x=p->first;
					//printf("%d %d\n", y, x);
					printf("%d\n", y-x-1);
				}
			}
			else {
				if(top==0)continue;
				d=arr[--top];
				p=mp.find(d);
				if(p!=mp.end()){
					mp.erase(p);
				}
			}
		}
	}
	return 0;
}
