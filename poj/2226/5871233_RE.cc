#include<cstdio>
#include<cstring>

int a[60][60],b[60][60];
int n,m,map[300][300],y[300],flag[300];
char str[60][60];

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
        int k=0;
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        
        int cnt=0,ret=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='*')
                {
                    a[i][j]=cnt;
                }
                if(str[i][j]=='*'&&str[i][j+1]!='*')cnt++;
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(str[j][i]=='*')
                {
                    b[j][i]=ret;
                }
                if(str[j][i]=='*'&&str[j+1][i]!='*')ret++;
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(str[i][j]=='*'){
                    map[a[i][j]][b[i][j]]=1;
                    //printf("%d %d %d %d\n",i,j,a[i][j],b[i][j]);
                }
        n=cnt;      m=ret;
        printf("%d\n",Max_Match());
    }
    return 0;
}
