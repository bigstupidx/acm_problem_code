#include<iostream>
#define N 10002
struct nod{
    int to;
    struct nod *next;
}edge[N],*vert[N];
int E[2*N+2],D[2*N+2];
int min[32][2*N+2],R[N],flag[N];
int top,n,par[N],level;
void add_edge(int f,int to)
{
    nod *p=&edge[top];
    p->to=to;
    p->next=vert[f];
    vert[f]=p;
    top++;
}
void dfs(int root)
{
    E[top]=root;
    if(!flag[root])R[root]=top;
    D[top++]=level;
    for(nod *p=vert[root];p;p=p->next)
    {
        level++;
        dfs(p->to);
        level--;
        E[top]=root;
        D[top++]=level;
    }
}
void make_rmq()
{
    int fi=1,k=0;
    for(int i=0;i<n;i++)
        min[0][i]=i;
    while(fi*2<=n){
        fi*=2;k++;
        for(int i=fi-1;i<n;i++)
            min[k][i]=D[min[k-1][i-fi/2]]<D[min[k-1][i]]
                ?min[k-1][i-fi/2]:min[k-1][i];
        }
}
int rmq_check(int l,int h)
{
    if(l>h)
    {
        int temp;
        temp=l;l=h;h=temp;
    }
    int fi=1,ll=h-l+1,k=0;
    while(fi*2<=ll){fi*=2;k++;}
    return D[min[k][l+fi-1]]<D[min[k][h]]?min[k][l+fi-1]:min[k][h];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        top=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            par[i]=i,vert[i]=NULL;
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            par[v]=u;
            add_edge(u,v);
        }
        int root=1;
        while(root!=par[root])root=par[root];
        top=0;level=0;
        memset(flag,0,sizeof(flag));
        dfs(root);
        n=top;
        make_rmq();
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",E[rmq_check(R[u],R[v])]);
    }
}
