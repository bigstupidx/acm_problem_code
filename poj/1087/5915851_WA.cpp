#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;
int m,n,g[500][500],y[500],flag[500],map1[500][500];
char str[102][25];
bool Path(int s)
{
    for(int i=0;i<m;i++)
    {
        if(!flag[i]&&map1[s][i])
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
    while(scanf("%d",&m)!=EOF)
    {
        int k=m,tt,id=0;
        map<string,int>mp;
        map<string,int>::iterator p;
        memset(g,0,sizeof(g));
        for(int i=0;i<m;i++)
            scanf("%s",str[i]);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int j,u;
            char aa[25],bb[25];
            scanf("%s%s",aa,bb);
            p=mp.find(aa);
            if(p==mp.end())
            {
                mp[aa]=id;
                u=id++;
            }
            else u=p->second;
            for(j=0;j<k;j++)
                if(strcmp(str[j],bb)==0)
                {   g[u][n+j]=1;    break;  }
            if(j==k){strcpy(str[k],bb);g[u][n+k]=1;k++;}
        }
        scanf("%d",&tt);
        for(int i=0;i<tt;i++)
        {
            int j,u,v;
            char aa[25],bb[25];
            scanf("%s%s",aa,bb);
            for(j=0;j<k;j++){
                if(strcmp(str[j],aa)==0)
                    u=j+n;
                else if(strcmp(str[j],bb)==0)
                    v=j+n;
            }
            g[u][v]=1;
        }
        k=k+n;
        for(int w=0;w<k;w++)
            for(int u=0;u<k;u++)
                for(int v=0;v<k;v++)
                    if(!g[u][v]&&(g[u][w]&&g[w][v]))
                        g[u][v]=1;
        memset(map1,0,sizeof(map1));
        for(int i=0;i<id;i++)
            for(int j=n;j<k;j++)
                map1[i][j-n]=g[i][j];
        n=id;
        printf("%d\n",n-Max_Match());
    }
    return 0;
}
