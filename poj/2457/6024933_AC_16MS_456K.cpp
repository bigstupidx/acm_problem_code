#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[200010],*vert[1010];
const int inf = 1000000000;
int dis[1010],mark[1010],n,m,pre[1010];
struct QN {
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
void Add_Edge(int x,int y,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
void Dijkstra()
{
    QN now;
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++){dis[i]=inf;mark[i]=0;pre[i]=-1;}
    now.u=1;    now.d=0;    dis[1]=0;
    Q.push(now);
    for(int k,i=1;i<n;i++)
    {
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=vert[k];p;p=p->next)
        {
            if(!mark[p->to]&&dis[p->to]>dis[k]+p->d)
            {
                pre[p->to]=k;
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
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int top=-1,x,y;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            Add_Edge(x,y,1,top);
        }
        Dijkstra();
        if(dis[n]==inf)puts("-1");
        else{
            printf("%d\n",dis[n]+1);
            vector<int>aa;
            int i=n,top=dis[n]+1;
            do{
                aa.push_back(i);
                i=pre[i];
            }while(pre[i]!=-1);
            aa.push_back(1);
            for(i=top-1;i>=0;i--)
                printf("%d\n",aa[i]);
        }
    }
    return 0;
}
