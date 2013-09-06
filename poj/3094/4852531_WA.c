#include<stdio.h>
int main()
{
    char c;
    long ans=0;
    int j=1;
    while(1){
        c=getchar();
        if(c=='#')break;
        if(c==' '){j++;continue;}
        if(c=='\n'){
                 printf("%ld\n",ans);
                 j=1;ans=0;
                 continue;
        }
        ans+=j*(c-'A'+1);
     }
     return 0;
}

