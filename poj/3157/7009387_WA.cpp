#include <cstdio>
#include <cstring>

char str[102], ans[102];

int main(){
	while(scanf("%s", str)!=EOF){
		int len=strlen(str);
		int flag=0;
		if(str[0]>'z'||str[0]<'a')flag=1;
		for(int i=0;i<len;i++){
			if(flag==1)continue;
			if(str[i]=='_'){
				if(flag==3||i+1==len||str[i+1]>'z'||str[i+1]<'a'){
					flag=1;
				}
				else {
					flag=2;
				}
			}
			else if(str[i]<='Z'&&str[i]>='A'){
				if(flag==2){
					flag=1;
				}
				else {
					flag=3;
				}
			}
		}
		if(flag==1){
			puts("Error!");
		}
		else if(flag==0){
			puts(str);
		}
		else if(flag==2){
			int k=0;
			for(int i=0;i<len;i++){
				if(str[i]=='_'){
					ans[k++]=str[i+1]+'A'-'a';
					i++;
				}
				else {
					ans[k++]=str[i];
				}
			}
			ans[k]='\0';
			puts(ans);
		}
		else {
			int k=0;
			for(int i=0;i<len;i++){
				if(str[i]>='A'&&str[i]<='Z'){
					ans[k++]='_';
					ans[k++]=str[i]+'a'-'A';
				}
				else {
					ans[k++]=str[i];
				}
			}
			ans[k]='\0';
			puts(ans);
		}
	}
	return 0;
}
