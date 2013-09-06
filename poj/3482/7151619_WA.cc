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
	int ans=0;
	for(++k;k<=base;k++){
		int tem=0;
		for(int i=0;i<len;i++){
			tem*=k;
			tem+=num[i];
		}
		ans+=tem;
	}
	printf("%d\n", ans);
}

int main(){
	while(scanf("%s", dig)!=EOF){

		memset(flag, 0, sizeof(flag));
		int len=strlen(dig);
		for(int i=0;i<len;i++){
			flag[dig[i]]=i;
		}
		getchar();
		while(gets(numb)){
			if(strcmp(numb, "")==0)break;
			solve(len);
		}
	}
	return 0;
}
