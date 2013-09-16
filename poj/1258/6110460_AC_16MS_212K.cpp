#include <cstdio>
#include <cstring>
const int inf = 10000000;
int map[120][120],closed[120],n;
int prim()
{
    int ans=0;
    for(int i=0;i<n;i++)closed[i]=map[0][i];
    for(int j=1;j<n;j++)
    {
        int k,mini=inf;
        for(int i=0;i<n;i++)
            if(closed[i]&&mini>closed[i])
                k=i,mini=closed[i];
        ans+=mini;
        closed[k]=0;
        for(int i=0;i<n;i++)
            if(closed[i]&&map[k][i]<closed[i])
                closed[i]=map[k][i];
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&map[i][j]);
        printf("%d\n",prim());
    }
    return 0;
}
