#include <cstdio>
#include <cstring>
char str[300];
int main()
{
    int flag=0;
    while(gets(str)){
        int len=strlen(str);
        for(int i=0;i<len;i++){
            if(str[i]=='"'){
                if(flag%2==0)printf("``");
                else
                    printf("''");
                flag++;
            }
            else
                putchar(str[i]);
        }
        puts("");
    }
    return 0;
}
