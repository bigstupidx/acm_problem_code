#include <cstdio>
#include <cstring>

char map[30], str[100];

int main(){
    gets(map);
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
	if(str[i]<='z'&&str[i]>='a'){
	    printf("%c", map[str[i]-'a']);
	}
	else if(str[i]<='Z'&&str[i]>='A'){
	    printf("%c", map[str[i]-'A']+'A'-'a');
	}
	else {
	    printf("%c", str[i]);
	}
    }
    puts("");
    return 0;
}