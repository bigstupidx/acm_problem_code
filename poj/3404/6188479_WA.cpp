#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,tim[55];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",tim+i);
        sort(tim,tim+n);
        if(n==1)
        {
            printf("%d\n",tim[0]);
            continue;
        }
        if(n==0)
        {
            puts("0");
            continue;
        }
        int ans=0;
        int a=0,b=1,c=n-2,d=n-1;
        int t1=tim[a],t2=tim[b];
        while(b<c)
        {
            int t3=tim[c],t4=tim[d];
            if(2*t2<t1+t3)
                ans+=2*t2+t1+t4;
            else
                ans+=t4+t1+t3+t1;
            c-=2;d-=2;
        }
        if(c==b+1)
            ans+=tim[c]+t1+t2;
        else
            ans+=t2;
        printf("%d\n",ans);
    }
    return 0;
}
