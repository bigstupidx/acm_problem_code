
#include<cstdio>
#include<cstring>
#define M 25000010
#define N 5010
struct edge{
    int to;
    edge *next;
}edg[M],*vert[N],r_edg[M],*r_vert[N];
int n,top,id[N],order[N],out[N];
bool v[N];
void Add_Edge(int u,int v)
{
    edge *p=&edg[top];
    p->to=v;
    p->next=vert[u];vert[u]=p;

    p=&r_edg[top++];
    p->to=u;
    p->next=r_vert[v];r_vert[v]=p;
}
void DFS_RG(int s)
{
    v[s]=1;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])DFS_RG(p->to);
    order[top++]=s;
}
void DFS(int s)
{
    v[s]=1;
    id[s]=top;
    for(edge *p=vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
}
int main()
{
    while(scanf("%d",&n),n)
    {
        int m;
        scanf("%d",&m);
        top=0;
        for(int i=1;i<=n;i++)
        {
            vert[i]=NULL;
            r_vert[i]=NULL;
        }
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Add_Edge(x,y);
        }

        memset(v,0,sizeof(v));
        top=1;
        for(int i=1;i<=n;i++)
            if(!v[i])DFS_RG(i);

        memset(v,0,sizeof(v));
        top=1;
        for(int i=n;i>0;i--)
            if(!v[order[i]]){DFS(order[i]);top++;}
        if(top==2)
        {
            for(int i=1;i<=n;i++)
                printf("%d ",i);
            puts("");
            continue;
        }
        memset(out,0,sizeof(out));
        for(int i=1;i<=n;i++)
            for(edge *p=vert[i];p;p=p->next)
                if(id[i]!=id[p->to])out[id[i]]++;

        int ans=0,k;
        for(int i=1;i<top;i++)
            if(out[i]==0){ans++;k=i;}
        if(ans!=1)puts("");
        else{
            for(int i=1;i<=n;i++)
                if(id[i]==k)printf("%d ",i);
            puts("");
        }
    }
    return 0;
}
