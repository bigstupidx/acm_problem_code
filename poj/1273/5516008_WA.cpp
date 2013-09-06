#include<iostream>
#include<string.h>
#define N 202

int p[N],f[N][N],flag[N];
int n,m,c[N][N],min,top;
int path(int s)
{
    if(s==n)
        return 1;
    for(int i=1;i<=n;i++)
    {
        if(!flag[i] && c[s][i] > f[s][i])
        {
            int tem=min;
            p[top++]=i;
            flag[i]=1;
            if(min>c[s][i]-f[s][i])min=c[s][i]-f[s][i];
            if(path(i))return 1;
            top--;
            min=tem;
        }
    }
    return 0;
}
int Max_Flow()
{
    int ans=0;
    memset(f,0,sizeof(f));
    p[0]=1;
    while(1)
    {
        min=100000000;
        top=1;
        memset(flag,0,sizeof(flag));
        flag[1]=1;
        if(!path(1))break;
        ans+=min;
        for(int i=1;i<top;i++)
        {
            f[p[i-1]][p[i]]+=min;
            f[p[i]][p[i-1]]=-f[p[i-1]][p[i]];
        }
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
