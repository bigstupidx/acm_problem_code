#include <cstdio>
#include <cstring>

char str[2][300];
int ans[1010];

void revers_str(int k){
	int len=strlen(str[k]);
	for(int j,i=0;i<len;i++){
		j=len-i-1;
		if(i>=j)break;
		char ch;
		ch=str[k][i];
		str[k][i]=str[k][j];
		str[k][j]=ch;
	}
}

int main(){
	while(scanf("%s%s", str[0], str[1])!=EOF){
		int len1=strlen(str[0]);
		int len2=strlen(str[1]);
		revers_str(0);
		revers_str(1);
		memset(ans, 0, sizeof(ans));
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				ans[i+j]+=(str[0][i]-'0')*(str[1][j]-'0');
			}
		}
		len1+=len2;
		for(int i=0;i<len1;i++){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		int i=len1;
		for(;i>=0;i--){
			if(ans[i])break;
		}
		if(i==-1)puts("0");
		else{
			for(;i>=0;i--){
				printf("%d", ans[i]);
			}
			puts("");
		}
	}
	return 0;
}
