#include<cstdio>
#include<cstring>
bool g[303][303],flag[303];
char plug[102][30],in[102][30],out[102][30],rec[102][30];
int n,k,m,y[303];
void Floyd()
{
    int t=m+n+k;
    for(int w=0;w<t;w++)
        for(int u=0;u<t;u++)
            if(g[u][w])
                for(int v=0;v<t;v++)
                    if(g[w][v])
                        g[u][v]=true;
}
bool Path(int s)
{
    for(int i=m;i<n+m;i++)
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
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        for(int i=0;i<n;i++)
            scanf("%s",plug[i]);
        
        scanf("%d",&m);getchar();
        for(int i=0;i<m;i++)
            scanf("%*s%s",rec[i]);
        
        scanf("%d",&k);getchar();
        for(int i=0;i<k;i++)
            scanf("%s%s",in[i],out[i]);
        
        memset(g,0,sizeof(g));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!strcmp(rec[i],plug[j]))g[i][j+m]=true;
        for(int i=0;i<m;i++)
            for(int j=0;j<k;j++)
                if(!strcmp(rec[i],in[j]))g[i][j+m+n]=true;
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                if(!strcmp(out[i],in[j]))g[i+m+n][j+n+m]=true;
        for(int i=0;i<k;i++)
            for(int j=0;j<n;j++)
                if(!strcmp(out[i],plug[j]))g[i+m+n][j+m]=true;
        Floyd();
        int ans=0;
        memset(y,-1,sizeof(y));
        for(int i=0;i<m;i++)
        {
            memset(flag,0,sizeof(flag));
            if(!Path(i))ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
