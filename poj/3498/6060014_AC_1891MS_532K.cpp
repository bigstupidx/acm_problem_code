#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct edge{
    int to,c,f,next;
}e[4000010];
struct node{int x,y;}nod[120];
int n,head[300],L[300],p[300][2],kk[120],va[120];
const int inf = 1000000000;
vector<int>ans;
double Distance(int i,int j)
{
    double ax=nod[i].x-nod[j].x;
    double by=nod[i].y-nod[j].y;
    return sqrt(ax*ax+by*by);
}
void add_edge(int x,int y,int c,int &top)
{
   // printf("%d->%d %d\n",x,y,c);
    e[++top].to=y;  e[top].c=c;
    e[top].f=0;     e[top].next=head[x];    head[x]=top;
    
    e[++top].to=x;  e[top].c=0;
    e[top].f=0;     e[top].next=head[y];  head[y]=top;
}
int max_flow(int s,int t)
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
            //printf("%d\n",flow);
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
                //printf("mini %d\n",mini);
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
    int nca;
    scanf("%d",&nca);
    while(nca--)
    {
        double R;
        int top=-1,sum=0;
        scanf("%d%lf",&n,&R);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d%d",&nod[i].x,&nod[i].y,va+i,kk+i);
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++){
            if(va[i])
                add_edge(0,2*i-1,va[i],top);
            sum+=va[i];
            add_edge(2*i-1,2*i,kk[i],top);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++){
                if(R>=Distance(i,j)){
                    //printf("%d %d\n",i,j);
                    add_edge(2*i,2*j-1,inf,top);
                    add_edge(2*j,2*i-1,inf,top);
                }
            }
        }
        ans.clear();
        for(int i=1;i<=n;i++){
            for(int j=0;j<top;j++)e[j].f=0;
            if(max_flow(0,2*i-1)==sum)
                ans.push_back(i);
        }
        if(ans.size()==0)puts("-1");
        else{
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)
                printf("%d ",ans[i]-1);
            puts("");
        }
    }
    return 0;
}
