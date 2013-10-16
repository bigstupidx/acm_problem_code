#include <cstdio>
#include <cstring>
char str[20];
int dis[120][120];
const int inf = 1000000000;
int change()
{
    if(str[0]=='x')return inf;
    int len=strlen(str);
    int ans=0;
    for(int i=0;i<len;i++)
    {
        ans*=10;
        ans+=str[i]-'0';
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=inf;
        for(int i=1;i<=n;i++)
            dis[i][i]=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                scanf("%s",str);
                dis[i][j]=dis[j][i]=change();
            }
        }
        for(int w=1;w<=n;w++)
            for(int u=1;u<=n;u++)
                if(dis[u][w]<inf)
                    for(int v=1;v<=n;v++)
                        if(dis[u][v]>dis[u][w]+dis[w][v])
                            dis[u][v]=dis[u][w]+dis[w][v];
        int maxi=-1;
        for(int i=2;i<=n;i++)
            if(maxi<dis[1][i])maxi=dis[1][i];
        printf("%d\n",maxi);
    }
    return 0;
}
