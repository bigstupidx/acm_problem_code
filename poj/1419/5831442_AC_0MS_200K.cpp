#include<cstdio>
#include<cstring>
int g[102][102],num[102],best,n,m,x[102],path[102];
bool DFS(int *adj,int total,int cnt)
{
    int t[102];
    if(total==0){
        if(cnt>best)
        {
            for(int i=0;i<cnt;i++)path[i]=x[i];
            best=cnt;
            return true;
        }
    }
    for(int i=0;i<total;i++)
    {
        int k=0;
        if(cnt+total-i<=best)return false;
        if(cnt+num[adj[i]]<=best)return false;
        x[cnt]=adj[i];
        for(int j=i+1;j<total;j++)
            if(g[adj[i]][adj[j]])t[k++]=adj[j];
        if(DFS(t,k,cnt+1))return true;
    }
    return false;
}
int Max_Clique()
{
    int adj[102];
    best=0;
    for(int i=n-1;i>=0;i--)
    {
        int k=0;x[0]=i;
        for(int j=i+1;j<n;j++)
            if(g[i][j])adj[k++]=j;
        DFS(adj,k,1);
        num[i]=best;
    }
    return best;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)g[i][j]=1;
        for(int i=0;i<n;i++)g[i][i]=1;
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;    y--;
            g[x][y]=g[y][x]=0;
        }
        printf("%d\n",Max_Clique());
        for(int i=0;i<best;i++)
            printf("%d ",path[i]+1);
        puts("");
    }
    return 0;
}
