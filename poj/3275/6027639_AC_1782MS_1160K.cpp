#include <cstdio>
#include <cstring>
bool map[1010][1010];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ans=0,x,y;
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=true;
        }
        for(int w=1;w<=n;w++)
            for(int u=1;u<=n;u++)
                if(map[u][w])
                    for(int v=1;v<=n;v++)
                        if(map[w][v])
                            map[u][v]=true;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(!map[i][j]&&!map[j][i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}
