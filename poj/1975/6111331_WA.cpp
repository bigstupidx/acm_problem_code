#include <cstdio>
#include <cstring>
bool map[100][100],n,m;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            map[u][v]=true;
        }
        for(int w=1;w<=n;w++)
            for(int u=1;u<=n;u++)
                if(map[u][w])
                    for(int v=1;v<=n;v++)
                        if(map[w][v])
                            map[u][v]=true;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int n1=0,n2=0;
            for(int j=1;j<=n;j++){
                if(map[i][j])n1++;
                if(map[j][i])n2++;
            }
            if(n1>=(n+1)/2||n2>=(n+1)/2)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
