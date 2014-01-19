#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct edge{
    int u,v,c,w,r,next;
}e[4000000];
int head[3000],dis[3000],n,v[3000],pre[3000],map[55][55];
const int inf=1000000000;

void Add_Edge(int u,int v,int c,int w,int &top)
{
    e[++top].u=u;   e[top].v=v;     e[top].c=c;
    e[top].w=w;     e[top].r=top+1; e[top].next=head[u];   head[u]=top;

    e[++top].u=v;   e[top].v=u;     e[top].c=0;
    e[top].w=-w;    e[top].r=top-1; e[top].next=head[v];    head[v]=top;
}
bool Spfa(int s)
{
    queue<int>Q;
    for(int i=1;i<=n;i++){v[i]=0;dis[i]=inf;}
    Q.push(s);dis[s]=0;v[s]=1;
    while(!Q.empty())
    {
        int i=Q.front();Q.pop();
        for(int j=head[i];j!=-1;j=e[j].next)
        {
            if(e[j].c>0 && dis[i]+e[j].w<dis[e[j].v])
            {
                dis[e[j].v]=dis[i]+e[j].w;
                pre[e[j].v]=j;
                if(!v[e[j].v])
                {
                    v[e[j].v]=1;
                    Q.push(e[j].v);
                }
            }
        }
        v[i]=0;
    }
    if(dis[n]==inf)return 0;
    return 1;
}
int main()
{
    int r,k;
    while(scanf("%d%d",&r,&k)!=EOF)
    {
        int top=-1;
        n=2*r*r-1;
        memset(head,-1,sizeof(head));
        for(int i=0;i<r;i++)
            for(int j=0;j<r;j++)
                scanf("%d",&map[i][j]);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<r;j++)
            {
                int x=2*(i*r+j);
                Add_Edge(x,x+1,k-1,0,top);
                Add_Edge(x,x+1,1,-map[i][j],top);
                if(i+1<r)
                    Add_Edge(x+1,2*((i+1)*r+j),k,0,top);
                if(j+1<r)
                    Add_Edge(x+1,2*(i*r+j+1),k,0,top);
            }
        }
        int flow=0,ans=0;
        while(flow!=k)
        {
            Spfa(0);
            ans+=-dis[n];
            int i=n,mini=inf;
            while(i!=0)
            {
                if(mini>e[pre[i]].c)mini=e[pre[i]].c;
                i=e[pre[i]].u;
            }
            flow+=mini;
            i=n;
            while(i!=0)
            {
                e[pre[i]].c-=mini;
                e[pre[i]^1].c+=mini;
                i=e[pre[i]].u;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
