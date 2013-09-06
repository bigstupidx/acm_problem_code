#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[20010],*vert[1002],*r_vert[1002];
bool visit[1002];
int n,m,top,order[1002],id[1002],in[1002];
vector<int>front[1002];
void add_edge(int x,int y){
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
    
    p=&edg[++top];
    p->to=x;
    p->next=r_vert[y];  r_vert[y]=p;
}
void DFS(int s){
    visit[s]=1;
    for(edge *p=vert[s];p;p=p->next){
        if(!visit[p->to]){
            DFS(p->to);
        }
    }
    order[top++]=s;
}
void DFS_RG(int s){
    visit[s]=1;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next){
        if(!visit[p->to]){
            DFS_RG(p->to);
        }
    }
}
int DFS2(int s){
    int maxi=0;
    for(int i=0;i<front[s].size();i++){
        int t=front[s][i];
        int tem=DFS2(t);
        if(tem>maxi)maxi=tem;
    }
    return maxi+1;
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        top=-1;
        memset(vert,0,sizeof(vert));
        memset(r_vert,0,sizeof(r_vert));
        
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u--;    v--;
            add_edge(u,v);
        }
        top=1;
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++){
            if(!visit[i])DFS(i);
        }
        top=0;
        memset(visit,0,sizeof(visit));
        for(int i=n;i>0;i--){
            if(!visit[order[i]]){
                DFS_RG(order[i]);
                top++;
            }
        }
        for(int i=0;i<n;i++){
            in[i]=0;
            front[i].clear();
        }
        for(int i=0;i<n;i++){
            int u=id[i];
            for(edge *p=vert[i];p;p=p->next){
                int v=id[p->to];
                if(u!=v){
                    front[u].push_back(v);
                    in[v]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<top;i++){
            if(in[i]==0){
                ans=DFS2(i);
                break;
            }
        }
        if(ans==top)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
