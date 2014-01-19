#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[5];
int num[5];

int main(){
    while(scanf("%s", str), strcmp(str, "-1")!=0){
        printf("N=%s:\n", str);
        int cnt=0, a, b, c, len=4;
        for(int i=0;i<4;i++){
            num[i]=str[i]-'0';
        }
        if(num[0]==num[1]&&num[0]==num[2]&&num[0]==num[3]){
            puts("No!!");
            continue;
        }
        do{
            sort(num, num+len);
            a=0; b=0;
            for(int i=0;i<len;i++){
                b*=10;
                b+=num[i];
            }
            for(int i=len-1;i>=0;i--){
                a*=10;
                a+=num[i];
            }
            c=a-b;
            printf("%d-%d=%d\n", a, b, c);
            len=0;
            while(c){
                num[len]=c%10;
                c/=10;len++;
            }
            c=a-b;
            cnt++;
        }while(c!=0&&c!=6174);
        printf("Ok!! %d times\n", cnt);
    }
    return 0;
}