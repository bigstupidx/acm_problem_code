#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		int cnt=1, num=n;
		map<int, int> mp;
		map<int, int> ::iterator p;
		do{
			cnt++;
			mp[num]=cnt;
			num%=100000;
			num/=10;
			//printf("%d ", num);
			num*=num;
			//printf(" %d ", num);
			num%=1000000;
			//printf("%d\n", num);
			p=mp.find(num);
		}while(p==mp.end());
		n=p->second;
		printf("%d %d %d\n",num, cnt-n+1, cnt-1); 
	}
	return 0;
}

