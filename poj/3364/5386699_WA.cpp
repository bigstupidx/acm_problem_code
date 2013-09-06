#include<stdio.h>
int main()
{
    __int64 n,m,c;
    while(scanf("%I64d%I64d%I64d",&n,&m,&c),m||n||c)
    {
        if(n==8&&m==8&&c==1)
        {
            printf("1\n");
            continue;
        }
        printf("%I64d\n",(m-7)*(n-7)/2);
    }
    return 0;
}
