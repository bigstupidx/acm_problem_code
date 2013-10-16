#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
int f[110][110];
int n,pre[110];
int Max_Flow(int s,int t)
{
    int ans=0;
    while(1)
    {
        int i,min=1000000000;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);pre[s]=-2;
        while(!Q.empty()&&pre[t]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=0;j<=n+1;j++)
                if(pre[j]==-1&&f[i][j]>0)
                {
                    pre[j]=i;
                    if(min>f[i][j])min=f[i][j];
                    Q.push(j);
                }
        }
        if(pre[t]==-1)return ans;
        for(i=t;pre[i]!=-2;i=pre[i])
        {
            f[pre[i]][i]-=min;
            f[i][pre[i]]+=min;
        }
        ans+=min;
    }
}
int main()
{
    int np,nc,m;
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
        int u,v,z;
        char ch;
        memset(f,0,sizeof(f));
        while(m--)
        {
            cin>>ch>>u>>ch>>v>>ch>>z;
            f[u][v]=z;
        }
        while(np--)
        {
            cin>>ch>>u>>ch>>z;
            f[n][u]=z;
        }
        while(nc--)
        {
            cin>>ch>>u>>ch>>z;
            f[u][n+1]=z;
        }
        printf("%d\n",Max_Flow(n,n+1));
    }
    return 0;
}
