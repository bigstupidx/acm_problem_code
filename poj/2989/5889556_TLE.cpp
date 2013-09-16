#include<cstdio>
#include<cstring>
int g[140][140],num[140],best,n,m,path[140],tot;
bool DFS(int *adj,int total,int cnt)
{
    int t[102];
    if(total==0){
        if(cnt>best)
        {
            best=cnt;
            return true;
        }
    }
    for(int i=0;i<total;i++)
    {
        int k=0;
        if(cnt+total-i<=best)return false;
        if(cnt+num[adj[i]]<=best)return false;
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
        int k=0;
        for(int j=i+1;j<n;j++)
            if(g[i][j])adj[k++]=j;
        DFS(adj,k,1);
        num[i]=best;
    }
    return best;
}
bool DFS2(int *adj,int total,int cnt)
{
    int t[102];
    if(total==0){
        if(cnt==best)
        {
            tot++;
            return true;
        }
    }
    for(int i=0;i<total;i++)
    {
        int k=0;
        if(cnt+total-i<best)return false;
        if(cnt+num[adj[i]]<best)return false;
        for(int j=i+1;j<total;j++)
            if(g[adj[i]][adj[j]])t[k++]=adj[j];
        if(DFS2(t,k,cnt+1))return true;
    }
    return false;
}
void Max_Clique2()
{
    int adj[102];
    for(int i=n-1;i>=0;i--)
    {
        int k=0;
        for(int j=i+1;j<n;j++)
            if(g[i][j])adj[k++]=j;
        DFS2(adj,k,1);
        if(tot>1000)break;
    }
    return ;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(g,0,sizeof(g));
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;    y--;
            g[x][y]=g[y][x]=1;
        }
        //printf("%d\n",Max_Clique());
        Max_Clique();
        tot=0;
        Max_Clique2();
        if(tot>1000)puts("Too many maximal sets of friends.");
        else printf("%d\n",tot);
    }
    return 0;
}
