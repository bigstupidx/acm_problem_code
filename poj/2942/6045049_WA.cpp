#include <cstdio>
#include <cstring>
struct edge{
    int to;
    edge *next;
}edg[4000010],*vert[1002];
int n,m,anc[1002],dep[1002],id[1002],color[1002],par[1002];
bool map[1002][1002];
int Find(int x)
{
    if(par[x]==-1)return x;
    return par[x]=Find(par[x]);
}
void Add_Edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int k,int k_father,int depth)
{
    color[k]=1;
    dep[k]=anc[k]=depth;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(color[i]==1&&i!=k_father)
            anc[k]=anc[k]>dep[i]?dep[i]:anc[k];
        else if(color[i]==0)
        {
            DFS(i,k,depth+1);
            anc[k]=anc[k]>anc[i]?anc[i]:anc[k];
            if(anc[i]<=dep[k]){
                int ii=Find(i);
                int jj=Find(k);
                par[ii]=jj;
            }
        }
    }
    color[k]=2;
}
bool COLOR(int s,int &cnt)
{
    cnt++;
    int k=Find(s);
    for(edge *p=vert[s];p;p=p->next)
    {
        if(Find(p->to)!=k)continue;
        if(color[p->to]==-1){
            color[p->to]=(color[s]+1)%2;
            if(!COLOR(p->to,cnt))return false;
        }
        else if(color[p->to]==color[s])return false;
    }
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m),m||n)
    {
        int x,y,top=-1;
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=map[y][x]=1;
        }
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(map[i][j]==0){
                    Add_Edge(i,j,top);
                    Add_Edge(j,i,top);
                }
            }
        }
        memset(color,0,sizeof(color));
        memset( par, -1,sizeof( par));
        for(int i=1;i<=n;i++)
            if(!color[i])DFS(i,0,1);
      //  for(int i=1;i<=n;i++)
      //      printf("%d ",Find(i));
      //  puts("");
        int maxi=-1;
        memset(color,-1,sizeof(color));
        for(int i=1;i<=n;i++)
            if(color[i]==-1){
                int num=0;
                color[i]=0;
                if(COLOR(i,num)||num==1)continue;
                if(maxi<num)maxi=num;
            }
        printf("%d\n",n-maxi);
    }
    return 0;
}
