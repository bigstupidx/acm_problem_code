#include <cstdio>
#include <cstring>

using namespace std;

char str[230];

int main(){
	while(gets(str)){//start
		if(strcmp(str, "ENDOFINPUT")==0)break;
		
		gets(str);
		for(int i = 0, n = strlen(str);i<n;i++){
			if(str[i]>='A' && str[i]<='Z'){
				putchar((str[i]-'A'-5+26)%26 +'A');
			}
			else{
				putchar(str[i]);
			}
		}
		puts("");
		
		gets(str);//end
	}
	return 0;
}
