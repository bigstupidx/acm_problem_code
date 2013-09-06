#include<stdio.h>
#include<string.h>
int map[302][100];
int y[100],flag[100],n;

int path(int s)
{
    for(int i=1;i<100;i++)
    {
        if(map[s][i]&&!flag[i])
        {
            flag[i]=1;
            if(y[i]==0||path(y[i]))
            {
                y[i]=s;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch()
{
    int ans=0;
    memset(y,0,sizeof(y));
    for(int i=1;i <= n;i ++)
    {
        memset(flag,0,sizeof(flag));
        if(path(i)) ans++;
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            for(int j=0;j<t;j++)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                map[i][(x-1)*12+y]=1;
            }
        }
        printf("%d\n",MaxMatch());
    }
    return 0;
}
