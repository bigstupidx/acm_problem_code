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
int n,m,par[102];
int Find(int x){
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
int kruskral(int kk,int &nn){
    int ans=0,cnt=1,st=-1,ed=-1;
    memset(par,-1,sizeof(par));
    for(int i=kk;i<m;i++){
        int ii=Find(edg[i].u);
        int jj=Find(edg[i].v);
        if(ii!=jj){
            par[ii]=jj;
            ans+=edg[i].va;
            if(st==-1)st=i;
            if(ed==-1)ed=i;
            if(++cnt==n){
                ed=i;
                break;
            }
        }
    }
    if(cnt!=n)return -1;
    nn=edg[ed].va-edg[st].va;
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&edg[i].u,&edg[i].v,&edg[i].va);
        }
        sort(edg,edg+m);
        int slim,ans=kruskral(0,slim);
        if(ans==-1){
            puts("-1");
            continue;
        }
        for(int i=1;i<m;i++){
            int ss,tem=kruskral(i,ss);
            if(tem==-1)break;
            if(ss<slim)slim=ss;
        }
        printf("%d\n",slim);
    }
    return 0;
}
