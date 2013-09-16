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
				printf("%s", str);
				cnt=len;
			}
			else{
				if(cnt==0){
					printf("%s", str);
					cnt=len;
				}
				else{
					if(1+cnt+len>80){
						printf("\n%s", str);
						cnt=len;
					}
					else{
						printf("%s",str);
						cnt+=len;
					}
				}
			}
		}
	}
	return 0;
}
