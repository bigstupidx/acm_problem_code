#include <cstdio>
#include <cstring>
struct edge{
    int to;
    int d;
    edge *next;
}edg[1000010],*vert[10010];
int  dis[10010],flag[10010],que[10010];
const int inf=1000000000;
void Add_Edge(int x,int y,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
int Spfa(int s,int t)
{
    int ff=0,rr=1,n=t-s+1;
    for(int i=s;i<=t;i++){dis[i]=-inf;flag[i]=0;}
    dis[s]=0;   que[0]=s;   flag[s]=1;
    while(ff!=rr)
    {
        int u=que[ff];
        ff=(ff+1)%n;
        flag[u]=0;
        for(edge *p=vert[u];p;p=p->next)
        {
            int v=p->to;
            if(dis[v]<dis[u]+p->d)
            {
                dis[v]=dis[u]+p->d;
                if(!flag[v])
                {
                    flag[v]=1;
                    que[rr]=v;
                    rr=(rr+1)%n;
                }
            }
        }
    }
    return dis[t];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int mini=inf,maxi=-inf,top=-1;
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);b++;
            if(a < mini)mini = a;
            if(b > maxi)maxi = b;
            Add_Edge(a,b,2,top);
        }
        for(int i=mini;i<maxi;i++)
        {
            Add_Edge(i,i+1,0,top);
            Add_Edge(i+1,i,-1,top);
        }
        printf("%d\n",Spfa(mini,maxi));
    }
    return 0;
}
