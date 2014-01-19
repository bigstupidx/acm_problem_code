#include <cstdio>
#include <cstring>
struct edge{
    int to;
    edge *next;
}edg[400010],*vert[20010];
int top,n,m,ans[40010];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int s)
{
    edge *p;
    while(p=vert[s])
    {
        ans[top++]=p->to;
        vert[s]=p->next;
        DFS(p->to);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        top=0;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Add_Edge(x,y);Add_Edge(y,x);
        }
        ans[0]=1;    top=1;  DFS(1);
        //printf("top %d\n",top);
        for(int i=0;i<top;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
