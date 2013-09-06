#include<stdio.h>
#include<string.h>
int n,p;
int map[102][302];
int flag[302],y[302];
int path(int s)
{
    for(int i=1;i<=p;i++)
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
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(path(i))ans++;
    }
    if(ans==n)return 1;
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&p);
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
        {
            int tt;
            scanf("%d",&tt);
            while(tt--)
            {
                int u;
                scanf("%d",&u);
                map[i][u]=1;
            }
        }
        if(MaxMatch())
             printf("YES\n");
        else printf("NO\n");
    }
    //system("pause");
    return 0;
}
