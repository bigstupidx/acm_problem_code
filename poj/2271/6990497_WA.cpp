#include <cstdio>
#include <cstring>

char str[102], tem[102];

int main(){
//	freopen("out.txt", "w", stdout);
	int cnt=0, len, flag=0;
	while(scanf("%s", str)!=EOF){
		if(strcmp(str, "<br>")==0){
			puts("");
			cnt=0;
		}
		else if(strcmp(str, "<hr>")==0){
			if(cnt)puts("");
			for(int i=0;i<80;i++){
				putchar('-');
			}
			puts("");
			cnt=0;
		}
		else{
			len=strlen(str);
			if(!flag){
				flag=1;
				if(len>80){
					for(int i=0;i<80;i++){
						putchar(str[i]);
					}
					puts("");
					for(int i=80;i<len;i++){
						putchar(str[i]);
					}
					cnt=len-80;
				}
				else{
					printf("%s", str);
					cnt=len;
				}
			}
			else{
				putchar(' ');
				cnt++;
				if(cnt==80){
					cnt=0;
					puts("");
				}
				if(cnt+len>80){
					for(int i=0;i<80-cnt;i++){
						putchar(str[i]);
					}
					puts("");
					for(int i=80-cnt;i<len;i++){
						putchar(str[i]);
					}
					cnt=len+cnt-80;
				}
				else{
					printf("%s",str);
					cnt+=len;
				}
			}
		}
	}
	return 0;
}
