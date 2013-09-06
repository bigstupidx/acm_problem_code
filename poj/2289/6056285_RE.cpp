#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
char str[200];
int n,m,g[1001][501],flag[501],my[501][1001];
bool path(int s,int mid)
{
    for(int i=0;i<m;i++)
    {
        if(!flag[i]&&g[s][i])
        {
            flag[i]=1;
            if(my[i][0]<mid){
                my[i][++my[i][0]]=s;
                return true;
            }
            else{
                for(int j=1;j<=my[i][0];j++)
                {
                    if(path(my[i][j],mid))
                    {
                        my[i][j]=s;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int max_match(int mid)
{
    int ans=0;
    memset(my,-1,sizeof(my));
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
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
        {
            gets(str);
            string st(str);
            istringstream in(st);
            in>>str;
            while(in>>u)g[i][u]=1;
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
