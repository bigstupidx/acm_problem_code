#include<cstdio>
#include<cstring>
struct edge{
    int to,d,next;
}e[1000];
int head[30],dis[30],que[2][40],need[30],count[30],mark[30],flag[30];
const int inf = 1000000000;
void Add_Edge(int x,int y,int va,int &top)
{
    e[++top].to=y;
    e[top].d=va;
    e[top].next=head[x];    head[x]=top;
}
void Build(int mid)
{
    int top=-1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=24;i++){
        Add_Edge(i-1,i,0,top);
        Add_Edge(i,i-1,-count[i],top);
        int j=(i-1+8)%24+1;//wrong了，开始写为j=(i+8)%24+1; 
        if(j>i)Add_Edge(i,j,need[j],top);
        else Add_Edge(i,j,need[j]-mid,top);
    }
    Add_Edge(0,24,mid,top);
}
bool Bellman_Ford(int sum)
{   
    // 用邻接表 vert 存储 n 表示点数 
    int s,last = 0, top, cnt = 0;
    for( int i = 1;i <= 24; i ++ ) dis[i] = -inf;
    memset( mark, 0, sizeof( mark ) );
    dis[0] = 0;
    que[0][0]=1;    que[0][1]=0;
    bool change = true;
    while (change)
    {
        cnt++;
        if ( cnt > 24 ) return false;
        change = top = 0;
        for ( int i = 1;i <= que[last][0]; i ++ )
        {
            s = que[last][i];
            for ( int j=head[s];j!=-1;j=e[j].next )
            {
                if( dis[s] + e[j].d > dis[e[j].to] )
                {
                    change = true;
                    dis[e[j].to] = dis[s] + e[j].d;
                    if ( mark[e[j].to] != cnt )
                    {
                        mark[e[j].to] = cnt;
                        que[1-last][++top] = e[j].to;
                    }
                }
            }
        }
        last = 1-last;
        que[last][0] = top;
    }
    return 1;
}

int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--)
    {
        int n,tem;
        for(int i=1;i<=24;i++)
            scanf("%d",&need[i]);
        scanf("%d",&n);
        memset(count,0,sizeof(count));
        for(int i=0;i<n;i++){
            scanf("%d",&tem);
            count[tem+1]++;
        }
        int l=0,r=n,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
          //  printf("try mid %d\n",mid);
            Build(mid);
            if(Bellman_Ford(mid))
                r=mid-1;
            else
                l=mid+1;
           // for(int i=0;i<=24;i++)
           //     printf("%d ",dis[i]);
           // puts("");
        }
        if(l==n+1)puts("No Solution");
        else printf("%d\n",l);
    }
    return 0;
}
