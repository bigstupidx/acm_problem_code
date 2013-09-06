#include <cstdio>
#include <map>
#include <cmath>
#include <cstring>

using namespace std;

char ss[40], pp[40], cc[80], ans[80];

int main(){
	int x, n;
	while(scanf("%d", &x), x){
		int d, len;
		map<char, int>mp1, mp2;
		map<char, int>::iterator p;
		scanf("%s%s%s", ss, pp, cc);
		n=strlen(cc);
		len=strlen(ss);
		d=((int)pow(n, 1.5)+x)%n;
		for(int i=0;i<len;i++){
			mp1[ss[i]]=i;
			mp2[pp[i]]=i;
		}
		ans[n]=0;
		ans[d]=pp[mp1.find(cc[d])->second];
		int i=d, j;
		while((i-1+n)%n!=d){
			j=i;
			i=(i-1+n)%n;
			int x=mp1.find(ans[j])->second;
			int y=mp1.find(cc[i])->second;
			//printf("%d %d %c\n", x, y, pp[x^y]);
			ans[i]=pp[x^y];
		}
		puts(ans);
		//printf("%d\n", d);
	}
	return 0;
}
