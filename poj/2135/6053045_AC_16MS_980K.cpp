#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct edge{
    int s,t;
    int c,next;
    int wi;
}e[800010];
int n,m,head[1010],flag[1010],pre[1010];
int dis[1010];
const int inf = 1000000000;
void add_edge(int x,int y,int c,int va,int &top)
{
    //printf("%d -> %d %d %I64d\n",x,y,c,va);
    e[++top].s=x;   e[top].t=y;     e[top].c=c;
    e[top].wi=va;   e[top].next=head[x];    head[x]=top;
    
    e[++top].s=y;   e[top].t=x;     e[top].c=0;
    e[top].wi=-va;   e[top].next=head[y];    head[y]=top;   
}
void spfa()
{
    queue<int>Q;
    for(int i=1;i<=n;i++){dis[i]=inf;   flag[i]=0;}
    dis[1]=0;   flag[1]=1;  Q.push(1);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(int j=head[u];j!=-1;j=e[j].next)
        {
            if(e[j].c>0&&dis[e[j].t]>dis[u]+e[j].wi)
            {
                dis[e[j].t]=dis[u]+e[j].wi;
                pre[e[j].t]=j;
                if(!flag[e[j].t])
                {
                    flag[e[j].t]=1;
                    Q.push(e[j].t);
                }
            }
        }
        flag[u]=0;        
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int top=-1;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++)
        {
            int x,y,va;
            scanf("%d%d%d",&x,&y,&va);
            add_edge(x,y,1,va,top);
            add_edge(y,x,1,va,top);
        }
        int cnt=0,ans=0;
        while(cnt<2)
        {
            spfa(); cnt++;
            for(int i=pre[n];;i=pre[e[i].s])
            {
                e[i].c--;
                e[i^1].c++;
                if(e[i].s==1)break;
            }
            ans+=dis[n];
        }
        printf("%d\n",ans);
    }
    return 0;
}
