#include <cstdio>
#include <stack>
#include <cstring>
#define MAXN 2002
#define MAXM 1000002
using namespace std;
struct edge{
    int to;
    int id;
    edge *next;
}edg[2*MAXM],*vert[MAXN];
int n,m,visit[MAXN],mark[MAXN],que[MAXM],flag[MAXM],e[MAXM][2],cnt1,cnt2;
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
            que[cnt1++]=p->id;
            DFS(p->to);
        }
    }
}
void DFS2(int s){
    mark[s]=1;
    for(edge *p=vert[s];p;p=p->next){
        if(!mark[p->to]&&!flag[p->id]){
            flag[p->id]=2;
            cnt2++;
            DFS2(p->to);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        int top=-1,id=0;
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++){
            int mm,v;
            scanf("%d",&mm);
            for(int j=0;j<mm;j++){
                scanf("%d",&v);
                add_edge(i,v,id,top);
                e[id][0]=i;
                e[id][1]=v;
                id++;
            }
        }
        memset(mark,0,sizeof(mark));
        memset(visit,0,sizeof(visit));
        cnt1=1; cnt2=1; DFS(1); DFS2(1);
        if(cnt1!=n)puts("NONE");
        else{
            int tem=1;
            while(cnt2<n){
                int u,v,i,cnt=0;
                for(i=tem;i<cnt1;i++){
                    if(flag[que[i]]==1&&mark[e[que[i]][0]]&&!mark[e[que[i]][1]]){
                        flag[que[i]]=2;
                        v=e[que[i]][1];
                        break;
                    }
                }
                DFS2(v);
                cnt1=i;
                stack<int>S;
                memset(visit,0,sizeof(visit));
                for(int j=i+1;j<cnt1;j++)
                    flag[que[i]]=0;
                for(int j=1;j<i;j++){
                    u=e[que[i]][0];
                    v=e[que[i]][1];
                    if(!visit[u]){
                        S.push(u);
                        visit[u]=1;
                    }
                    if(!visit[v]){
                        S.push(v);
                        visit[v]=1;
                    }
                }
                while(!S.empty()){
                    u=S.top();S.pop();
                    for(edge *p=vert[u];p;p=p->next){
                        if(!visit[p->to]&&flag[p->id]){
                            flag[p->id]=1;
                            que[cnt1++]=p->id;
                            S.push(p->to);
                        }
                    }
                }
                if(cnt1!=n){
                    cnt2--;break;
                }
                tem=i;
            }
            if(cnt2<n)puts("NONE");
            else{
                puts("YES");
                for(int i=0;i<m;i++){
                    if(flag[i]==1)
                        printf("%d ",i+1);
                }
                puts("");
                for(int i=0;i<m;i++){
                    if(flag[i]==2)
                        printf("%d ",i+1);
                }
                puts("");
            }
        }
        puts("");
    }
    return 0;
}
