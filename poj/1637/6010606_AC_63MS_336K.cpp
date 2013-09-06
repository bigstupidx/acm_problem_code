#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
    int to,c,f,next;
}e[1000010];
int head[1200],n,m,id,p[1200][2],L[1200],in[1002],out[1002],un[1002];
const int inf = 1000000000;
void Add_Edge(int x,int y,int va,int &top)
{
    //printf("%d -> %d %d\n",x,y,va);
    e[++top].to=y;  e[top].c=va;
    e[top].f=0;     e[top].next=head[x];    head[x]=top;
    
    e[++top].to=x;  e[top].c=0;
    e[top].f=0;     e[top].next=head[y];    head[y]=top;
}

bool Max_Flow(int s,int t)
{
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
        if( L[t] == - 1 )break;
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
bool solve()
{
    int x,y,d;
    int top=-1;id=n+1;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&d);
        if(d==0){
            un[x]++;un[y]++;
            Add_Edge(id,x,1,top);
            Add_Edge(id,y,1,top);
            Add_Edge(0,id,1,top);
            id++;
        }
        else{
            out[x]++;in[y]++;
        }
    }    
    for(int i=1;i<=n;i++)
    {
        int sum=in[i]+out[i]+un[i];
        if(sum%2==1)return false;
        if(in[i]>sum/2)return false;
        if(sum/2-in[i])
            Add_Edge(i,id,sum/2-in[i],top);
    }
    Max_Flow(0,id);
    for(int i=1;i<=n;i++)
        for(int j=head[i];j!=-1;j=e[j].next)
            if(e[j].to==id)
            {
                if(e[j].c!=e[j].f)return false;
                break;
            }
    return true;
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        scanf("%d%d",&n,&m);
        memset(in,0,sizeof(in));
        memset(un,0,sizeof(un));
        memset(out,0,sizeof(out));
        memset(head,-1,sizeof(head));
        if(solve())puts("possible");
        else puts("impossible");
    }
    system("pause");
    return 0;
}
