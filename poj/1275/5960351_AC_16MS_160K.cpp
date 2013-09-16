#include<cstdio>
#include<cstring>
struct edge{
    int to,d,next;
}e[1000];
int head[30],dis[30],que[40],need[30],count[30],cnt[30],flag[30];
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
        int j=(i-1+8)%24+1;
        if(j>i)Add_Edge(i,j,need[j],top);
        else Add_Edge(i,j,need[j]-mid,top);
    }
    Add_Edge(0,24,mid,top);
}
bool Spfa(int sum)
{
    int front=0,rear=1;
    for(int i=1;i<=24;i++){dis[i]=-inf;flag[i]=0;cnt[i]=0;}
    dis[0]=0;   que[0]=0;   flag[0]=1;  cnt[0]=1;
    while(front!=rear)
    {
        int i=que[front];
        front=(front+1)%30;
        flag[i]=0;
        for(int j=head[i];j!=-1;j=e[j].next)
        {
            if(dis[e[j].to]<dis[i]+e[j].d)
            {
                dis[e[j].to]=dis[i]+e[j].d;
                if(!flag[e[j].to])
                {
                    flag[e[j].to]=1;
                    cnt[e[j].to]++;
                    if(cnt[e[j].to]>24)return false;
                    que[rear]=e[j].to;
                    rear=(rear+1)%30;
                }
            }
        }
    }
    return sum==dis[24];
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
            if(Spfa(mid))
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
