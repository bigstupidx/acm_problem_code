#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

struct edge{
    int to;
    edge *next;
}edg[4000010],*vert[1002];

int top,S[1002],idd;
int n,m,anc[1002],dep[1002],color[1002],visit[1002],hash[1002];
bool map[1002][1002];

vector<int>tem;
void Add_Edge(int x,int y)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
bool COLOR(int s)
{
    for(edge *p=vert[s];p;p=p->next)
    {
        if(hash[p->to]==0)continue;
        if(color[p->to]==-1)
        {
            color[p->to]=1-color[s];
            if(!COLOR(p->to))return false;
        }
        else if(color[p->to]==color[s])
            return false;
    }
    return true;
}
void DFS(int k,int k_father,int depth)
{
    dep[k]=anc[k]=depth;
    S[top++]=k;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(dep[i]==-1)
        {
            DFS(i,k,depth+1);
            anc[k]=anc[k]>anc[i]?anc[i]:anc[k];
            if(anc[i]>=dep[k])
            {
                tem.clear();
                memset(hash,0,sizeof(hash));
                tem.push_back(k);hash[k]=1;
                do{
                    tem.push_back(S[top-1]);
                    hash[S[top-1]]=1;
                }while(S[--top]!=i);
                memset(color,-1,sizeof(color));
                // for(int j=0;j<tem.size();j++)
                //    printf("%d ",tem[j]);
                //puts("");
                if(!COLOR(k)){
                    for(int j=0;j<tem.size();j++)
                        visit[tem[j]]=1;
                }
            }
        }
        else if(i!=k_father)
            anc[k]=anc[k]>dep[i]?dep[i]:anc[k];
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),m||n)
    {
        int x,y;
        top=-1,idd=0;
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=map[y][x]=1;
        }
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(map[i][j]==0)
                    Add_Edge(i,j),Add_Edge(j,i);
            }
        }
        memset(dep,-1,sizeof(dep));
        for(int i=1;i<=n;i++)
            if(-1==dep[i]){
                top=0;
                DFS(i,0,1);
            }
        int cnt=n;
        for(int i=1;i<=n;i++)
            if(visit[i])cnt--;
        printf("%d\n",cnt);
    }
    return 0;
}
