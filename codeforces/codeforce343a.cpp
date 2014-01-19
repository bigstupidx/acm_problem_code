#include <cstdio>
#include <cstring>

using namespace std;

__int64 solve(__int64 a, __int64 b){
	if(a==0)return 0;
	if(a==1)return b;
	return 1 + solve(b%a, a);
}

int main(){
	__int64 a, b;
	while(scanf("%I64d%I64d", &a, &b)!=EOF){
		if(a 
		printf("%I64d\n", solve(a, b));
	}
	return 0;
}
