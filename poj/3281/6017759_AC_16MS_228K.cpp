#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct node{
    int to,c,f;//c表示流量上限 
    int next;
} e[100010];
int head[502],L[502],p[502][2],n,f,d;
const int inf=1000000000;   

void Add_Edge( int x, int y, int va, int &top )
{	  //添加 x->y 流量上限为 va 的边 
    e[++top].to = y;		e[top].c = va;	e[top].f = 0;
    e[top].next = head[x];	head[x] = top;
    
    e[++top].to = x;		e[top].c = 0;		e[top].f = 0;
    e[top].next = head[y];	head[y] = top;
}
int Dinic( int s,int t )
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
        if( L[t] == - 1 )return flow;
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

int main()
{
    while(scanf("%d%d%d",&n,&f,&d)!=EOF)
    {
        int m1,m2,x,top=-1;
        int s=0,t=2*n+f+d+1;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&m1,&m2);
            for(int j=1;j<=m1;j++)
            {
                scanf("%d",&x);
                Add_Edge(x,2*i+f-1,1,top);
            }
            for(int j=1;j<=m2;j++)
            {
                scanf("%d",&x);
                Add_Edge(2*i+f,x+f+2*n,1,top);
            }
        }
        for(int i=1;i<=n;i++)Add_Edge(2*i-1+f,2*i+f,1,top);
        for(int i=1;i<=f;i++)Add_Edge(0,i,1,top);
        for(int i=1;i<=d;i++)Add_Edge(i+2*n+f,t,1,top);
        printf("%d\n",Dinic(s,t));
    }
    return 0;
}
