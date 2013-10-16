#include <cstdio>
#include <cstring>

char str[2][20];

int get_num(int now){
	int len=strlen(str[now]);
	int sign=1, num=0, i=0;
	if(str[now][0]=='-'){
		i++;
		sign*=-1;
	}
	if(str[now][0]=='+'){
		i++;
	}
	for(;i<len;i++){
		num*=10;
		num+=str[now][i]-'0';
	}
	return sign*num;
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		scanf("%s%s", str[0], str[1]);
		printf("%d\n", get_num(0)+get_num(1));
	}
	return 0;
}
