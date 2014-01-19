#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
    int x,y;
}nod[120];

int n,m,map[120][120],cost,tot,v[300],dis[300];
const int inf=1000000000,M=200000;
int e_n[M], e_t[M], e_u[M];//e_u记录流量
int e_c[M], e_p[M], e_x[M];

void Add_Edge(int s,int t,int f,int c,int kk)
{
    tot++;
    //printf("%d -> %d %d %d\n",s,t,f,c);
    e_n[tot]=e_n[s];  e_n[s]=tot;    e_t[tot]=t;
    e_u[tot]=f;       e_c[tot]=c;    e_p[tot]=tot+kk;
}
int Flow_Add(int now,int mini)
{
    int i,d;
    if(now==n+m+1)
    {
        cost+=mini*dis[0];
        return mini;
    }
    v[now]=true;
    for(i=e_x[now] ; i!=-1 ; i=e_n[i])
    {
        if(e_u[i]>0&&!v[e_t[i]]&&dis[e_t[i]]+e_c[i]==dis[now])
        {
            d=Flow_Add(e_t[i],min(mini,e_u[i]));
            if(d>0)
            {
                e_u[i] -= d;
                e_u[e_p[i]] += d;
                e_x[now] = i;
                return d;
            }
        }
    }
    e_x[now]=i;
    return 0;
}
bool Re_Label()
{
    int i,d=inf;
    for(i=0;i<=n+m+1;i++)
    {
        if(v[i])
        {
            for(int j=e_n[i]; j!=-1; j=e_n[j])
            {
                if(!v[e_t[j]]&&e_u[j]&&(e_c[j]-dis[i]+dis[e_t[j]])<d)
                    d=e_c[j]-dis[i]+dis[e_t[j]];
            }
        }
    }
    if(d==inf)return false;
    for(i=0;i<=n+m+1;i++)
        if(v[i])
        {
            v[i]=false;
            dis[i]+=d;
        }
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,tem;
        tot=m+n+1;
        for(i=0;i<=m+n+1;i++)e_n[i]=-1;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&nod[i].x,&nod[i].y,&tem);
            Add_Edge(0,i,tem,0, 1);
            Add_Edge(i,0,0 ,0,-1);
        }
        for(i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d%d",&x,&y,&tem);
            Add_Edge(i+n,m+n+1,tem,0,1);
            Add_Edge(n+m+1,i+n,0,0,-1);
            for(int j=1;j<=n;j++)
            {
                int tim;
                tim=abs(x-nod[j].x)+abs(y-nod[j].y);
                map[j][i]=tim+1;
                Add_Edge(j,i+n,inf,tim+1,1);
                Add_Edge(i+n,j,0,-1-tim,-1);
            }
        }
        tem=0;
        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                tem+=x*map[i][j];
                //printf("%d ",map[i][j]);
            }
        }
        while(1)
        {
            for(i=0;i<=n+m+1;i++)
                e_x[i]=e_n[i];
            do{
                memset(v,0,sizeof(v));
            }while(Flow_Add(0,inf)>0);
            
            if(!Re_Label())break;
        }
        //printf("%d\n",cost);
        memset(map,0,sizeof(map));
        if(cost<tem){
            puts("SUBOPTIMAL");
            for(i=n+1;i<=n+m;i++)
                for(int j=e_n[i]; j!=-1;j=e_n[j])
                    if(e_t[j]<n+1&&e_t[j]>0)
                        map[e_t[j]][i-n]=e_u[j];
            for(i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                    printf("%d ",map[i][j]);
                puts("");
            }
        }
        else
            puts("OPTIMAL");
    }
    return 0;
}
