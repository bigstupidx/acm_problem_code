#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge{
    int u,v,va;
    bool operator <(const edge &a)const{
        return a.va>va;
    }
}edg[10002];
int n,m,map[102][102],par[102];
int Find(int x){
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
int solve(int nn){
    int ans=0,cnt=nn;
    sort(edg,edg+m);
    for(int i=0;i<m;i++){
        int ii=Find(edg[i].u);
        int jj=Find(edg[i].v);
        if(ii!=jj){
            par[ii]=jj;
            ans+=edg[i].va;
            if(++cnt==n)break;
        }
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        int k=0,cnt=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
                if(i<j){
                    edg[k].u=i;
                    edg[k].v=j;
                    edg[k++].va=map[i][j];
                }
            }
        }
        scanf("%d",&m);
        memset(par,-1,sizeof(par));
        while(m--){
            int u,v;
            scanf("%d%d",&u,&v);
            int ii=Find(u);
            int jj=Find(v);
            if(ii!=jj){
                par[ii]=jj;
                cnt++;
            }
        }
        m=k;
        printf("%d\n",solve(cnt));
    }
    return 0;
}
