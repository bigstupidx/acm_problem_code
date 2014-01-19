#include <cstdio>
#include <cstring>
#define MAXN 100010
struct edge{
    int to;
    edge *next;
}e[400010],*vert[MAXN];
int anc[MAXN],dep[MAXN],n,m,edg[200010][2];
int par[MAXN],rank[MAXN],color[MAXN],fa[MAXN],id[MAXN];
int Find(int x){
    if(par[x]==-1)
        return x;
    return par[x]=Find(par[x]);
}
void add_edge(int x,int y,int &top) {
   // printf("%d -> %d\n",x,y);
    edge *p=&e[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int k,int k_father,int depth){
    color[k]=1;
    anc[k]=dep[k]=depth;
    for(edge *p=vert[k];p;p=p->next){
        int u=p->to;
        if(color[u]==1&&u!=k_father)
            anc[k]=anc[k]>dep[u]?dep[u]:anc[k];
        if(color[u]==0){
            DFS(u,k,depth+1);
            anc[k]=anc[k]>anc[u]?anc[u]:anc[k];
            if(anc[u]>dep[k]){
                edg[m][0]=k;
                edg[m++][1]=u;
            }
            else{
                int ii=Find(u);
                int jj=Find(k);
                par[ii]=jj;
            }
        }
    }
    color[k]=2;
}
void dfs(int s,int s_father,int depth)
{
    rank[s]=depth;
    fa[s]=s_father;
    for(edge *p=vert[s];p;p=p->next)
    {
        if(p->to!=s_father)
        {
            dfs(p->to,s,depth+1);
        }
    }
}
void solve(){
    int nid=1,top=-1;
    //puts("");
    memset(id,-1,sizeof(id));
    memset(vert,0,sizeof(vert));
    for(int i=0;i<m;i++){
      //  printf("%d %d\n",edg[i][0],edg[i][1]);
        int ii=Find(edg[i][0]);
        int jj=Find(edg[i][1]);
        if(id[ii]==-1){
            id[ii]=nid++;
        }
        if(id[jj]==-1){
            id[jj]=nid++;
        }
        add_edge(id[ii],id[jj],top);
        add_edge(id[jj],id[ii],top);
    }
    for(int i=1;i<=n;i++)
        id[i]=id[Find(i)];
}
void LCA(int x,int y){
    while(rank[x]>rank[y]){
        if(!color[x])
            m--,color[x]=1;
        x=fa[x];
    }
    while(rank[y]>rank[x]){
        if(!color[y])
            m--,color[y]=1;
        y=fa[y];
    }
    while(rank[x]==rank[y]){
        if(x==y)return ;
        if(!color[x])
            m--,color[x]=1;
        if(!color[y])
            m--,color[y]=1;
        x=fa[x];   y=fa[y];
    }
}
int main()
{
    int nca=0,mm;
    while(scanf("%d%d",&n,&mm),n||mm){
        int top=-1; nca++;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<mm;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add_edge(x,y,top);add_edge(y,x,top);
        }
        memset(par,-1,sizeof(par));
        memset(dep, 0,sizeof(dep));
        memset(color,0,sizeof(color));
        m=0;    DFS(1,0,1);
        solve();
        
        memset(fa,0,sizeof(fa));
        memset(rank,0,sizeof(rank));
        dfs(1,0,1);
        /*
        for(int i=1;i<=n;i++)
            printf("%d ",rank[i]);
        puts("");
        for(int i=1;i<=n;i++)
            printf("%d ",fa[i]);
        puts("");
        */
        printf("Case %d:\n",nca);
        int qq;
        scanf("%d",&qq);
        memset(color,0,sizeof(color));
        while(qq--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            //printf("%d %d\n",id[x],id[y]);
            LCA(id[x],id[y]);
            printf("%d\n",m);
        }
    }
    return 0;
}
