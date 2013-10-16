#include<stdio.h>
int main()
{
    __int64 n,m,c;
    while(scanf("%I64d%I64d%I64d",&n,&m,&c),m||n||c)
    {
        printf("%I64d\n",((m-7)*(n-7)+c)/2);
    }
    return 0;
}
