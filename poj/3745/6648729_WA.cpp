#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int id;
    edge *next;
}edg[1000010],*vert[2002];
int n,m,cnt,flag[1000010],visit[2002];
void add_edge(int x,int y,int id,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->id=id;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int s){
    visit[s]=1;
    for(edge *p=vert[s];p;p=p->next){
        if(!visit[p->to]){
            flag[p->id]=1;
            cnt++;
            DFS(p->to);
        }
    }
}
void DFS2(int s){
    visit[s]=1;
    for(edge *p=vert[s];p;p=p->next){
        if(!visit[p->to]&&flag[p->id]==0){
            flag[p->id]=2;
            cnt++;
            DFS2(p->to);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        int top=-1,id=1,mm=m;
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++){
            scanf("%d",&m);
            for(int j=0;j<m;j++){
                int v;
                scanf("%d",&v);
                add_edge(i,v,id++,top);
            }
        }
        memset(flag,0,sizeof(flag));
        memset(visit,0,sizeof(visit));
        cnt=0;  DFS(1);
        if(cnt!=n-1)puts("NONE");
        else{
            memset(visit,0,sizeof(visit));
            cnt=0;DFS2(1);
            if(cnt!=n-1)puts("NONE");
            else{
                puts("YES");
                vector<int>ans1,ans2;
                for(int i=1;i<=mm;i++)
                    if(flag[i]==1)printf("%d ",i);
                puts("");
                for(int i=1;i<=mm;i++)
                    if(flag[i]==2)printf("%d ",i);
                puts("");
            }
        }
        puts("");
    }
    return 0;
}
