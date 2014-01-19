#include <cstdio>
#include <cstring>
struct edge{
    int to;
    edge *next;
}edg[400010],*vert[10010];
int top,n,m,ans[20010];
void Add_Edge(int x,int y)
{
    //printf("%d->%d\n",x,y);
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int s)
{
    edge *p;
    while(p=vert[s])
    {
        vert[s]=p->next;
        DFS(p->to);
    }
    ans[top++]=s;
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
            Add_Edge(x,y);
            Add_Edge(y,x);
        }
        top=0;  DFS(1);
        //printf("top %d\n",top);
        for(int i=0;i<top;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
