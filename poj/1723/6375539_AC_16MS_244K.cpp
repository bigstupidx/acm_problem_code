#include <cstdio>
#include <algorithm>
using namespace std;
int xx[10010],yy[10010];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&xx[i],&yy[i]);
        sort(xx,xx+n);
        for(int i=0;i<n;i++)
            xx[i]-=i;
        sort(xx,xx+n);
        sort(yy,yy+n);
        __int64 sum=0;
        for(int i=0;i<n/2;i++)
            sum+=yy[n-1-i]-yy[i]+xx[n-1-i]-xx[i];
        printf("%I64d\n",sum);
    }
    return 0;
}
