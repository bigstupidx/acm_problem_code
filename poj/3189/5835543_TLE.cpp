#include<cstdio>
#include<cstring>

int link[22][1010],g[1010][22],n,m,cap[22];
bool v[22];
bool Path(int s)
{
    int i,j;
    for(i=g[s][0];i<=g[s][1];i++)
    {
        int y=g[s][i];
        if(!v[y])
        {
            v[y]=true;
            if(link[y][0]<cap[y]){
                link[y][++link[y][0]]=s;
                return true;
            }
            for(j=1;j<=link[y][0];j++)
            {
                if(Path(link[y][j]))
                {
                    link[y][j]=s;
                    return true;
                }
            }
        }
    }
    return false;
}
int Max_Match()
{
    int ans=0;
    for(int i=1;i<=m;i++)link[i][0]=0;
    for(int i=1;i<=n;i++)
    {
        memset(v,0,sizeof(v));
        if(Path(i))ans++;
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            g[i][0]=2;
            g[i][1]=m+1;
        }
        for(int i=1;i<=n;i++)
            for(int j=2;j<=m+1;j++)
                scanf("%d",&g[i][j]);
        for(int i=1;i<=m;i++)scanf("%d",cap+i);
        int mid;
        for(mid=1;mid<=m+1;mid++)
        {
            int flag=0;
            for(int i=0;i<m-mid+1;i++)
            {
                //printf("try %d %d\n",mid,i);
                for(int j=1;j<=n;j++)
                {
                    g[j][0]=i+2;    g[j][1]=i+mid+1;
                }
                if(Max_Match()==n)
                {
                    flag=1; break;
                }
            }
            if(flag)break;
        }
        printf("%d\n",mid);
    }
    return 0;
}
