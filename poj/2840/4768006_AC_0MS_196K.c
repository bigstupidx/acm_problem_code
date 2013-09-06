#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               int m,n;
               scanf("%d:%d",&m,&n);
               if(n!=0){ printf("0\n");continue;}
               if(m<=12)printf("%d\n",m+12);
               else printf("%d\n",m-12);
    }
    return 0;
}
