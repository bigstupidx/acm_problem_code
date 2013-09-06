#include <cstdio>
#include <cstring>
#define MAXN 100010
struct edge{
    int to;
    edge *next;
}edg[1000010],*vert[MAXN],*r_vert[MAXN];
int order[MAXN],visit[MAXN],top,id[MAXN],n,m,cnt[MAXN];
void add_edge(int x,int y)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
    
    p=&edg[++top];
    p->to=x;
    p->next=r_vert[y];    r_vert[y]=p;
}
void DFS(int s)
{
    visit[s]=1;
    for(edge *p=vert[s];p;p=p->next)
        if(!visit[p->to])DFS(p->to);
    order[top++]=s;
}
void DFS_RG(int s)
{
    visit[s]=1;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!visit[p->to])DFS_RG(p->to);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add_edge(x,y);
        }
        top=1;
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)
            if(!visit[i])DFS(i);
        
        //for(int i=1;i<top;i++)
        //    printf("%d ",order[i]);
        //puts("");
        top=1;
        memset(visit,0,sizeof(visit));
        for(int i=n;i>0;i--)
            if(!visit[order[i]]){DFS_RG(order[i]);top++;}
        
        //for(int i=1;i<=n;i++)
        //    printf("%d ",id[i]);
        //puts("");
        int ans=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)cnt[id[i]]++;
        for(int i=1;i<top;i++)
            if(cnt[i]>1)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
