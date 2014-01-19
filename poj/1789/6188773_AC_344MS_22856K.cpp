#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge{
    int u,v,d;
    bool operator<(const edge a)const
    {
        return a.d>d;
    }
}edg[4000040];
int n,par[2010];
char str[2010][10];
int Distance(int i,int j)
{
    int ans=0;
    for(int k=0;k<7;k++)
        if(str[i][k]!=str[j][k])
            ans++;
    return ans;
}
int Find(int x)
{
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
int main()
{
    while(scanf("%d",&n),n)
    {
        int k=0;
        for(int i=0;i<n;i++)scanf("%s",str[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                edg[k].u=i;
                edg[k].v=j;
                edg[k++].d=Distance(i,j);
            }
        }
        sort(edg,edg+k);
        int cnt=1,ans=0;
        memset(par,-1,sizeof(par));
        for(int i=0;i<k;i++)
        {
            int ii=Find(edg[i].u);
            int jj=Find(edg[i].v);
            if(ii!=jj)
            {
                cnt++;
                par[ii]=jj;
                ans+=edg[i].d;
                if(cnt==n)break;
            }
        }
        printf("The highest possible quality is 1/%d.\n",ans);
    }
    return 0;
}
