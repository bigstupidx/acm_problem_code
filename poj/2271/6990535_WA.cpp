#include <cstdio>
#include <cstring>

char str[102], tem[102];

int main(){
	freopen("out.txt", "w", stdout);
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
				if(cnt+len+1>80){
					printf("\n%s", str);
					cnt=len;
				}
				else{
					if(strcmp(tem, "<br>")!=0&&strcmp(tem, "<hr>")!=0){
						putchar(' ');
						cnt++;
					}
					printf("%s",str);
					cnt+=len;
				}
			}
		}
		strcpy(tem, str);
	}
	return 0;
}
