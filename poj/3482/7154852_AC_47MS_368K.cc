#include <cstdio>
#include <cstring>

char str[1002];
int flag[300], num[1002], ans[1002], bb[1002];

void _multi(int base){
	int count=0;
	for(int i=0;i<1000;i++){
		bb[i]*=base;
		bb[i]+=count;
		count=bb[i]/10;
		bb[i]%=10;
	}
}

void _add(){
	int count=0;
	for(int i=0;i<1000;i++){
		ans[i]+=bb[i]+count;
		count=ans[i]/10;
		ans[i]%=10;
	}
}

void solve(int base){
	int len=strlen(str), k=0;
	for(int i=0;i<len;i++){
		if(str[i]!=' '&&str[i]!='\t'){
			str[k++]=str[i];
		}
	}
	len=k, k=0;
	for(int i=0;i<len;i++){
		num[i]=flag[str[i]];
		if(k<flag[str[i]]){
			k=flag[str[i]];
		}
	}
	memset(ans, 0, sizeof(ans));
	for(++k;k<=base;k++){
		memset(bb, 0, sizeof(bb));
		for(int i=0;i<len;i++){
			_multi(k);
			bb[0]+=num[i];
		}
		_add();
	}
	k=0;
	for(int i=1000;i>=0;i--){
		if(ans[i]){
			k=i;
			break;
		}
	}
	for(;k>=0;k--){
		printf("%d", ans[k]);
	}
	puts("");
}

int main(){
	int xflag=0;
	while(gets(str)){
		if(strcmp(str, "")==0)continue;
		if(xflag)puts("");
		else xflag=1;
		memset(flag, 0, sizeof(flag));
		int len=strlen(str);
		for(int i=0;i<len;i++){
			flag[str[i]]=i;
		}
		while(gets(str)){
			if(strcmp(str, "")==0)break;
			solve(len);
		}
	}
	return 0;
}

