#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge{
    int s,t,va;
    bool operator<(const edge a)const
    {
        return a.va>va;
    }
}edg[10010];
int n,m,par[120],visit[10010],mark[10010];
int Find(int x)
{
    if(par[x]==-1)return x;
    return par[x]=Find(par[x]);
}
int Kruskral(int &flag)
{
    int ans=0,cnt=1;
    for(int i=0;i<m;i++)
    {
        if(visit[i])continue;
        int ii=Find(edg[i].s);
        int jj=Find(edg[i].t);
        if(ii!=jj){
            cnt++;
            ans+=edg[i].va;
            visit[i]=1;
            par[ii]=jj;
        }
    }
    if(cnt<n)flag=-1;
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(par,-1,sizeof(par));
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&edg[i].s,&edg[i].t,&edg[i].va);
        sort(edg,edg+m);
        int flag=1;
        memset(visit,0,sizeof(visit));
        int mini=Kruskral(flag);
        if(flag==-1)
        {
            printf("%d\n",mini);
            continue;
        }
        bool unic=true;
        for(int i=0;i<m;i++)mark[i]=visit[i];
        for(int i=0;i<m;i++)
        {
            if(!mark[i])continue;
            memset(visit,0,sizeof(visit));
            memset(par,-1,sizeof(par));
            flag=1;visit[i]=1;
            int temp=Kruskral(flag);
            if(flag==-1)continue;
            if(temp==mini){unic=false;break;}
        }
        if(!unic)puts("Not Unique!");
        else printf("%d\n",mini);
    }
    //system("pause");
    return 0;
}
