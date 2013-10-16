#include <cstdio>
#include <cstring>
int n,m,dis[333][333],arr[333];
const int inf = 1000000000;
double ans[333];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=inf;
        while(m--)
        {
            int mm;
            scanf("%d",&mm);
            for(int i=0;i<mm;i++)scanf("%d",arr+i);
            for(int i=0;i<mm;i++)
                for(int j=i+1;j<mm;j++)
                    dis[arr[i]][arr[j]]=dis[arr[j]][arr[i]]=1;
        }
        for(int i=1;i<=n;i++)dis[i][i]=0;
        for(int w=1;w<=n;w++)
            for(int u=1;u<=n;u++)
                //if(dis[u][w]<inf)
                    for(int v=1;v<=n;v++)
                        if(dis[u][v]>dis[u][w]+dis[w][v])
                            dis[u][v]=dis[u][w]+dis[w][v];
        //for(int i=1;i<=n;i++)
        //{
        //    for(int j=1;j<=n;j++)
        //        printf("%d ",dis[i][j]);
        //    puts("");
        //}
        double mini=inf;
        for(int i=1;i<=n;i++)
        {
            ans[i]=0;
            for(int j=1;j<=n;j++)
                ans[i]+=dis[i][j];
            ans[i]/=n-1;
            if(ans[i]<mini)mini=ans[i];
        }
        //for(int i=1;i<=n;i++)
        //    printf("%lf ",ans[i]);
        printf("%.0lf\n",mini*100);
    }
    return 0;
}
