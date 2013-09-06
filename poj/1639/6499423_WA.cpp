#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge{
    int u,v,va;
    bool operator <(const edge &a)const{
        return a.va>va;
    }
}edg[444];
int m,n,par[444],k,flag[22];
int Find(int x){
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
int kruskral(){
    int kk=0,ans=0,cnt=1;
    memset(par,-1,sizeof(par));
    for(int i=0;i<m;i++){
        if(edg[i].u==0&&!flag[kk++])continue;
        int ii=Find(edg[i].u);
        int jj=Find(edg[i].v);
        if(ii!=jj){
            par[ii]=jj;
            ans+=edg[i].va;
            if(++cnt==n)break;
        }
    }
    if(cnt==n)return ans;
    return -1;
}
int main()
{
    while(scanf("%d",&m)!=EOF){
        int id=1,kk=0;
        map<string,int>mp;
        map<string,int>::iterator p;
        mp["Park"]=0;
        for(int i=0;i<m;i++){
            int u,v,va;
            char nam1[12],nam2[12];
            scanf("%s%s%d",nam1,nam2,&va);
            p=mp.find(nam1);
            if(p==mp.end()){
                mp[nam1]=id;
                u=id++;
            }
            else
                u=p->second;
            
            p=mp.find(nam2);
            if(p==mp.end()){
                mp[nam2]=id;
                v=id++;
            }
            else
                v=p->second;
            if(u>v){
                int tem;
                tem=u;u=v;v=tem;
            }
            if(u==0)kk++;
            edg[i].u=u;
            edg[i].v=v;
            edg[i].va=va;
        }
        n=id;
        int jj=kk,fi=1;
        while(jj--)fi*=2;
        
        sort(edg,edg+m);
        for(int i=0;i<kk;i++)flag[i]=1;
        int ans=kruskral();
        scanf("%d",&k);
        for(int i=0;i<fi;i++){
            int nn=i,j=0;
            memset(flag,0,sizeof(flag));
            while(nn){
                flag[j++]=nn%2;
                nn/=2;
            }
            int tem=kruskral();
            if(tem!=-1&&tem<ans)
                ans=tem;
        }
        printf("Total miles driven: %d\n",ans);
    }
    return 0;
}
