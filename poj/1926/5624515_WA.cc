#include<cstdio>
#include<cstring>
struct edge{
    int to;
    edge *next;
}edg[20010],*vert[102];
double c[102],ans[102];
int n,top,in[102];
bool v[102],mark[102];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&edg[top++];
    p->to=x;
    p->next=vert[y];vert[y]=p;
}
void DFS(int s)
{
    mark[s]=true;
    v[s]=true;
    for(edge *p=vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,i,x,y;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%lf",c+i);
        memset(in,0,sizeof(in));
        memset(vert,0,sizeof(vert));
        while(m--)
        {
            scanf("%d%d",&x,&y);
            in[x]++;in[y]++;
            Add_Edge(x,y);
        }
        /*
        printf("degree: ");
        for(i=1;i<=n;i++)
            printf("%d ",in[i]);
        puts("");
        */
        memset(mark,0,sizeof(mark));
        for(i=1;i<=n;i++)
        {
            if(mark[i])continue;
            memset(v,0,sizeof(v));
            DFS(i);
            double sum=0;
            int sum_edge=0;
            for(int j=1;j<=n;j++)
                if(v[j]){sum+=c[j];sum_edge+=in[j];}
            for(int j=1;j<=n;j++)
                if(v[j])ans[j]=in[j]*sum/sum_edge;
        }
        for(i=1;i<=n;i++)
            printf("%.3lf\n",ans[i]);
    }
    return 0;
}
