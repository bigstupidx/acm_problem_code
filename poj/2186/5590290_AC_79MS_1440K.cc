#include<cstdio>
#include<cstring>
#define N 10010
#define M 50010
struct node{
    int to;
    node *next;
}nod[M],*vert[N],r_nod[M],*r_vert[N];

int v[N],n,top,order[N],id[N],out[N];
void Add_Edge(int u,int v)
{
    node *p=&nod[top];
    p->to=v;
    p->next=vert[u];vert[u]=p;

    p=&r_nod[top++];
    p->to=u;
    p->next=r_vert[v];r_vert[v]=p;
}
void DFS_RG(int s)
{
    v[s]=1;
    for(node *p=r_vert[s];p;p=p->next)
    {
        if(!v[p->to])DFS_RG(p->to);
    }
    order[top++]=s;
}
void DFS(int s)
{
    v[s]=1;
    id[s]=top;
    for(node *p=vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        top=0;
        for(int i=1;i<=n;i++){
            vert[i]=NULL;
            r_vert[i]=NULL;
        }
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Add_Edge(x,y);
        }
        top=1;
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++)
        {
            if(!v[i])DFS_RG(i);
        }
        
        memset(v,0,sizeof(v));
        memset(id,0,sizeof(id));

        top=1;
        for(int i=n;i>0;i--)
        {
            if(!v[order[i]])
            {
                DFS(order[i]);
                top++;
            }
        }//reverse_travel to mark the groups
        //**//
        memset(out,0,sizeof(out));
        for(int i=1;i<=n;i++)
        {
            for(node *p=vert[i];p;p=p->next)
            {
                if(id[i]!=id[p->to])
                    out[id[i]]++;
            }
        }
        int ans=0,k;
        for(int i=1;i<top;i++)
            if(out[i]==0){ans++;k=i;}
        if(ans!=1)puts("0");
        else{
            ans=0;
            for(int i=1;i<=n;i++)
                if(id[i]==k)ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}
