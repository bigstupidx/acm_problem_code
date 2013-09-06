#include <cstdio>
#include <cstring>
int n,arrey[120];
int main()
{
    while(scanf("%d",&n),n)
    {
        int cnt=0,tem;
        for(int i=1;i<=n;i++)
            scanf("%d",arrey+i);
        bool flag=true;
        for(int i=2;i<=n;i++)
            if(arrey[i]!=arrey[1]){flag=false;break;}
        while(!flag)
        {
            int i;
            for(i=2;i<=n;i++)
                if(arrey[i]!=arrey[1])break;
            if(i==n+1){flag=true;break;}
            cnt++;
            tem=arrey[n]=arrey[n]/2;
            for(i=n;i>1;i--)
            {
                arrey[i-1]/=2;
                arrey[i]+=arrey[i-1];
            }
            arrey[1]+=tem;
            for(i=1;i<=n;i++)
                if(arrey[i]/2)arrey[i]+=1;
        }
        printf("%d %d\n",cnt-1,arrey[1]-1);
    }
    return 0;
}
