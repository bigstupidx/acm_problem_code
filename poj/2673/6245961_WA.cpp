#include <cstdio>
#include <cstring>
int main()
{
    __int64 t,v,ans;
    while(scanf("%I64d%I64d",&t,&v)!=EOF)
    {
        int m,mini=10000000;
        scanf("%d",&m); ans=0;
        while(m--)
        {
            int tem,si,di;
            scanf("%d%d",&di,&si);
            tem=(int)(di*1.0/si);
            if(tem*si==di)tem--;
            if(tem<mini)mini=tem;
        }
        ans+=v*mini;
        ans+=v*((t-mini)/2);
        printf("%I64d\n",ans);
    }
    return 0;
}
