#include<stdio.h>
int main()
{
    char c;
    long ans;
    int j=1;
    while(1){
        c=getchar();
        if(c=='#')break;
        if(c==' '){j++;continue;}
        if(c=='/n'){
                 printf("%ld\n",ans);
                 j=1;
                 continue;
        }
        ans+=j*(c-'A'+1);
     }
     return 0;
}

