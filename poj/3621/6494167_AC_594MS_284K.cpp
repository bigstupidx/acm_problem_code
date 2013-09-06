#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[5002],*vert[1010];
double dis[1010];
int cost[1010],n,m,cnt[1010],flag[1010];
const int inf = 1000000000;
inline void add_edge(int x,int y,int va,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
bool bellman_ford(double mid){
    queue<int>Q;
    for(int i=1;i<=n;i++){Q.push(i);dis[i]=0;cnt[i]=1;flag[i]=1;}
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        flag[u]=0;
        for(edge *p=vert[u];p;p=p->next){
            int v=p->to;
            if(dis[v]>dis[u]+mid*(p->d)-cost[u]){
                dis[v]=dis[u]+mid*(p->d)-cost[u];
                if(!flag[v]){
                    if(++cnt[v]>n) return false;
                    flag[v]=1;
                    Q.push(v);
                }
            }
        }
    }
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        int maxi=-1,top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++){
            vert[i]=0;
            scanf("%d",cost+i);
            if(maxi<cost[i])maxi=cost[i];
        }
        for(int i=0;i<m;i++){
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            add_edge(u,v,va,top);
        }
        double lf=0,rt=maxi,mid;
        while(rt-lf>1e-4){
            mid=(lf+rt)/2;
            if(!bellman_ford(mid))
                lf=mid;
            else
                rt=mid;
            //printf("%lf %lf %lf\n",lf,mid,rt);
        }
        printf("%.2lf\n",mid);
    }
    return  0;
}
