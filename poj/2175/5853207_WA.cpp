#include<cstdio>
#include<cstring>
using namespace std;

struct node{
    int x,y;
}nod[120];
int n,m,dis[220],c[220][220],f[220][220],wi[220][220];
const int inf=1000000000;
int uu[220][220],p,pre[220],v[220];

int ABS(int x)
{
    if(x<0)return -x;
    return x;
}
bool Check()
{
    int i,j;
    memset(uu,0,sizeof(uu));
    for(i=0;i<=n+m+1;i++)
    {
        dis[i]=0;
        for(j=0;j<=n+m+1;j++)
            if(c[i][j]>f[i][j])
                uu[i][j]=wi[i][j];
            else uu[i][j]=inf;
    }
    /*
    for(i=0;i<=n+m+1;i++)
    {
        for(j=0;j<=1+n+m;j++)
            printf("%d ",uu[i][j]);
        puts("");
    }
    */
    for(int k=0;k<=n+m+1;k++)
    {
        bool flag=false;
        for(i=0;i<=1+n+m;i++)
            for(j=0;j<=1+n+m;j++)
                if(dis[i]+uu[i][j]<dis[j])
                {
                    dis[j]=dis[i]+uu[i][j];
                    pre[j]=i;   p=j;
                    flag=true;
                }
        if(!flag)return false;
    }
    return true;
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
            int mini=inf;
            memset(v,0,sizeof(v));
            i=p;
            while(!v[i])
            {
                v[i]=1;
                if(mini>c[pre[i]][i]-f[pre[i]][i])
                    mini=c[pre[i]][i]-f[pre[i]][i];
                i=pre[i];
            }
            i=p;
            memset(v,0,sizeof(v));
            while(!v[i])
            {
                v[i]=1;
                f[pre[i]][i]+=mini;
                f[i][pre[i]]-=mini;
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
