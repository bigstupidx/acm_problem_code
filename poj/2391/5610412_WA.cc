#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const long long inf=1LL <<60;
int cow[202],pi[202],n,Y;
long long dp[202][202],bb[40010];

struct edge{
    int to,c,f,r,next;
}e[40010];
int head[404],p[404][404],top,L[404];

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
        if(L[t]==-1){
            //printf("Flow :%d \n",flow);
            return flow;
        }
        top=0;
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
void Add_Edge(int a,int b,int va)
{
    e[++top].to=b;	e[top].c=va;	e[top].f=0;
    e[top].r=top+1;	e[top].next=head[a];	head[a]=top;

    e[++top].to=a;	e[top].c=0;	e[top].f=0;
    e[top].r=top-1;	e[top].next=head[b];	head[b]=top;
}
bool Exist_Path(int mid)
{
    memset(head,-1,sizeof(head));
    top=-1;
    for(int i=1;i<=n;i++)
    {
        Add_Edge(0,i,pi[i]);
        Add_Edge(i+n,2*n+1,cow[i]);
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(dp[i][j]!=inf&&dp[i][j]<=mid){
                Add_Edge(i,j+n,100000000);
                Add_Edge(j,i+n,100000000);
            }
    return Dinic(0,2*n+1)==Y;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Y=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",cow+i,pi+i);
            Y+=cow[i];
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i==j)dp[i][j]=0;
                else dp[i][j]=inf;
        while(m--)
        {
            int x,y,va;
            scanf("%d%d%d",&x,&y,&va);
            dp[x][y]=dp[y][x]=dp[x][y]<va?dp[x][y]:va;
        }
        for(int w=1;w<=n;w++)
           for(int u=1;u<=n;u++)
               for(int v=1;v<=n;v++)
                   if(dp[u][v]>dp[u][w]+dp[w][v])
                       dp[u][v]=dp[u][w]+dp[w][v];
        top=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(dp[i][j]!=inf)bb[top++]=dp[i][j];

        sort(bb,bb+top);
        
        int tt=top,h=top-1,l=0,mid;
        long long ans=-1;
        while(l<=h)
        {
            mid=(h+l)/2;
            //printf("try mid :%d\n",bb[mid]);
            if(Exist_Path(bb[mid]))
                h=mid-1;
            else
                l=mid+1;
        }
        if(l!=tt)ans=bb[l];
        printf("%lld\n",ans);
    }
    return 0;
}
