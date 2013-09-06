#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    int x,y;
    int va;
    bool operator<(const node a)const
    {
        return a.va>va;
    }
}nod[50010];
int par[20002];
int Find(int x){if(par[x]==-1)return x;return par[x]=Find(par[x]);}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--)
    {
        int n,m,r;
        scanf("%d%d%d",&n,&m,&r);
        memset(par,-1,sizeof(par));
        for(int i=0;i<r;i++){
            int x,y,va;
            scanf("%d%d%d",&x,&y,&va);
            va=10000-va;
            nod[i].x=x; nod[i].y=y; nod[i].va=va;
        }
        sort(nod,nod+r);
        __int64 ans=0;
        for(int i=0;i<r;i++)
        {
            int ii=Find(nod[i].x);
            int jj=Find(nod[i].y+n);
            if(ii!=jj){
                par[ii]=jj;
                ans+=nod[i].va;
            }
        }
        for(int i=0;i<n+m;i++)
            if(par[i]==-1)ans+=10000;
        printf("%I64d\n",ans);
    }
    return 0;
}
