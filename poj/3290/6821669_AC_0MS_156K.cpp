#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char str[102];

int main()
{
	while(scanf("%s", str), strcmp("0",str)!=0){
		vector<char>lower,upper;
		int len=strlen(str),cnt=0;
		for(int i=0;i<len;i++){
			if(str[i]=='N')cnt++;
			else if(str[i]<'z'&&str[i]>'a')
				lower.push_back(str[i]);
			else
				upper.push_back(str[i]);
		}
		if(lower.empty()){
			puts("no WFF possible");
			continue;
		}
		while(cnt--)putchar('N');
		int n = lower.size()-1,i;
		if(upper.size()<n)n=upper.size();
		for(i=0;i<n;i++){
			putchar(upper[i]);
			putchar(lower[i]);
		}
		printf("%c\n",lower[n]);
	}
	return 0;
}