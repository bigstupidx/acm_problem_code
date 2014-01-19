#include<iostream>
#define N 10002
struct nod{
    int to;
    int dis;
    struct nod *next;
}edge[N],*vert[N];
int E[2*N+2],D[2*N+2],R[N];
int min[32][2*N+2],flag[N],visit[N];
int dist[N];
int top,n,par[N],level;
void add_edge(int f,int to,int value)
{
    nod *p=&edge[top];
    p->to=to;
    p->dis=value;
    p->next=vert[f];
    vert[f]=p;
    top++;
}
void dfs(int root)
{
    visit[root]=1;
    E[top]=root;
    if(!flag[root])
    {
        flag[root]=1;
        R[root]=top;
    }
    D[top++]=level;
    for(nod *p=vert[root];p;p=p->next)
    {
        if(!visit[p->to])
        {   
            level++;
            dist[p->to]=dist[root]+p->dis;
            dfs(p->to);
            level--;
            E[top]=root;
            D[top++]=level;
        }
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
            min[k][i]=D[min[k-1][i-fi/2]] < D[min[k-1][i]]
                ? min[k-1][i-fi/2] : min[k-1][i];
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
    return D[min[k][l+fi-1]] < D[min[k][h]] ? min[k][l+fi-1] : min[k][h];
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        top=0;
        for(int i=1;i<=n;i++)
            par[i]=i,vert[i]=NULL;
        for(int i=0;i<m;i++)
        {
            int u,v,dis;
            scanf("%d%d%d %*c",&u,&v,&dis);
            par[v]=u;
            add_edge(u,v,dis);
            add_edge(v,u,dis);
        }
        int root=1;
        while(root!=par[root])root=par[root];//²éÕÒ¸ù½áµã 
        
        top=0;level=0;
        memset(flag,0,sizeof(flag));
        memset(visit,0,sizeof(visit));
        dist[root]=0;
        dfs(root);
        
        n=top;
        make_rmq();
        
        int u,v,k;
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&u,&v);
            int index=rmq_check(R[u],R[v]);
            int ans=dist[u]+dist[v]-2*dist[E[index]];
            printf("%d\n",ans);
        }
    }
}
