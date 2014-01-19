#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
struct QN {
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
int n,m,dis[120],mark[120],gra[120][120],edg[1010][4];
const int inf =1000000000;
void Dijkstra(int s)
{
    QN now;
    priority_queue<QN>Q;
    for(int i=1;i<n;i++){dis[i]=inf;    mark[i]=0;}
    now.u=s;    now.d=0;    dis[s]=0;
    Q.push(now);
    for(int k,i=1;i<n;i++)
    {
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(int i=1;i<n;i++)
        {
            if(!mark[i]&&gra[k][i]!=-1&&dis[i]>dis[k]+gra[k][i])
            {
                dis[i]=dis[k]+gra[k][i];
                now.u=i;
                now.d=dis[i];
                Q.push(now);
            }
        }
    }
}
int main()
{
    int tt;
    scanf("%d",&tt);
    for(int ii=1;ii<=tt;ii++)
    {
        int k=0,u,v,st,tim;
        char aa[40],bb[40];
        scanf("%d",&m);
        n=1;
        map<string,int>mp;
        map<string,int>::iterator p;
        memset(gra,-1,sizeof(gra));
        for(int i=0;i<m;i++)
        {
            scanf("%s%s%d%d",aa,bb,&st,&tim);
            if(st>24)st%=24;
            if(st>6&&st<18)continue;
            if(st<=6&&st+tim>6)continue;
            if(st>=18&&st+tim>30)continue;
            p=mp.find(aa);
            if(p==mp.end())
            {
                mp[aa]=n;
                u=n++;
            }
            else u=p->second;
            p=mp.find(bb);
            if(p==mp.end())
            {
                mp[bb]=n;
                v=n++;
            }
            else v=p->second;
            gra[u][v]=0;
            edg[k][0]=u;edg[k][1]=v;
            edg[k][2]=st;edg[k++][3]=st+tim;
        }
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(edg[i][1]==edg[j][0])
                {
                    if(edg[i][3]<edg[j][2]&&edg[j][2]<7)
                        gra[edg[i][1]][edg[j][0]]=0;
                    else if(edg[i][3]<edg[j][2]&&edg[i][3]>7)
                        gra[edg[i][1]][edg[j][0]]=0;
                    else if(edg[j][2]<7&&edg[i][3]>7)
                        gra[edg[i][1]][edg[j][0]]=0;
                    else
                        gra[edg[i][1]][edg[j][0]]=1;
                }
            }
        }
        scanf("%s%s",aa,bb);
        printf("Test Case %d.\n",ii);
        p=mp.find(aa);
        if(p==mp.end())
        {
            puts("There is no route Vladimir can take.");
            continue;
        }
        else u=p->second;
        
        p=mp.find(bb);
        if(p==mp.end())
        {
            puts("There is no route Vladimir can take.");
            continue;
        }
        else v=p->second;
        Dijkstra(u);
        if(dis[v]==inf)puts("There is no route Vladimir can take.");
        else printf("Vladimir needs %d litre(s) of blood.\n",dis[v]);
    }
    return 0;
}
