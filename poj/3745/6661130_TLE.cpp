#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int id;
    edge *next;
}edg[1000002],*vert[2002];
int n,m,flag[1000002],cnt1,cnt2,mark[2002],visit[2002],e[1000002][2],que[1000002];
void add_edge(int x,int y,int id,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->id=id;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int s){
    visit[s]=1;
    for(edge *p=vert[s];p;p=p->next){
        if(!visit[p->to]&&flag[p->to]!=2){
            flag[p->id]=1;
            que[cnt1]=p->id;
            cnt1++;
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
void DFS3(int s){
    mark[s]=1;
    for(edge *p=vert[s];p;p=p->next){
        if(!mark[p->to]&&!flag[p->id]){
            flag[p->id]=2;
            cnt2++;
            DFS3(p->to);
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
        memset(visit,0,sizeof(visit));
        cnt1=1;  DFS(1);
        if(cnt1!=n)puts("NONE");
        else{
            memset(mark,0,sizeof(mark));
            cnt2=1;  DFS2(1);
            while(cnt2<n){
                int s;
                for(int i=1;i<cnt1;i++){
                    if(mark[e[que[i]][0]]&&!mark[e[que[i]][1]]){
                        s=e[que[i]][0];break;
                    }
                }
                DFS3(s);
                memset(visit,0,sizeof(visit));
                cnt1=1; DFS(1);
                if(cnt1!=n)break;
            }
            if(cnt2<n)puts("NONE");
            else{
                puts("YES");
                for(int i=0;i<m;i++)
                    if(flag[i]==1)printf("%d ",i+1);
                puts("");
                for(int i=0;i<m;i++)
                    if(flag[i]==2)printf("%d ",i+1);
                puts("");
            }
        }
        puts("");
    }
    return 0;
}
