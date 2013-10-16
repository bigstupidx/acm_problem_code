#include<stdio.h>
int main()
{
    int n,m,c;
    while(scanf("%d%d%d",&n,&m,&c),m||n||c)
    {
        __int64 ans;
        ans=(m-7)*(n-7);
        if(n==8&&m==8&&c==1)
        {
            printf("1\n");
            continue;
        }
        printf("%I64d\n",ans/2);
    }
    return 0;
}
