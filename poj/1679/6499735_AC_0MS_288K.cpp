#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge{
    int u,v,va;
    bool operator <(const edge &a)const{
        return a.va>va;
    }
}edg[10010];
int par[102],n,m,visit[10010],mark[10010];
int Find(int x){
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
int kruskral(){
    int ans=0,cnt=1;
    memset(par,-1,sizeof(par));
    for(int i=0;i<m;i++){
        if(visit[i])continue;
        int ii=Find(edg[i].u);
        int jj=Find(edg[i].v);
        if(ii!=jj){
            par[ii]=jj;
            ans+=edg[i].va;
            visit[i]=1;
            if(++cnt==n)break;
        }
    }
    if(cnt!=n)return -1;
    return ans;
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&edg[i].u,&edg[i].v,&edg[i].va);
        }
        sort(edg,edg+m);
        memset(visit,0,sizeof(visit));
        int ans=kruskral(),flag=0;
        if(ans==-1)puts("Not Unique!");
        else{
            for(int i=0;i<m;i++)
                mark[i]=visit[i];
            for(int i=0;i<m;i++){
                if(!mark[i])continue;
                memset(visit,0,sizeof(visit));
                visit[i]=1;
                int tem=kruskral();
                if(tem!=-1&&tem==ans){
                    flag=1;
                    break;
                }
            }
        }
        if(flag)puts("Not Unique!");
        else printf("%d\n",ans);
    }
    return 0;
}
