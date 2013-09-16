#include <cstdio>
#include <cstring>
struct edge{
    int to,d;
    edge *next;
}edg[10010],*vert[120];
int n,dis[120],que[120],cnt[120],flag[120];
void Add_Edge(int x,int y,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
bool Spfa()
{
    int ff=0,rr=0;
    for(int i=0;i<=n;i++){dis[i]=0;flag[i]=1;cnt[i]=1;que[rr++]=i;}
    while(ff!=rr)
    {
        int i=que[ff];
        ff=(ff+1)%(n+2);
        flag[i]=0;
        for(edge *p=vert[i];p;p=p->next)
        {
            if(dis[p->to]<dis[i]+p->d)
            {
                dis[p->to]=dis[i]+p->d;
                if(!flag[p->to]){
                    flag[p->to]=1;
                    cnt[p->to]++;
                    if(cnt[p->to]>n)return false;
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
    while(scanf("%d",&n),n)
    {
        char str[10];
        int m,top=-1,x,y,limit;
        scanf("%d",&m);
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%s%d",&x,&y,str,&limit);
            if(strcmp(str,"gt")==0)
                Add_Edge(x-1,x+y,limit+1,top);
            else    Add_Edge(x+y,x-1,-(limit-1),top);
        }
        if(Spfa())puts("lamentable kingdom");
        else puts("successful conspiracy");
    }
    return 0;
}
