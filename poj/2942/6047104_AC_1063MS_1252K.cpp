#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[4000010],*vert[1002];
vector<int>tem;
int hash[1002];
int n,m,top,anc[1002],dep[1002],visit[1002],S[1002],color[1002];
bool map[1002][1002];
void add_edge(int x,int y)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
bool judge(int s,int cc)
{
    color[s]=cc;
    for(edge *p=vert[s];p;p=p->next)
    {
        if(hash[p->to]==-1)continue;
        if(color[p->to]==-1)
        {
            if(!judge(p->to,cc^1))return false;
        }
        else if(color[p->to]==color[s])
            return false;
    }
    return true;
}
void DFS(int k,int k_father,int depth)
{
    anc[k]=dep[k]=depth;
    S[++top]=k;
    for(edge *p=vert[k];p;p=p->next)
    {
        int v=p->to;
        if(dep[v]==-1)
        {
            DFS(v,k,depth+1);
            anc[k]=anc[k]>anc[v]?anc[v]:anc[k];
            if(anc[v]>=dep[k])
            {
                tem.clear();
                memset(hash,-1,sizeof(hash));
                tem.push_back(k);   hash[k]=1;
                do{
                    int u=S[top];
                    tem.push_back(u);
                    hash[u]=1;
                }while(S[top--]!=v);
               // for(int i=0;i<tem.size();i++)
               //     printf("%d ",tem[i]);
               // puts("");
                memset(color,-1,sizeof(color));
                if(!judge(k,1)){
                    for(int i=0;i<tem.size();i++)
                        visit[tem[i]]=1;
                }
            }
        }
        else if(v!=k_father)
            anc[k]=anc[k]>dep[v]?dep[v]:anc[k];
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y]=map[y][x]=1;
        }
        
        top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(!map[i][j])
                    add_edge(i,j),add_edge(j,i);
        
        memset(dep,-1,sizeof(dep));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)
            if(dep[i]==-1)
                top=-1,DFS(i,0,1);
        int ans=n;
        for(int i=1;i<=n;i++)
            if(visit[i])ans--;
        printf("%d\n",ans);
    }
    return 0;
}
