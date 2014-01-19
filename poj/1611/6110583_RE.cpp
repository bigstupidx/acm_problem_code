#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int par[30010],n,m,tem[30010];
int Find(int x)
{
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        memset(par,-1,sizeof(par));
        for(int i=0;i<m;i++)
        {
            int k;
            scanf("%d",&k);
            for(int j=0;j<k;j++)scanf("%d",&tem[j]);
            sort(tem,tem+k);
            int ii=Find(tem[0]);
            for(int j=1;j<k;j++)
            {
                int jj=Find(tem[j]);
                par[jj]=ii;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(Find(i)==0)cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
