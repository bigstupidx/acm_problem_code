#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;

struct edge{
    int to,c,f,r,next;
}e[400000];
int va[5005],n,head[5005],L[5005],p[5005][5005],visit[5005];

void Add_Edge(int u,int v,int value,int &top)
{
    e[++top].to=v;  e[top].c=value; e[top].f=0;
    e[top].r=top+1; e[top].next=head[u];    head[u]=top;
    
    e[++top].to=u;  e[top].c=0; e[top].f=0;
    e[top].r=top-1; e[top].next=head[v];    head[v]=top;
}
int Dinic(int s,int t)
{
    int flow=0;
    while(1)
    {
        queue<int>Q;
        memset(L,-1,sizeof(L));
        Q.push(s);L[s]=0;
        while(!Q.empty())
        {
            int i=Q.front();Q.pop();
            for(int j=head[i];j!=-1;j=e[j].next)
            {
                if(L[e[j].to]==-1 && e[j].c > e[j].f)
                {
                    L[e[j].to]=L[i]+1;
                    Q.push(e[j].to);
                }
            }
        }
        if(L[t]==-1)return flow;
        int top=0;
        p[0][0]=s;p[0][1]=head[s];
        while(top>=0)
        {
            if(p[top][0]!=t)
            {
                while(p[top][1]>=0)
                {
                    if(L[p[top][0]]<L[e[p[top][1]].to]&& e[p[top][1]].c > e[p[top][1]].f)
                    {
                        p[top+1][0]=e[p[top][1]].to;
                        p[top+1][1]=head[p[top+1][0]];
                        top++;break;
                    }
                    p[top][1]=e[p[top][1]].next;
                }
                if(p[top][1]<0)
                {
                    top--;
                    if(top<0)break;
		    p[top][1]=e[p[top][1]].next;
                }
            }
            else
            {
                int min=1000000000,k=top-1,flag=1;
                for(int i=0;i<top;i++)
                    if(min > e[p[i][1]].c-e[p[i][1]].f)min = e[p[i][1]].c-e[p[i][1]].f;
                flow+=min;
                for(int i = top-1;i>=0;i--)
                {
                    e[p[i][1]].f+=min;
                    e[e[p[i][1]].r].f=-e[p[i][1]].f;
                    if(flag&&e[p[i][1]].f==e[p[i][1]].c){flag=0;k=i;}
                }
                top=k;
                p[top][1]=e[p[top][1]].next;
            }
        }
    }
}

void DFS(int s)
{
    visit[s]=1;
    n++;
    for(int i=head[s];i!=-1;i=e[i].next)
        if(!visit[e[i].to]&&e[i].c>e[i].f)
            DFS(e[i].to);
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,top=-1,sum=0;
        memset(head,-1,sizeof(head));
        for(i=1;i<=n;i++){
            scanf("%d",va+i);
            if(va[i]>0){
                sum+=va[i];
                Add_Edge(0,i,va[i],top);
            }
            else if(va[i]<0)
                Add_Edge(i,n+1,-va[i],top);
        }
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            Add_Edge(x,y,inf,top);
        }
        printf("%d ",sum-Dinic(0,n+1));
        n=-1;
        memset(visit,0,sizeof(visit));
        DFS(0);
        printf("%d\n",n);
    }
    return 0;
}
