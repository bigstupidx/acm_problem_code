#include<cstdio>
#include<cstring>
int n,m,y[100];
bool flag[100],g[100][100];
bool Path(int s)
{
    for(int i=0;i<m;i++)
    {
        if(!flag[i]&&g[s][i])
        {
            flag[i]=1;
            if(y[i]==-1||Path(y[i]))
            {
                y[i]=s;
                return true;
            }
        }
    }
    return false;
}
int Max_Match()
{
    int ans=0;
    memset(y,-1,sizeof(y));
    for(int i=0;i<n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(Path(i))ans++;
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        int k;
        scanf("%d%d",&m,&k);
        memset(g,0,sizeof(g));
        while(k--)
        {
            int i,j;
            scanf("%*d%d%d",&i,&j);
            if(i*j!=0)g[i][j]=1;
        }
        printf("%d\n",Max_Match());
    }
    return 0;
}
