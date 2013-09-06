#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[100010],*vert[50002];
__int64 inf=1,dis[50002];
int n,m,wi[50002],mark[50002];
struct QN{
    int u;
    __int64 d;
    bool operator <(const QN &a)const{
        return a.d<d;
    }
};
void add_edge(int x,int y,int va,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
    
    p=&edg[++top];
    p->to=x;
    p->d=va;
    p->next=vert[y];    vert[y]=p;
}
void dijkstra(){
    QN now;
    priority_queue<QN>Q;
    for(int i=0;i<n;i++){dis[i]=inf;mark[i]=0;}
    now.u=0;    now.d=0;    dis[0]=0;
    Q.push(now);
    for(int k,i=1;i<n;i++){
        do{
            if(Q.empty())return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=vert[k];p;p=p->next){
            if(!mark[p->to]&&dis[p->to]>dis[k]+p->d){
                dis[p->to]=dis[k]+p->d;
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
}
int main()
{
    int nca;
    inf<<=60;
    scanf("%d",&nca);
    while(nca--){
        int top=-1;
        memset(vert,0,sizeof(vert));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",wi+i);
        for(int i=0;i<m;i++){
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            u--;    v--;
            add_edge(u,v,va,top);
        }
        dijkstra();
        int flag=0;
        __int64 ans=0;
        for(int i=0;i<n;i++){
            if(dis[i]==inf){
                flag=1;
                break;
            }
            ans+=dis[i]*wi[i];
        }
        if(flag)
            puts("No Answer");
        else
            printf("%I64d\n",ans);
    }
    return 0;
}
