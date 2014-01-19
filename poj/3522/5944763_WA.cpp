#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge{
    int s,t,d;
    bool operator<(const edge a)const
    {
        return a.d>d;
    }
}edg[10010];
int n,m,par[120],visit[10010],mark[10010];
int Find(int x)
{
    if(par[x]==-1)return x;
    return par[x]=Find(par[x]);
}
int Kruskral(int &flag,int st)
{
    int mini,maxi,cnt=1;
    for(int i=st;i<m;i++)
    {
        int ii=Find(edg[i].s);
        int jj=Find(edg[i].t);
        if(ii!=jj)
        {
            par[ii]=jj;
            if(cnt==1)mini=edg[i].d;
            cnt++;  visit[i]=1;
            if(cnt==n)maxi=edg[i].d;
        }
        if(cnt==n)break;
    }
    if(cnt<n)flag=-1;
    return maxi-mini;
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&edg[i].s,&edg[i].t,&edg[i].d);
        sort(edg,edg+m);
        int flag=1;
        memset(visit, 0, sizeof(visit));
        memset(  par,-1, sizeof(  par));
        int mini=Kruskral(flag,0);
        if(flag==-1){
            puts("-1");
            continue;
        }
        for(int i=0;i<m;i++)mark[i]=visit[i];
        for(int i=0;i<m;i++)
        {
            if(!mark[i])continue;
            flag=1;
            memset(par,-1,sizeof(par));
            memset(visit,0,sizeof(visit));
            int temp=Kruskral(flag,i+1);
            if(flag==-1)break;
            if(temp<mini)mini=temp;
        }
        printf("%d\n",mini);
    }
    return 0;
}
