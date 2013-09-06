#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int map[400][400],m,n,k;
const int inf = 1000000000;
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int s,t,va;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                map[i][j]=inf;
            map[i][i]=0;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&s,&t,&va);
            if(map[s][t]>va)map[s][t]=va;
        }
        for(int w=1;w<=n;w++){
            for(int u=1;u<=n;u++){
                if(map[u][w]<inf){
                    for(int v=1;v<=n;v++){
                        if(map[w][v]<inf){
                            int tem=max(map[u][w],map[w][v]);
                            if(map[u][v]==inf)
                                map[u][v]=tem;
                            else
                                map[u][v]=min(map[u][v],tem);
                        }
                    }
                }
            }
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&s,&t);
            if(map[s][t]==inf)puts("-1");
            else printf("%d\n",map[s][t]);
        }
    }
    return 0;
}
