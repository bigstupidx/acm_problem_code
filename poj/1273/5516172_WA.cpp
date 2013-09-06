#include<stdio.h>
#include<string.h>
#define N 202

int p[N],f[N][N],flag[N];
int n,m,c[N][N],top;
int path(int s)
{
    if(s==n)
        return 100000000;
    for(int i=1;i<=n;i++)
    {
        if(!flag[i] && c[s][i] > f[s][i])
        {
            flag[i]=1;
            int t=path(i);
            if(t)
            {
                p[i]=s;
                if(t>c[s][i]-f[s][i])t=c[s][i]-f[s][i];
                return t;
            }
        }
    }
    return 0;
}
int Max_Flow()
{
    int ans=0,m;
    memset(f,0,sizeof(f));
    p[1]=-1;
    while(1)
    {
        memset(flag,0,sizeof(flag));
        flag[1]=1;
        if(!(m=path(1)))break;
        for(int i=n;p[i]!=-1;i=p[i])
        {
            f[p[i]][i]+=m;
            f[i][p[i]]=-f[p[i]][i];
        }
        ans+=m;
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int ans=0;
        memset(c,0,sizeof(c));
        for(int i=0;i<m;i++)
        {
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            c[u][v]=va;
        }
        printf("%d\n",Max_Flow());    
    }
    return 0;
}
