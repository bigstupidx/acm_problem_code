#include <cstdio>
#include <cstring>
#define MAXN 300010
int par[MAXN],n,m,rank[MAXN];
int Find(int x)
{
    if(par[x]==x)
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
        for(int i=0;i<n;i++){par[i]=i;rank[i]=0;}
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
                if(ii!=jj)unionij(ii,jj);
            }
        }
        for(int i=0;i<n;i++)Find(i);
        int cnt=1;
        for(int i=1;i<n;i++)
            if(par[i]==par[0])cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
