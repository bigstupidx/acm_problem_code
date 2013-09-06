#include <cstdio>
#include <cstring>
bool solve(int n)
{
    int tem=n,sum=0,ans;
    while(tem)
    {
        sum+=tem%10;
        tem/=10;
    }
    //printf("%d ",sum);
    tem=n;ans=0;
    while(tem)
    {
        ans+=tem%12;
        tem/=12;
    }
    //printf("%d ",ans);
    if(ans!=sum)return false;
    tem=n;ans=0;
    while(tem)
    {
        ans+=tem%16;
        tem/=16;
    }
    //printf("%d\n",ans);
    if(ans!=sum)return false;
    return true;
}
int main()
{
    //int n;
    //while(scanf("%d",&n),n)
    //    solve(n);
    for(int i=1000;i<10000;i++)
    {
        if(solve(i))
        {
            printf("%d\n",i);
            //getchar();
        }
    }
    return 0;
}
