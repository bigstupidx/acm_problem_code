#include<cstdio>
#include <cstring>
#include <cstdlib>

char str[200];

int main(){
	
	while(gets(str)){
		int len = strlen(str);
		int tail = len;
		for(int i = len-1;i>=0;i--){
			if(i==0){
				for(int j = 0;j<tail;j++){
					printf("%c", str[j]);
				}
			}
			
			else if(str[i]==' ')
			{
				for(int j = i+1;j<tail;j++){
					printf("%c", str[j]);
				}
				printf(" ");
				tail = i;
			}else{
			}
		}
		puts("");
	}
	
	return 0;
}
