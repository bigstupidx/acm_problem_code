#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,cost,tot,v[600],dis[600],flow;
const int inf=1000000000,M=3000000;
int e_n[M], e_t[M], e_u[M];//e_u记录流量
int e_c[M], e_p[M], e_x[M];
void Add_Edge(int s,int t,int f,int c,int kk)
{
    tot++;
    //printf("%d->%d %d %d\n",s,t,f,c);
    e_n[tot]=e_n[s];  e_n[s]=tot;    e_t[tot]=t;
    e_u[tot]=f;       e_c[tot]=c;    e_p[tot]=tot+kk;
}
int Flow_Add(int now,int mini)
{
    int i,d;
    if(now==n)
    {
        cost+=mini*dis[n-1];
        flow+=mini;
        return mini;
    }
    v[now]=true;
    for(i=e_x[now] ; i ; i=e_n[i])
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
    for(i=1;i<=n;i++)
    {
        if(v[i])
        {
            for(int j=e_n[i]; j; j=e_n[j])
            {
                if(!v[e_t[j]]&&e_u[j]&&(e_c[j]-dis[i]+dis[e_t[j]])<d)
                    d=e_c[j]-dis[i]+dis[e_t[j]];
            }
        }
    }
    if(d==inf)return false;
    for(i=1;i<=n;i++)
        if(v[i])
        {
            v[i]=false;
            dis[i]+=d;
        }
    return true;
}
int main()
{
    int k;
    while(scanf("%d%d%d",&n,&m,&k),m||n||k)
    {
        int tem,sum=0;
        tot=(m+n)*k+2;
        for(int i=0;i<=tot;i++)
            e_n[i]=0;
        for(int i=0;i<n;i++)
            for(int j=1;j<=k;j++)
            {
                scanf("%d",&tem);
                if(tem==0)continue;
                sum+=tem;
                Add_Edge(m*k+i*k+j,(m+n)*k+2,tem,0,1);
                Add_Edge((m+n)*k+2,m*k+i*k+j,0,0,-1);
            }
        for(int i=0;i<m;i++)
            for(int j=1;j<=k;j++)
            {
                scanf("%d",&tem);
                if(tem==0)continue;
                Add_Edge((m+n)*k+1,i*k+j,tem,0,1);
                Add_Edge(i*k+j,(m+n)*k+1,0,0,-1);
            }
        for(int x=1;x<=k;x++)
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                {
                    scanf("%d",&tem);
                    Add_Edge(j*k+x,m*k+i*k+x,inf,tem,1);
                    Add_Edge(m*k+i*k+x,j*k+x,0,-tem,-1);
                }
        n=(m+n)*k+2;flow=0;cost=0;
        while(1)
        {
            for(int i=1;i<=n;i++)e_x[i]=e_n[i];

            do{
                memset(v,0,sizeof(v));
            }while(Flow_Add(n-1,inf)>0);

            if(!Re_Label())break;
        }
        if(sum==flow)
            printf("%d\n",cost);
        else puts("-1");
    }
    return 0;
}
