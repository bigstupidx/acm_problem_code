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
        while(n)
        {
            len--;
            if(len<0)break;
            int t = ((n % 2) + 2) % 2;
            ans[len] = t + '0';
 /*           if(!(n%2))
                ans[len]='0';
            else
            {
                ans[len]='1';
                if(str[len]=='n')
                    n+=1;
            }
            n/=2;*/
            if (str[len] == 'n') n = (n + t) / 2;
            else n = (n - t) / 2;
        }
        if(len<0)printf("Impossibe\n");
        else{
            for(int i=0;i<len;i++)ans[i]='0';
            puts(ans);
        }
    }
    return 0;    
}
