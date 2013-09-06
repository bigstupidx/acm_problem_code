#include<cstdio>
#include<cstring>
int n,m,map[502][502],y[502],flag[502];
bool Path(int s)
{
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0&&map[s][i])
        {
            flag[i]=1;
            if(y[i]==-1||Path(y[i]))
            {
                y[i]=s;
                return true;
            }
        }
    }
    return false;
}
int Max_Match()
{
    int ans=0;
    memset(y,-1,sizeof(y));
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(Path(i))ans++;
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y]=1;
        }
        for(int u=1;u<=n;u++)
            for(int v=1;v<=n;v++)
                for(int w=1;w<=n;w++)
                    map[u][v]+=map[u][w]*map[w][v];
        printf("%d\n",n-Max_Match());
    }
    return 0;
}
