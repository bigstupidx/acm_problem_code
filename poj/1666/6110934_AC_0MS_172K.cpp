#include <cstdio>
#include <cstring>
int n,arrey[10010];
int main()
{
    while(scanf("%d",&n),n)
    {
        int cnt=0,tem;
        for(int i=1;i<=n;i++)
            scanf("%d",arrey+i);
        while(1)
        {
            int i;
            for(i=2;i<=n;i++)
                if(arrey[i]!=arrey[1])break;
            if(i==n+1)break;
            cnt++;
            tem=arrey[1]=arrey[1]/2;
            for(i=1;i<n;i++)
            {
                arrey[i+1]/=2;
                arrey[i]+=arrey[i+1];
            }
            arrey[n]+=tem;
            for(i=1;i<=n;i++)
                if(arrey[i]%2)arrey[i]+=1;
        }
        printf("%d %d\n",cnt,arrey[1]);
    }
    return 0;
}
