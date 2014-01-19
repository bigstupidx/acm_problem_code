#include <cstdio>
#include <cstring>
#define MAXN 300010
int par[MAXN],n,m,rank[MAXN];
int Find(int x)
{
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
void unionij(int i,int j)
{
    if(rank[i]<rank[j])
        par[j]=i;
    else{
        par[i]=j;
        if(rank[i]==rank[j])
            rank[i]++;
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        memset(par,-1,sizeof(par));
        memset(rank,0,sizeof(rank));
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
                //if(ii!=jj)unionij(ii,jj);
            }
        }
        int cnt=0,ii=Find(0);
        for(int i=0;i<n;i++)
            if(Find(i)==ii)cnt++;
        //for(int i=0;i<n;i++)
        //    printf("%d ",par[i]);
        printf("%d\n",cnt);
    }
    return 0;
}
