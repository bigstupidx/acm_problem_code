#include<cstdio>
#include<cstring>
struct edge{
    int to;
    edge *next;
}edg[2000010],*vert[1010];
int n,top,ans[1010],anc[1010],deep[1010],color[1010];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&edg[top++];
    p->to=x;
    p->next=vert[y];vert[y]=p;
}
void DFS(int k,int k_father,int depth)
{
    color[k]=1;
    anc[k]=deep[k]=depth;
    int tot=0;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(i!=k_father&&color[i]==1)
            anc[k]=anc[k]>deep[i]?deep[i]:anc[k];
        if(color[i]==0)
        {
            tot++;
            DFS(i,k,depth+1);
            anc[k]=anc[k]>anc[i]?anc[i]:anc[k];
            if(k_father==0&&tot>1||k_father!=0&&anc[i]>=deep[k])
                ans[k]++;
        }
    }
    color[k]=2;
}
int main()
{
    int ncase=0;
    while(1){
        int x,y;
        top=0;n=1;ncase++;
        memset(vert,0,sizeof(vert));
        while(scanf("%d",&x),x)
        {
            scanf("%d",&y);
            if(x>n)n=x;
            if(y>n)n=y;
            Add_Edge(x,y);
        }
        if(n==1)break;
        memset(color,0,sizeof(color));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
            if(!color[i])DFS(i,0,1);
        /*
         * for(int i=1;i<=n;i++)
            printf("%d ",anc[i]);
        puts("");
         * */
        top=0;
        bool flag=0;
        printf("Network #%d\n",ncase);
        for(int i=1;i<=n;i++)
        {
            if(ans[i]){
                flag=true;
                printf("  SPF node %d leaves %d subnets\n",i,ans[i]+1);
            }
        }
        if(!flag)printf("  No SPF nodes\n");
        puts("");
    }
    return 0;
}
