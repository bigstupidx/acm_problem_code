#include <cstdio>
#include <cstring>
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        double mini=1000000000;
        for(int i=0;i<n;i++)
        {
            int v,tt;
            scanf("%d%d",&v,&tt);
            if(tt<0)continue;
            double ed=tt+3.6*4500/(1.0*v);
            if(ed<mini)mini=ed;
        }
        int ans=mini;
        if(mini-ans>1e-6)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
