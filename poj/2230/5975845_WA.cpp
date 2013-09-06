#include <cstdio>
#include <cstring>
struct edge{
    int to;
    edge *next;
}edg[200010],*vert[10010];
int top,deg[10010],n,m,ans[100010];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
    /*
    p=&edg[top++];
    p->to=x;
    p->next=vert[y];    vert[y]=p;*/
}
void DFS(int s,int cnt)
{
    edge *p;
    if(cnt==2*m)return ;
    while(p=vert[s])
    {
        vert[s]=p->next;
        DFS(p->to,cnt+1);
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
            Add_Edge(x,y);Add_Edge(y,x);
            deg[x]+=2;  deg[y]+=2;
        }
        top=0;  DFS(1,0);
        //printf("top %d\n",top);
        for(int i=0;i<top;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
