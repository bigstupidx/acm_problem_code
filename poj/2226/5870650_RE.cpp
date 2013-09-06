#include<cstdio>
#include<cstring>

int n,m,map[502][502],y[502],flag[502],aa[502],hash[502];
char str[100][100];

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
        memset(hash,-1,sizeof(hash));
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(str[i][j]=='*')
                {
                    aa[k]=i*m+j;
                    hash[i*m+j]=k++;
                }
        for(int i=0;i<k;i++)
        {
            if(aa[i]%m+1<m&&str[aa[i]/m][aa[i]%m+1]=='*')
                map[hash[aa[i]]][hash[aa[i]+1]]=1;
            if(aa[i]/m+1<n&&str[aa[i]/m+1][aa[i]%m]=='*')
                map[hash[aa[i]]][hash[aa[i]+m]]=1;
        }
        m=n=k;
        printf("%d\n",k-Max_Match());
    }
    return 0;
}
