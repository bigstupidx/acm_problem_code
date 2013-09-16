#include<cstdio>
#include<cstring>
struct edge{
    int to;
    edge *next;
}edg[404000],*vert[100010];
int top,n,tail,color[100010],deep[100010],anc[100010],par[100010];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&edg[top++];
    p->to=x;
    p->next=vert[y];vert[y]=p;
}
int F(int s)
{
    int t=par[s];
    if(t==-1)return s;
    return par[s]=F( t );
}
void DFS(int k,int k_father,int depth)
{
    color[k]=1;
    anc[k]=deep[k]=depth;
    int repeat=0;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(i==k_father)repeat++;
        if((i!=k_father||repeat!=1)&&color[i]==1)
            anc[k]=anc[k]>deep[i]?deep[i]:anc[k];
        if(color[i]==0)
        {
            DFS(i,k,depth+1);
            anc[k]=anc[k]>anc[i]?anc[i]:anc[k];
            if(anc[i]<=deep[k])
            {//union
                int ii=F( i ),kk=F( k );
                par[ii]=kk;
            }
            else
            {
                tail++;
                /*
                brig[tail][0]=k;
                brig[tail++][1]=i;
                 * */
            }
        }
    }
    color[k]=2;
}

int main( )
{
    int m,ncase=0;
    while(scanf("%d%d",&n,&m),n||m)
    {
        int x,y,q;
        memset(vert,0,sizeof(vert));
        top=0;ncase++;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            Add_Edge(x,y);
        }
        scanf("%d",&q);
        printf("Case %d:\n",ncase);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            Add_Edge(x,y);
            memset(color,0,sizeof(color));
            memset(par,-1,sizeof(par));
            tail=0;
            DFS(1,0,1);
            /*
             * for(int i=1;i<=n;i++)
                printf("%d ",anc[i]);
            printf("\n");
            for(int i=1;i<tail;i++)
                printf("%d %d\n",brig[i][0],brig[i][1]);
             * */
            printf("%d\n",tail);
        }
        puts("");
    }
    return 0;
}
