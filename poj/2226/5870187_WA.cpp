#include<cstdio>
#include<cstring>

int n,m,map[55][55],y[55],flag[55];
char str[55][55];

bool Path(int s)
{
    for(int i=0;i<m;i++)
    {
        if(flag[i]==0&&map[s][i])
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
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(str[i][j]=='*')map[i][j]=1;
        printf("%d\n",Max_Match());
    }
    return 0;
}
