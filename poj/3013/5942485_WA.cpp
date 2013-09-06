#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct edge{
    int to;
    __int64 d;
    edge *next;
}edg[100010],*vert[50010];
int n,top,wi[50010],mark[50010];
__int64 dis[50010], inf=1;
struct QN{
    int u;
    __int64 d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
void Add_Edge(int x,int y,__int64 va)
{
    edge *p=&edg[top++];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int s)
{
    mark[s]=1;
    top++;
    for(edge *p=vert[s];p;p=p->next)
        if(!mark[p->to])
            DFS(p->to);
}
void Dijskral(int s)
{
    QN now;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++){dis[i]=inf;   mark[i]=0;}
    now.u=s;    now.d=0;    dis[s]=0;
    Q.push(now);
    for(int i=1;i<n;i++)
    {
        int k;
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=vert[k];p;p=p->next)
        {
            if(!mark[p->to] && dis[p->to] > dis[k] + p->d)
            {
                dis[p->to] = dis[k] + p->d;
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
}
int main()
{
    int t,m;
    inf=inf<<60;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        top=0;
        for(int i=1;i<=n;i++)
        {
            vert[i]=NULL;
            scanf("%d",&wi[i]);
        }
        while(m--)
        {
            int x,y;
            __int64 va;
            scanf("%d%d%I64d",&x,&y,&va);
            Add_Edge(x,y,va);
            Add_Edge(y,x,va);
        }
        top=0;
        memset(mark,0,sizeof(mark));    DFS(1);
        if(top != n)puts("No Answer");
        else{
            __int64 ans=0;
            Dijskral(1);
            //for(int i=1;i<=n;i++)
             //   printf("%d ",dis[i]);
            //puts("");
            for(int i=1;i<=n;i++)
                ans+=dis[i]*wi[i];
            printf("%I64d\n",ans);
        }
    }
    //system("pause");
    return 0;
}
