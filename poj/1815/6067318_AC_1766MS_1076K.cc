#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;
struct edge{
    int to,c,f,r,next;
}e[20010];
int n,top,map[204][204],head[500],ans[204],p[500][2],L[500];
void Add_Edge(int u,int v,int va)
{
    e[++top].to=v;e[top].c=va;
    e[top].r=top+1;e[top].next=head[u];head[u]=top;

    e[++top].to=u;e[top].c=0;
    e[top].r=top-1;e[top].next=head[v];head[v]=top;
}
int Dinic(int s,int t)
{
    int flow=0;
    for(int i=0;i<=top;i++)e[i].f=0;
    while(1)
    {
        queue<int>Q;
        memset(L,-1,sizeof(L));
        L[s]=0;Q.push(s);
        while(!Q.empty())
        {
            int i=Q.front();Q.pop();
            for(int j=head[i];j!=-1;j=e[j].next)
                if( L[e[j].to]==-1 && e[j].c>e[j].f)
                {
                    L[e[j].to]=L[i]+1;
                    Q.push(e[j].to);
                }
        }
        if(L[t]==-1)return flow;
        int tail=0;
        p[0][0]=s;p[0][1]=head[s];
        while(tail>=0)
        {
            if(p[tail][0]!=t)
            {
                while(p[tail][1]!=-1)
                {
                    if(L[p[tail][0]]<L[e[p[tail][1]].to]&&e[p[tail][1]].c>e[p[tail][1]].f)
                    {
                        p[tail+1][0]=e[p[tail][1]].to;
                        p[tail+1][1]=head[p[tail+1][0]];
                        tail++;
                        break;
                    }
                    p[tail][1]=e[p[tail][1]].next;
                }
                if(p[tail][1]<0)
                {
                    tail--;
                    p[tail][1]=e[p[tail][1]].next;
                }
            }
            else
            {
                int mini=inf,k,flag=1;
                for(int i=0;i<tail;i++){
                    if(mini>e[p[i][1]].c-e[p[i][1]].f){
                        mini=e[p[i][1]].c-e[p[i][1]].f;
                        k=i;
                    }
                }
                flow+=mini;
                for(int i=tail-1;i>=0;i--)
                {
                    e[p[i][1]].f+=mini;
                    e[e[p[i][1]].r].f=-e[p[i][1]].f;
                }
                tail=k;
                p[tail][1]=e[p[tail][1]].next;
            }
        }
    }
}
int main()
{
    int s,t;
    while(scanf("%d%d%d", &n,&s,&t)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%d",map[i]+j);
        }
        if(map[s][t]==1)
        {
            puts("NO ANSWER!");
            continue;
        }
        for(int i=0;i<500;i++)
            head[i]=-1;
        top=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(map[i][j]==0)continue;
                if(i!=s&&i==j)Add_Edge(i,i+n,1);
                else
                {
                    Add_Edge(i+n,j,inf);
                    Add_Edge(j+n,i,inf);
                }
            }
        }
        Add_Edge(s,s+n,inf);
        
        int ret,temp,k=0;
        ret=Dinic(s,t);
        printf("%d\n",ret);
        if(ret==0)continue;
        for(int i=1;i<=n;i++)
        {
            if(i==s||i==t)continue;
            int xx;
            for(xx=head[i];xx!=-1;xx=e[xx].next)
                if(e[xx].to==i+n)break;
            if(e[xx].f==0)continue;
            e[xx].c=0;

            temp=Dinic(s,t);
            //if(temp==inf)continue;
            if(temp!=ret){ret=temp;ans[k++]=i;continue;}
            e[xx].c=1;
        }

        printf("%d",ans[0]);
        for(int i=1;i<k;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
