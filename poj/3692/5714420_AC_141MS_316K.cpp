#include<cstdio>
#include<cstring>
int X,Y,map[202][202],flag[202],y[202];
bool Path(int s)
{
    for(int i=1;i<=Y;i++)
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
    for(int i=1;i<=X;i++)
    {
        memset(flag,0,sizeof(flag));
        if(Path(i))ans++;
    }
    return ans;
}
int main()
{
    int ncase=0,m;
    while(scanf("%d%d%d",&X,&Y,&m),X||Y||m)
    {
        for(int i=1;i<=X;i++)
            for(int j=1;j<=Y;j++)
                map[i][j]=1;
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            map[a][b]=0;
        }
        printf("Case %d: %d\n",++ncase,X+Y-Max_Match());
    }
    return 0;
}
