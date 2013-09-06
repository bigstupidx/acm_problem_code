#include <cstdio>
#include <cstring>
char str[1010];
void puts_char(int i){
    if(str[i]==' '){
        putchar('%');
        printf("20");
    }
    else if(str[i]=='!'){
        putchar('%');
        printf("21");
    }
    else if(str[i]=='$'){
        putchar('%');
        printf("24");
    }
    else if(str[i]=='%'){
        putchar('%');
        printf("25");
    }
    else if(str[i]=='('){
        putchar('%');
        printf("28");
    }
    else if(str[i]==')'){
        putchar('%');
        printf("29");
    }
    else if(str[i]=='*'){
        putchar('%');
        printf("2a");
    }
    else
        putchar(str[i]);
}
int main()
{
    while(1){
        gets(str);
        if(strcmp(str,"#")==0)break;
        int len=strlen(str);
        for(int i=0;i<len;i++){
            puts_char(i);
        }
        puts("");
    }
    return 0;
}
