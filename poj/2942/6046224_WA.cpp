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

vector<int>bina_con[1002];
void Add_Edge(int x,int y)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int k,int k_father,int depth)
{
    color[k]=1;
    dep[k]=anc[k]=depth;
    int tot=0;
    S[top++]=k;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(color[i]==1&&i!=k_father)
            anc[k]=anc[k]>dep[i]?dep[i]:anc[k];
        else if(color[i]==0)
        {
            tot++;
            DFS(i,k,depth+1);
            anc[k]=anc[k]>anc[i]?anc[i]:anc[k];
            if(anc[i]>=dep[k])
            {
                bina_con[idd].push_back(k);
                do{
                    bina_con[idd].push_back(S[top-1]);
                }while(S[--top]!=i);
                idd++;
            }
        }
    }
    color[k]=2;
}
bool COLOR(int s)
{
    for(edge *p=vert[s];p;p=p->next)
    {
        if(hash[p->to]==0)continue;
        if(color[p->to]==-1)
        {
            color[p->to]=color[s]^1;
            if(!COLOR(p->to))return false;
        }
        else if(color[p->to]==color[s])
            return false;
    }
    return true;
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
        memset(color,0,sizeof(color));
        for(int i=1;i<=n;i++)
            if(!color[i]){
                top=0;
                DFS(i,0,1);
            }
        /*for(int i=0;i<idd;i++)
        {
            for(int j=0;j<bina_con[i].size();j++)
                printf("%d ",bina_con[i][j]);
            puts("");
        }*/
        int cnt=0;
        memset(visit,0,sizeof(visit));
        for(int i=0;i<idd;i++)
        {
            memset(color,-1,sizeof(color));
            memset(hash,0,sizeof(hash));
            color[bina_con[i][0]]=0;
            for(int j=0;j<bina_con[i].size();j++)
                hash[bina_con[i][j]]=1;
            if(!COLOR(bina_con[i][0])){
                for(int j=0;j<bina_con[i].size();j++)
                    if(!visit[bina_con[i][j]]){
                        cnt++;
                        visit[bina_con[i][j]]=1;
                    }
            }
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}
