#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct edge{
    int to,c,f,next;
}e[100010];
int L[220],p[220][2],head[220];
int n,m,dis[220][220],va[220],wi[220],sum1,sum2;
const int inf = 1000000000;
bool map[220][220];
void Add_Edge( int x, int y, int va, int &top )
{	  //添加 x->y 流量上限为 va 的边 
    //printf("%d -> %d %d\n",x,y,va);
    e[++top].to = y;		e[top].c = va;	e[top].f = 0;
    e[top].next = head[x];	head[x] = top;
    
    e[++top].to = x;		e[top].c = 0;		e[top].f = 0;
    e[top].next = head[y];	head[y] = top;
}
int Max_Flow( int s,int t )
{
    int flow=0;
    while( 1 )
    {
        queue<int>Q;
        memset ( L, -1 ,sizeof( L ) );
        Q.push(s);		L[s]=0;
        while( !Q.empty() )
        {
            int i=Q.front();Q.pop();
            for( int j = head[i]; j!=-1; j = e[j].next )
            {
                if( L[ e[j].to ] == -1 && e[j].c > e[j].f )
                {
                    L[ e[j].to ] = L[i] + 1;
                    Q.push(e[j].to);
                }
            }
        }
        if( L[t] == - 1 ){
           // printf("flow %d \n",flow);
            return flow;
        }
        int top = 0;
        p[0][0] = s;		p[0][1] = head[s];
        while( top >= 0 )
        {
            if( p[top][0] != t )
            {
                while( p[top][1] >= 0 )
                {
                    if( L[ p[top][0] ] < L[ e[ p[top][1] ].to]&& 
                        e[ p[top][1] ].c > e[ p[top][1] ].f )
                    {
                        p[top+1][0]=e[ p[top][1] ].to;
                        p[top+1][1]=head[ p[top+1][0] ];
                        top++;     break;
                    }
                    p[top][1]=e[ p[top][1] ].next;
                }
                if( p[top][1] < 0 )
                {
                    top -- ;
                    if(top < 0)break;
                    p[top][1]=e[ p[top][1] ].next;
                }
            }
            else
            {
                int mini = inf;
                int k=top - 1;
                for(int i = 0; i < top; i ++ )
                {
                    if(mini > e[p[i][1]].c - e[p[i][1]].f)
                    {
                        mini = e[ p[i][1] ].c - e[ p[i][1] ].f;
                        k=i;
                    }
                }
                flow += mini;
                for(int i = top-1;i>=0;i--)
                {
                    e[ p[i][1] ].f += mini;
                    e[ p[i][1]^1 ].f = - e[p[i][1]].f;
                }
                top = k;
                p[top][1] = e[ p[top][1] ].next;
            }
        }
    }
}

void Build_G(int mid)
{
    int top=-1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        if(va[i]>0)Add_Edge(0,i,va[i],top);
        if(wi[i]>0)Add_Edge(i,n+1,wi[i],top);
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(dis[i][j]!=inf&&dis[i][j]<=mid){
                Add_Edge(i,j,inf,top);
                Add_Edge(j,i,inf,top);
        }
}

int main()
{
    while(scanf("%d",&n),n)
    {
        sum1=0; sum2=0;
        for(int i=1;i<=n;i++){
            scanf("%d",va+i);
            sum1+=va[i];
        }
        for(int i=1;i<=n;i++){
            scanf("%d",wi+i);
            sum2+=wi[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                dis[i][j]=inf;
            dis[i][i]=0;
        }
        int x,y,d,maxi=-1;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&d);
            if(maxi<d)maxi=d;
            if(dis[x][y]>d)
                dis[x][y]=dis[y][x]=d;
        }
        if(sum1>sum2)
        {
            puts("No Solution");
            continue;
        }
        int l=0,r=maxi,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
           // printf("try %d \n",mid);
            Build_G(mid);
            if(Max_Flow(0,n+1)==sum1)
                r=mid-1;
            else l=mid+1;
        }
        if(l == maxi + 1)puts("No Solution");
        else printf("%d\n",l);
    }
    return 0;
}
