#include <cstdio>
#include <cstring>
char str[3][1010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int ii=1;ii<=n;ii++)
    {
        scanf("%s%s%s",str[0],str[1],str[2]);
        printf("Data set %d: ",ii);
        int len=strlen(str[2]);
        int len1=strlen(str[0]);
        int len2=strlen(str[1]);
        if(len!=len1+len2)
        {
            puts("no");
            continue;
        }
        int i,j;
        for(j=0,i=0;i<len1;i++)
        {
            bool flag=false;
            for(;j<len;j++)
            {
                if(str[0][i]==str[2][j])
                {
                    flag=true;
                    j++;break;
                }
            }
            if(!flag)break;
        }
        if(i!=len1)
        {
            puts("no");
            continue;
        }
        for(i=0,j=0;i<len2;i++)
        {
            bool flag=false;
            for(;j<len;j++)
            {
                if(str[1][i]==str[2][j])
                {
                    flag=true;
                    j++;break;
                }
            }
            if(!flag)break;
        }
        if(i==len2)puts("yes");
        else puts("no");
    }
    return 0;
}
