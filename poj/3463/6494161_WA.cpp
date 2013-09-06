#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[20010],*vert[2][1010];
bool mark[1010];
const int inf = 1000000000;
int cnt[2][1010],dis[2][1010],n,m;
struct node{
    int u;
    int d;
    bool operator <(const node &a)const{
        return a.d<d;
    }
};
void add_edge(int x,int y,int va,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[0][x];    vert[0][x]=p;
    
    p=&edg[++top];
    p->to=x;
    p->d=va;
    p->next=vert[1][y];    vert[1][y]=p;
}
void dijkstra(int s,int t,int j){
    node now;
    priority_queue<node>Q;
    for(int i=1;i<=n;i++){dis[j][i]=inf;mark[i]=0;cnt[j][i]=0;}
    now.u=s;    now.d=0;    dis[j][s]=0;    cnt[j][s]=1;
    Q.push(now);
    for(int i=1,k;i<n;i++){
        do{
            if(Q.empty())return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=vert[j][k];p;p=p->next){
            if(!mark[p->to]){
                if(dis[j][p->to]>dis[j][k]+p->d){
                    cnt[j][p->to]=cnt[j][k];
                    dis[j][p->to]=dis[j][k]+p->d;
                    now.u=p->to;
                    now.d=dis[j][p->to];
                    Q.push(now);
                }
                else if(dis[j][p->to]==dis[j][k]+p->d){
                    cnt[j][p->to]+=cnt[j][k];
                }
            }
        }
    }
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        int top=-1,s,t;
        memset(vert,0,sizeof(vert));

        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            add_edge(u,v,va,top);
        }
        scanf("%d%d",&s,&t);

        dijkstra(s,t,0);
        dijkstra(t,s,1);
        /*
        for(int i=1;i<=n;i++)
            printf("%d ",dis[0][i]);
        puts("");

        for(int i=1;i<=n;i++)
            printf("%d ",cnt[0][i]);
        puts("");
        
        for(int i=1;i<=n;i++)
            printf("%d ",dis[1][i]);
        puts("");
        */
        int ans=cnt[0][t],x=dis[0][t];
        for(int i=1;i<=n;i++){
            for(edge *p=vert[0][i];p;p=p->next){
                if(dis[0][i]+p->d==dis[0][p->to]+1&&
                dis[0][p->to]+dis[1][p->to]==x){
                    printf("%d %d\n",i,p->to);
                    ans+=cnt[0][i]*cnt[1][p->to];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
