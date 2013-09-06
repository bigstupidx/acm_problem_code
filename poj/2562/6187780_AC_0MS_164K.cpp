#include <cstdio>
#include <cstring>
int main()
{
    int cc[12],dd[12];
    char aa[12],bb[12];
    while(scanf("%s%s",aa,bb))
    {
        if(strcmp(aa,"0")==0&&strcmp(bb,"0")==0)break;
        
        memset(cc,0,sizeof(cc));
        memset(dd,0,sizeof(dd));
        
        int lenc=strlen(aa);
        for(int i=0;i<lenc;i++)
            cc[i]=aa[lenc-i-1]-'0';
        
        int lend=strlen(bb);
        for(int i=0;i<lend;i++)
            dd[i]=bb[lend-i-1]-'0';
        
        //for(int i=0;i<lenc;i++)
        //    printf("%d ",cc[i]);
        //puts("");
        //for(int i=0;i<lend;i++)
        //    printf("%d ",dd[i]);
        //puts("");
        
        int len=lenc>lend?lenc:lend;
        int ans=0,carry=0;
        for(int i=0;i<=len;i++)
        {
            if(cc[i]+dd[i]+carry>=10)
            {
                carry=(cc[i]+dd[i]+carry)/10;
                ans++;
            }
        }
        if(ans==0)
            puts("No carry operation.");
        else if(ans==1)
            puts("1 carry operation.");
        else printf("%d carry operations.\n",ans);
    }
    return 0;
}
