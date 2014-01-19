#include<stdio.h>
#include<string.h>
#define _cls(x) memset(x,0,sizeof(x))
int map[210][210];
int graph[210][210];
int ans[210];
int in[210],out[210];
void floyd(int n)
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (graph[i][k] && graph[k][j] && i!=j)
                        graph[i][j]=1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        _cls(graph),_cls(map),_cls(in),_cls(out);
        for (int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if (map[u][v]==0)
            {
                graph[u][v]=map[u][v]=1;
                in[v]++,out[u]++;
            }
        }
        floyd(n);
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                if (!graph[i][j] && !graph[j][i])
                {
                    map[i][j]=1;
                    in[j]++,out[i]++;
                    for (int k=1;k<=n;k++)
                    {
                        if (graph[k][i]) graph[k][j]=1;
                        if (graph[j][k]) graph[i][k]=1;
                    }
                }
        _cls(ans);
        bool can=true;
        for (int i=1;i<=n;i++)
        {
            int now=-1;
            for (int j=1;j<=n;j++)
                if (in[j]==0)
                {
                    now=j;
                    break;
                }
            if (now<0) 
            {
                can=false;
                break;
            }
            for (int j=1;j<=n;j++)
                if (map[now][j])
                    in[j]--;
            in[now]=-1;
            ans[now]=i;
        }
        if (can)
        {
            printf("%d",ans[1]);
            for (int i=2;i<=n;i++)
                printf(" %d",ans[i]);
            puts("");
        }
        else
            puts("-1");
    }
}