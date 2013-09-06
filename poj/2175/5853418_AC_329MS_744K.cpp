#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct node{
    int x,y;
}nod[120];
int n,m,dis[220],c[220][220],f[220][220],wi[220][220];
const int inf=1000000000;
int uu[220][220],p,pre[220],v[220],cnt[220];

int ABS(int x)
{
    if(x<0)return -x;
    return x;
}
bool Check()
{
    queue<int>Q;
    for(int i=0;i<=n+m+1;i++){Q.push(i);cnt[i]=1;v[i]=1;dis[i]=0;}
    while(!Q.empty())
    {
        int i=Q.front();Q.pop();
        v[i]=0;
        for(int j=0;j<=n+m+1;j++)
        {
            if(c[i][j]>f[i][j] && dis[i]+wi[i][j]<dis[j])
            {
                dis[j]=dis[i]+wi[i][j];
                pre[j]=i;   p=j;

                if(!v[j]){
                    v[j]=1;

                    cnt[j]++;
                    if(cnt[j]>n+m+1)return true;

                    Q.push(j);
                }
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        memset( c,0,sizeof( c));
        memset( f,0,sizeof( f));
        memset(wi,0,sizeof(wi));
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&nod[i].x,&nod[i].y,&c[0][i]);
        for(i=1;i<=m;i++)
        {
            int x,y,va,tem;
            scanf("%d%d%d",&x,&y,&va);
            c[i+n][n+m+1]=va;
            for(int j=1;j<=n;j++)
            {
                c[j][i+n]=inf;
                tem=ABS(x-nod[j].x)+ABS(y-nod[j].y)+1;
                wi[j][i+n]=tem; wi[i+n][j]=-tem;
            }
        }
        //int ans=0,best=0;
        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int va;
                scanf("%d",&va);
                if(!va)continue;
                //ans+=va*wi[i][j+n];
                f[i][0]-=va;    f[n+m+1][j+n]-=va;
                f[0][i]+=va;    f[j+n][m+n+1]+=va;
                f[i][j+n]+=va;  f[j+n][i]-=va;
            }
        }
        if(Check())
        {
            memset(v,0,sizeof(v));
            for(i=p;;i=pre[i])
            {
                if(v[i])break;
                v[i]=1;
            }
            memset(v,0,sizeof(v));
            while(!v[i])
            {
                v[i]=1;
                f[pre[i]][i]+=1;
                f[i][pre[i]]-=1;
                i=pre[i];
            }
            puts("SUBOPTIMAL");
            for(i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++){
          //          best+=f[i][j+n]*wi[i][j+n];
                    printf("%d ",f[i][j+n]);
                }
                puts("");
            }
            //printf("ans :%d  best :%d\n",ans,best);
        }
        else    puts("OPTIMAL");
    }
    return 0;
}
