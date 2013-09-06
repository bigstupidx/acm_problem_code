#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[10010],*vert[600];
int dis[600],flag[600],n,m,k,cnt[600];
void Add_Edge(int x,int y,int va,int &top)
{
    printf("%d -> %d %d\n",x,y,va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
bool Spfa()
{
    queue<int>Q;
    for(int i=1;i<=n;i++){dis[i]=0;flag[i]=1;Q.push(i);cnt[i]=1;}
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        flag[u]=0;
        for(edge *p=vert[u];p;p=p->next)
        {
            if(dis[p->to]>dis[u]+p->d)
            {
                dis[p->to]=dis[u]+p->d;
                if(!flag[p->to]){
                    flag[p->to]=1;
                    cnt[p->to]++;
                    if(cnt[p->to]>n)return false;
                    Q.push(p->to);
                }   
            }
        }
    }
    return true;
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--)
    {
        int x,y,d,top=-1;
        scanf("%d%d%d",&n,&m,&k);
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&d);
            Add_Edge(x,y,d,top);
            Add_Edge(y,x,d,top);
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d%d%d",&x,&y,&d);
            Add_Edge(x,y,-d,top);
        }
        if(Spfa())puts("NO");
        else puts("YES");
    }
    return 0;
}
