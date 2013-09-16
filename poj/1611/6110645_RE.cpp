#include <cstdio>
#include <cstring>
int par[100010],n,m;
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
            int k,ff,u;
            scanf("%d",&k);
            if(k==0)continue;
            scanf("%d",&ff);
            int ii=Find(ff);
            for(int j=1;j<k;j++)
            {
                scanf("%d",&u);
                int jj=Find(u);
                par[jj]=ii;
            }
        }
        int cnt=0,ii=Find(0);
        for(int i=0;i<n;i++)
            if(Find(i)==ii)cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
