#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[100000],*vert[1010];
char gra[12][12][12];
int dis[1010],n,mark[1010],N;
const int inf = 1000000000;
struct QN {
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
void add_edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void dijkstra(int s)
{
    QN now;
    priority_queue<QN>Q;
    for(int i=0;i<N;i++){dis[i]=inf;mark[i]=0;}
    dis[s]=0;   now.u=s;    now.d=0;
    Q.push(now);
    for(int k,i=1;i<N;i++)
    {
        do{
            if(Q.size()==0)return;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=vert[k];p;p=p->next)
        {
            if(!mark[p->to]&&dis[p->to]>dis[k]+1)
            {
                dis[p->to]=dis[k]+1;
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
}
int main()
{
    char str[40];
    while(scanf("%s",str)!=EOF)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                scanf("%s",gra[i][j]);
        }
        int top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(gra[i][j][k]=='O'){
                        if(i>0&&gra[i-1][j][k]=='O')
                            add_edge(i*n*n+j*n+k,(i-1)*n*n+j*n+k,top);
                        if(i<n-1&&gra[i+1][j][k]=='O')
                            add_edge(i*n*n+j*n+k,(i+1)*n*n+j*n+k,top);
                        if(j>0&&gra[i][j-1][k]=='O')
                            add_edge(i*n*n+j*n+k,i*n*n+(j-1)*n+k,top);
                        if(j<n-1&&gra[i][j+1][k]=='O')
                            add_edge(i*n*n+j*n+k,i*n*n+(j+1)*n+k,top);
                        if(k>0&&gra[i][j][k-1]=='O')
                            add_edge(i*n*n+j*n+k,i*n*n+j*n+k-1,top);
                        if(k<n-1&&gra[i][j][k+1]=='O')
                            add_edge(i*n*n+j*n+k,i*n*n+j*n+k+1,top);
                    }
                }
            }
        }
        int s,t,x,y,z;
        scanf("%d%d%d",&x,&y,&z);s=z*n*n+y*n+x;
        scanf("%d%d%d",&x,&y,&z);t=z*n*n+y*n+x;
        N=n*n*n;    dijkstra(s);
        if(dis[t]==inf)puts("NO ROUTE");
        else printf("%d %d\n",n,dis[t]);
        scanf("%s",str);
    }
    return 0;
}
