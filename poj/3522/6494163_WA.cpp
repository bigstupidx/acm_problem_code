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
int n,m,par[120];
int Find(int x){
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
int kruskral(int st,int &x){
    int si,ei,flag=1;
    memset(par,-1,sizeof(par));
    for(int i=st;i<m;i++){
        int ii=Find(edg[i].u);
        int jj=Find(edg[i].v);
        if(ii!=jj){
            par[ii]=jj;
            if(flag){
                flag=0;
                si=i;
            }
            if(++x==n){
                ei=i;
                break;
            }
        }
    }
    if(x!=n)return 0;
    return edg[ei].va-edg[si].va;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&edg[i].u,&edg[i].v,&edg[i].va);
        }
        sort(edg,edg+m);
        int x=1,mini=kruskral(0,x);
        if(x!=n)puts("-1");
        else{
            for(int i=1;i<m;i++){
                x=1;
                int tem=kruskral(i,x);
                if(x!=n)break;
                if(tem<mini)mini=tem;
            }
            printf("%d\n",mini);
        }
    }
    return 0;
}
