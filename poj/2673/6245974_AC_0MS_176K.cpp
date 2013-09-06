#include <cstdio>
#include <cstring>
int main()
{
    __int64 t,v,ans;
    while(scanf("%I64d%I64d",&t,&v)!=EOF)
    {
        int m,mini=100000000;
        scanf("%d",&m); ans=0;
        while(m--)
        {
            int tem,si,di;
            scanf("%d%d",&di,&si);
            //if(si==0)continue;
            tem=(int)(di*1.0/si);
            if(tem*si==di)tem--;
            if(tem<mini)mini=tem;
        }
        if(mini>t)
            ans=v*t;
        else if(mini==0)
            ans=0;
        else{
            ans+=v*mini;
            ans+=v*((t-mini)/2);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
