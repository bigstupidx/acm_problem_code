#include<cstdio>
#include<cstring>
struct node{
    int u,t,dur;
}nod[202];
int q,m,dis[25][25],y[202];
const int inf = 1000000000;
bool g[202][202],flag[202];
void Floyd_Dis()
{
    for(int w=1;w<=q;w++)
        for(int u=1;u<=q;u++)
            for(int v=1;v<=q;v++)
                if(dis[u][v]<dis[u][w]+dis[w][v])
                    dis[u][v]=dis[u][w]+dis[w][v];
}
bool OK(int i,int j)
{
    if(nod[i].t+nod[i].dur+dis[nod[i].u][nod[j].u]<nod[j].t)
        return true;
    return false;
}
bool Path(int s)
{
    for(int i=1;i<=m;i++)
    {
        if(!flag[i]&&g[s][i])
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
    for(int i=1;i<=m;i++)
    {
        memset(flag,0,sizeof(flag));
        if(Path(i))ans++;
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&q,&m),q||m)
    {
        int tem;
        for(int i=1;i<=q;i++)
        {
            for(int j=1;j<=q;j++)
            {
                scanf("%d",&tem);
                if(tem==-1)dis[i][j]=inf;
                else dis[i][j]=tem;
            }
        }
        Floyd_Dis();
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&nod[i].u,&nod[i].t,&nod[i].dur);
        memset(g,0,sizeof(g));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                if(OK(i,j))g[i][j]=1;
        printf("%d\n",m-Max_Match());
    }
    return 0;
}
