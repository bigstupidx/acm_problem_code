#include <cstdio>
#include <cstring>
struct edge{
    int to,d;
    edge *next;
}edg[110000],*vert[1010];

int n,dis[1010],flag[1010],que[1010],cnt[1010];
const int inf=1000000000;
void Add_Edge(int x,int y,int va,int &top)
{
    //printf("%d->%d %d\n",x,y,va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
bool Spfa()
{
    int ff=0,rr=1;
    for(int i=1;i<=n;i++){dis[i]=-inf;flag[i]=0;cnt[i]=0;}
    flag[0]=1;dis[0]=0;que[0]=0;cnt[0]=1;
    while(ff!=rr)
    {
        int u=que[ff];
        ff=(ff+1)%(n+2);
        flag[u]=0;
        for(edge *p=vert[u];p;p=p->next)
        {
            if(dis[p->to]<dis[u]+p->d)
            {
                dis[p->to]=dis[u]+p->d;
                if(!flag[p->to])
                {
                    flag[p->to]=1;
                    cnt[p->to]++;
                    if(cnt[p->to]>n+1)return false;
                    que[rr]=p->to;
                    rr=(rr+1)%(n+2);
                }
            }
        }
    }
    return true;    
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        char str[3];
        getchar();
        int x,y,c,top=-1;
        memset(vert,0,sizeof(vert));
        while(m--)
        {
            scanf("%s%d%d",str,&x,&y);getchar();
            if(str[0]=='P')
            {
                scanf("%d",&c);getchar();
                Add_Edge(y,x,c,top);
                Add_Edge(x,y,-c,top);
            }
            else    Add_Edge(y,x,1,top);
        }
        for(int i=1;i<=n;i++)
            Add_Edge(0,i,0,top);
        if(Spfa())puts("Reliable");
        else puts("Unreliable");
    }
    return 0;
}
