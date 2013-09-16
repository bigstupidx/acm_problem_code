
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge{
    int s,e;
    int d;
    bool operator<(const edge a)const
    {
        return a.d>d;
    }
}edg[10010];
int n,m,mark[10010],par[102],visit[10010];
int F(int s)
{
    int t=par[s];
    if(t==-1)return s;
    par[s]=F(t);
    return par[s];
}
int Kruskral(int &flag)
{
    int count=1,ans=0;
    for(int i=0;i<m;i++)
    {
        if(visit[i])continue;
        int u,v;
        u=edg[i].s; v=edg[i].e;
        int uu=F(u),vv=F(v);
        if(uu==vv)continue;

        par[uu]=vv;
        ans+=edg[i].d;
        visit[i]=1;
        count++;
        if(count==n)break;
    }
    if(count<n)flag=-1;
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&edg[i].s,&edg[i].e,&edg[i].d);
        }
        sort(edg,edg+m);

        memset(visit,0,sizeof(visit));
        memset(par,-1,sizeof(par));

        int ff=1;
        int min=Kruskral(ff);
        if(ff==-1)
        {
            printf("%d\n",min);
            continue;
        }
        for(int i=0;i<m;i++)
            mark[i]=visit[i];
        int flag=0;
        for(int i=0;i<m;i++)
        {
            if(mark[i]==0)continue;

            memset(visit,0,sizeof(visit));
            memset(par,-1,sizeof(par));
            ff=1;visit[i]=1;

            int temp=Kruskral(ff);
            if(ff==-1)continue;
            if(temp==min){flag=1;break;}
        }
        if(flag)printf("Not Unique!\n");
        else printf("%d\n",min);
    }
    return 0;
}
