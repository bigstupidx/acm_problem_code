#include <cstdio>
#include <cstring>
#define MAXN 30010
int par[MAXN],n,m,rank[MAXN];
int Find(int x)
{
    if(par[x]==x)
        return x;
    return par[x]=Find(par[x]);
}

int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        //memset(par,-1,sizeof(par));
        for(int i=0;i<n;i++)par[i]=i;
        for(int i=0;i<m;i++)
        {
            int k,u,v;
            scanf("%d",&k);
            if(k==0)continue;
            scanf("%d",&u);
            int ii=Find(u);
            for(int j=1;j<k;j++)
            {
                scanf("%d",&v);
                int jj=Find(v);
                par[jj]=ii;
            }
        }
        int cnt=1,ii=Find(0);
        for(int i=1;i<n;i++)
            if(Find(i)==ii)cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
