#include <cstdio>
#include <deque>
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
		deque<char>ans;
		int n=lower.size()-1;
		if(n>upper.size())n=upper.size();
		ans.push_back(lower[n]);
		while(n--){
			ans.push_front(lower[n]);
			ans.push_front(upper[n]);
		}
		while(cnt--)ans.push_front('N');
		for(int i=0;i<ans.size();i++){
			putchar(ans[i]);
		}
		puts("");
	}
	return 0;
}