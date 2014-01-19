#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[1000002],*vert[2002];
int n,m,top,cnt,visit[2002],mark[2002],que[2002],flag[1000002],e[1000002][2];
void add_edge(int x,int y,int id){
    edge *p=&edg[++top];
    p->to=y;
    p->d=id;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int s){
    visit[s]=1;
    for(edge *p=vert[s];p;p=p->next){
        if(!visit[p->to]&&flag[p->d]==0){
            flag[p->d]=1;
            que[top++]=p->d;
            DFS(p->to);
        }
    }
}
void DFS2(int s){
    mark[s]=1;
    for(edge *p=vert[s];p;p=p->next){
        if(!mark[p->to]&&flag[p->d]==0){
            flag[p->d]=2;
            cnt++;
            DFS2(p->to);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        int id=0;top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++){
            int mm,to;
            scanf("%d",&mm);
            for(int j=0;j<mm;j++){
                scanf("%d",&to);
                e[id][0]=i; e[id][1]=to;
                add_edge(i,to,id++);
            }
        }
        memset(flag ,0,sizeof(flag));
        memset(visit,0,sizeof(visit));
        top=0;      DFS(1);
        if(top!=n-1)puts("NONE");
        else{
            memset(mark,0,sizeof(mark));
            cnt=0;  DFS2(1);
            int ii=0,i;
            while(cnt<n-1){
                for(i=ii;i<n;i++){
                    if(mark[e[que[i]][0]]&&!mark[e[que[i]][1]]){
                        flag[que[i]]=2;
                        ii=i;
                        break;
                    }
                }
                if(i==n)break;
                int k=1;
                visit[e[que[i]][1]]=0;
                for(i=ii+1;i<n;i++){
                    if(!visit[e[que[i]][0]]){
                        flag[que[i]]=0;
                        visit[e[que[i]][1]]=0;
                        k++;
                    }
                }
                DFS2(e[que[ii]][1]);top=ii;
                for(i=1;i<=n;i++)
                    if(visit[i])DFS(i);
                if(top-ii!=k)break;
            }
            if(cnt!=n-1)puts("NONE");
            else{
                puts("YES");
                for(int i=0;i<m;i++)
                    if(flag[i]==1)
                        printf("%d ",i+1);
                puts("");
                for(int i=0;i<m;i++)
                    if(flag[i]==2)
                        printf("%d ",i+1);
                puts("");
            }
        }
        puts("");
    }
    return 0;
}
