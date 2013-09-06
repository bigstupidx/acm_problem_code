#include<iostream>
#include<string.h>
#define N 202

int p[N],f[N][N],fb[N][N],flag[N];
int n,m,c[N][N],min,top;
int path(int s)
{
    if(flag[s])return 0;
    flag[s]=1;
    if(s==n)
        return 1;
    for(int i=1;i<=n;i++)
    {
        if(flag[i])continue;
        if(c[s][i]>f[s][i])
        {
            int tem=min;
            p[top++]=i;
            if(min>c[s][i]-f[s][i])min=c[s][i]-f[s][i];
            if(path(i))return 1;
            top--;
            min=tem;
        }
        else if(fb[s][i]>0)
        {
            int tem=min;
            p[top++]=i;
            if(min>fb[s][i])min=fb[s][i];
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
    memset(fb,0,sizeof(fb));
    p[0]=1;
    while(1)
    {
        min=100000000;
        top=1;
        memset(flag,0,sizeof(flag));
        if(!path(1))break;
        ans+=min;
        for(int i=1;i<top;i++)
        {
            f[p[i-1]][p[i]]+=min;
            fb[p[i]][p[i-1]]+=min;
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

