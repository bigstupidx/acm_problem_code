#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;

char dig[30], numb[40];
int flag[300], num[40];

void solve(int base){
	int len=strlen(numb), k=0;
	for(int i=0;i<len;i++){
		if(numb[i]!=' '){
			numb[k++]=numb[i];
		}
	}
	len=k, k=-1;
	for(int i=0;i<len;i++){
		num[i]=flag[numb[i]];
		if(k<flag[numb[i]]){
			k=flag[numb[i]];
		}
	}
	long long ans=0;
	for(++k;k<=base;k++){
		long long tem=0;
		for(int i=0;i<len;i++){
			tem*=k;
			tem+=num[i];
		}
		ans+=tem;
	}
	printf("%lld\n", ans);
}

int main(){
	while(gets(dig)){
		if(strcmp(dig, "")==0)continue;
		memset(flag, 0, sizeof(flag));
		int len=strlen(dig);
		for(int i=0;i<len;i++){
			flag[dig[i]]=i;
		}
		while(gets(numb)){
			if(strcmp(numb, "")==0)break;
			solve(len);
		}
	}
	return 0;
}
