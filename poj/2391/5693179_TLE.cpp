#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int to;
    long long c,f;
    int r,next;
}e[10000000];
long long n,dp[220][220],cow[220],pi[220],Y;
long long bb[200000],L[500],head[500],p[500][500];
const long long inf=1LL <<60;
void Floyd_Short_Path()
{
    int u,v,w;
    for(v=1;v<=n;v++)
        for(u=1;u<=n;u++)
            for(w=1;w<=n;w++)
                if(dp[w][u]>dp[w][v]+dp[v][u])
                    dp[w][u]=dp[v][u]+dp[w][v];
}
long long Dinic(int s,int t)
{
    long long flow=0;
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
                long long min=inf;
                int k=top-1,flag=1;
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
void Add_Edge(int a,int b,long long va,int &top)
{
     e[++top].to=b;	e[top].c=va;	e[top].f=0;
     e[top].r=top+1;	e[top].next=head[a];	head[a]=top;

     e[++top].to=a;	e[top].c=0;	e[top].f=0;
     e[top].r=top-1;	e[top].next=head[b];	head[b]=top;
}
bool solve(long long mid)
{
    int i,j,top=-1;
    memset(head,-1,sizeof(head));

    for(i=1;i<=n;i++)
        Add_Edge(i,i+n,inf,top);

    for(i=1;i<=n;i++){
        Add_Edge(0,i,cow[i],top);
        Add_Edge(i+n,2*n+1,pi[i],top);
    }

    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(dp[i][j]<inf&&dp[i][j]<=mid)
            {
                Add_Edge(i,j+n,inf,top);
                Add_Edge(j,i+n,inf,top);
            }

   return Dinic(0,2*n+1)==Y;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dp[i][j]=inf;
        for(i=1;i<=n;i++)dp[i][i]=0;

        Y=0;
        for(i=1;i<=n;i++){
            scanf("%d%d",cow+i,pi+i);
            Y+=cow[i];
        }
        
        while(m--)
        {
            int d;
            scanf("%d%d%d",&i,&j,&d);
            if(d<dp[i][j])
                dp[i][j]=dp[j][i]=d;
        }
        Floyd_Short_Path();
        int cnt=1;bb[0]=0;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                if(dp[i][j] < inf)
                    bb[cnt++]=dp[i][j];
        sort(bb,bb+cnt);
        int l=0,r=cnt-1,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(solve(bb[mid]))
                r=mid-1;
            else
                l=mid+1;
        }
        if(l==cnt)bb[l]=-1;
        printf("%lld\n",bb[l]);
    }
    return 0;
}
