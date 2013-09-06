#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct QN{
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
int mark[120],map[120][120],dis[120],n,s,t;
const int inf = 1000000000;
void dijkstra()
{
    QN now;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++){dis[i]=inf;   mark[i]=0;}
    now.u=s;    now.d=0;    dis[s]=0;
    Q.push(now);
    for(int i=1;i<n;i++)
    {
        int k;
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(int i=1;i<=n;i++)
        {
            if(!mark[i]&&map[k][i]<inf&&dis[i]>dis[k]+map[k][i])
            {
                dis[i]=dis[k]+map[k][i];
                now.u=i;
                now.d=dis[i];
                Q.push(now);
            }
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&s,&t)!=EOF)
    {
        int m,x;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=inf;
        for(int i=1;i<=n;i++)map[i][i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&x);
                map[i][x]=j;
            }
        }
        dijkstra();
        int ans=dis[t];
        if(dis[t]==inf)ans=-1;
        //for(int i=1;i<=n;i++)
        //    printf("%d ",dis[i]);
        //puts("");
        printf("%d\n",ans);
    }
    return 0;
}
