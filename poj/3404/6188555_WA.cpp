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
        if(n==1)
        {
            printf("%d\n",tim[0]);
            continue;
        }
        sort(tim,tim+n);
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
            ans+=tim[d]+t1+t2;///插！！！！！！！！！tim[c]; 
        else
            ans+=t2;
        printf("%d\n",ans);
    }
    return 0;
}
