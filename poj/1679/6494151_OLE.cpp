#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge{
    int u,v,va,s;
    bool operator <(const edge &a)const{
        if(a.va==va)
            return a.s>s;
        return a.va>va;
    }
}edg[10010];
int n,m,par[120];
int Find(int x){
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
int kruskra(int &x){
    int ans=0,cnt=1;
    memset(par,-1,sizeof(par));
    for(int i=0;i<n;i++){
        int ii=Find(edg[i].u);
        int jj=Find(edg[i].v);
        if(ii!=jj){
            par[ii]=jj;
            ans+=edg[i].va;
            edg[i].s=1;
            if(++cnt==n)break;
        }
    }
    if((x=cnt)!=n)x=-1;
    return ans;
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v,va;
            edg[i].s=0;
            scanf("%d%d%d",&u,&v,&va);
            edg[i].u=u; edg[i].v=v; edg[i].va=va;
        }
        sort(edg,edg+m);
        for(int i=0;i<m;i++)
            printf("%d %d %d %d\n",edg[i].u,edg[i].v,edg[i].va,edg[i].s);
        int x=0,ans=kruskra(x),flag=1;
        if(x==n){
            sort(edg,edg+m);
            for(int i=0;i<m;i++)
                printf("%d %d %d %d\n",edg[i].u,edg[i].v,edg[i].va,edg[i].s);
            for(int i=1;i<m;i++){
                if(edg[i].va==edg[i-1].va&&edg[i].s!=0){
                    flag=0;break;
                }
            }
        }
        if(flag)
            printf("%d\n",ans);
        else
            puts("Not Unique!");
    }
    return 0;
}
