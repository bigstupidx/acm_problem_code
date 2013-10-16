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
}edg[402];
char str[2][12];
const int inf = 1000000000;
int n,m,k,flag[22],par[22],pcnt;
int Find(int x){
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
int kruskra(int &x){
    int ans=0,cnt=1,j=0;
    memset(par,-1,sizeof(par));
    for(int i=0;i<m;i++){
        if(edg[i].u==0&&!flag[j++])continue;
        int ii=Find(edg[i].u);
        int jj=Find(edg[i].v);
        if(ii!=jj){
            par[ii]=jj;
            if(edg[i].u==0)x++;
            ans+=edg[i].va;
            if(++cnt==n)break;
        }
    }
    if(cnt!=n)return inf;
    return ans;
}
int main()
{
    while(scanf("%d",&m)!=EOF){
        int id=1;
        pcnt=0;
        map<string,int>mp;
        map<string,int>::iterator p;
        mp["Park"]=0;
        for(int i=0;i<m;i++){
            int u,v,d;
            scanf("%s%s%d",str[0],str[1],&d);
            p=mp.find(str[0]);
            if(p==mp.end()){
                mp[str[0]]=id;
                u=id++;
            }
            else u=p->second;
            p=mp.find(str[1]);
            if(p==mp.end()){
                mp[str[1]]=id;
                v=id++;
            }
            else v=p->second;
            if(u>v){int tem=u;u=v;v=tem;}
            if(u==0)pcnt++;
            edg[i].u=u; edg[i].v=v; edg[i].va=d;
        }
        sort(edg,edg+m);
        scanf("%d",&k);
        n=id;
        for(int i=0;i<pcnt;i++)flag[i]=1;
        int x=0,ans=kruskra(x);
        if(x>k){
            int nn=1,j=0;
            while(j<pcnt){nn*=2;j++;}
            memset(flag,0,sizeof(flag));
            for(int i=0;i<nn;i++){
                int ccnt=0,tem=i;j=0;
                while(tem){flag[j++]=tem%2;tem/=2;}
                tem=kruskra(x);
                if(ans!=-1&&ans>tem)
                    ans=tem;
            }
        }
        printf("Total miles driven: %d\n",ans);
    }
    return 0;
}

