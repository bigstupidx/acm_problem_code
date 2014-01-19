#include <cstdio>
#include <cstring>
char str[100];
int num[3][12],ans[12];
int main()
{
    while(1)
    {
        scanf("%s",str);
        if(strcmp(str,"0+0=0")==0)
        {
            puts("True");break;
        }
        int a,b,c,len=strlen(str);
        memset(num,0,sizeof(num));
        memset(ans,0,sizeof(ans));
        for(int j,i=0;i<=len;i++)
        {
            if(str[i]=='+')
            {
                j=i+1;
                for(int k=0;k<i;k++)
                    num[0][k]=str[k]-'0';
                a=i;
            }
            else if(str[i]=='=')
            {
                b=i-j;
                for(int k=j;k<i;k++)
                    num[1][k-j]=str[k]-'0';
                j=i+1;
            }
            else if(str[i]=='\0')
            {
                c=i-j;
                for(int k=j;k<i;k++)
                    num[2][k-j]=str[k]-'0';
            }
        }
        /*
        for(int i=0;i<a;i++)
            printf("%d ",num[0][i]);
        puts("");
        for(int i=0;i<b;i++)
            printf("%d ",num[1][i]);
        puts("");
        for(int i=0;i<c;i++)
            printf("%d ",num[2][i]);
        puts("");
        */
        len=a>b?a+2:b+2;
        int carry=0,flag=0;
        for(int i=0;i<=len;i++)
        {
            ans[i]=carry+num[0][i]+num[1][i];
            if(ans[i]>=10)
            {
                carry=ans[i]/10;
                ans[i]%=10;
                if(ans[i]!=num[2][i])
                {   flag=1;break;   }
            }
            else
            {
                if(ans[i]!=num[2][i])
                {   flag=1;break;   }
                carry=0;
            }
        }
        for(int i=len;i<=c;i++)
        {
            if(num[2][i])
            {   flag=1;break;   }
        }
        if(flag)puts("False");
        else puts("True");
    }
    //getchar();
    return 0;
}
