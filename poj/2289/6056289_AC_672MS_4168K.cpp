#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
char str[2000];
int n,m,g[1001][501],flag[501],my[501][1001];
bool path(int s,int mid)
{
    for(int i=1;i<=g[s][0];i++)
    {
        int u=g[s][i];
        if(!flag[u])
        {
            flag[u]=1;
            if(my[u][0]<mid){
                my[u][++my[u][0]]=s;
                return true;
            }
            for(int j=1;j<=my[u][0];j++)
            {
                if(path(my[u][j],mid))
                {
                    my[u][j]=s;
                    return true;
                }
            }
        }
    }
    return false;
}
int max_match(int mid)
{
    int ans=0;
    for(int i=0;i<m;i++)my[i][0]=0;
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(path(i,mid))ans++;
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        int u;getchar();
        for(int i=1;i<=n;i++)
        {
            g[i][0]=0;
            gets(str);
            string st(str);
            istringstream in(st);
            in>>str;
            while(in>>u)g[i][++g[i][0]]=u;
        }
        int l=0,r=n,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(max_match(mid)==n)
                r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
