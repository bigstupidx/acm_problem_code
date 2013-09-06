#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
bool map[220][220];
int n,m,in[220],ans[220],flag[220];
struct QN {
    int i;
    bool operator<(const QN a)const
    {
        return a.i>i;
    }
};
bool check()
{
    int k=1;
    QN now;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0){
            now.i=i;
            Q.push(now);
        }
    }
    while(!Q.empty())
    {
        now=Q.top();Q.pop();
        int u=now.i;ans[k++]=u;
        for(int i=1;i<=n;i++)
        {
            if(map[u][i])
            {
                in[i]--;
                if(in[i]==0)
                {now.i=i;Q.push(now);}
            }
        }
    }
    return k==n+1;
}
int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--){
        int x,y;
        scanf("%d%d",&n,&m);
        memset(in,0,sizeof(in));
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            in[x]++;map[y][x]=true;
        }
        if(check())
        {
            for(int i=n;i>=1;i--)
                printf("%d ",ans[i]);
            puts("");
        }
        else puts("-1");
    }
    system("pause");
    return 0;
}
