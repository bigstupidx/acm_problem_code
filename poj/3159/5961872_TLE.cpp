#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[150010],*vert[30010];
int n,dis[30010],flag[30010];
const int inf = 1000000000;
void Add_Edge(int x,int y,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
int Spfa()
{
    stack<int>S;
    for(int i=1;i<=n;i++){dis[i]=inf;flag[i]=0;}
    dis[1]=0;   S.push(1);  flag[1]=1;
    while(!S.empty())
    {
        int u=S.top();S.pop();
        flag[u]=0;
        for(edge *p=vert[u];p;p=p->next)
        {
            if(dis[p->to]>dis[u]+p->d)
            {
                dis[p->to]=dis[u]+p->d;
                if(!flag[p->to])S.push(p->to);
            }
        }
    }
    return dis[n];
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int top=-1;
        memset(vert,0,sizeof(vert));
        while(m--){
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            Add_Edge(x,y,c,top);
        }
        printf("%d\n",Spfa());
    }
    return 0;
}
