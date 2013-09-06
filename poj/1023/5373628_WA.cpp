#include<stdio.h>
#include<string>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        __int64 len,n;
        char str[65],ans[65];
        scanf("%I64d%s%I64d",&len,str,&n);
        ans[len]='\0';
        while (n)
        {
            len--;
            if(len<0)break;
            if(!(n%2))
                ans[len]='0';
            else
            {
                ans[len]='1';
                if(str[len]=='n')
                    n++;
                else n--;//错误一 
            }
            n/=2;
        }
        if(len<0)printf("Impossibe\n");
        else{
            for(int i=0;i<len;i++)ans[i]='0';
            puts(ans);
        }
    }
    return 0;    
}