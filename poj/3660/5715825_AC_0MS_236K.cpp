#include<cstdio>
#include<cstring>
struct edge{
    int to;
    edge *next;
}edg[5000],*vert[202],*r_vert[202],r_edg[5000];
int n,top;
bool v[202];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&r_edg[top++];
    p->to=x;
    p->next=r_vert[y];r_vert[y]=p;
}
void DFS(int s)
{
    v[s]=1;
    for(edge *p=vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
}
void RG_DFS(int s)
{
    v[s]=1;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])RG_DFS(p->to);
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ans=0,i;
        for(i=1;i<=n;i++){vert[i]=NULL;r_vert[i]=NULL;}
        top=0;
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Add_Edge(y,x);
        }
        for(i=1;i<=n;i++)
        {
            int count=0;
            memset(v,0,sizeof(v));
            DFS(i);RG_DFS(i);
            for(int j=1;j<=n;j++)
                if(v[j])count++;
            if(count==n)ans++;
            //printf("%d ",i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
