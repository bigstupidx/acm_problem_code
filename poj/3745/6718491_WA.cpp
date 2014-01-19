#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int id;
    edge *next;
}edg[1000002],*vert[2002];
int n,m,top,cnt,que[2002],visit[2002],mark[2002],flag[1000002],e[1000002][2];
void add_edge(int x,int y,int id){
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
            que[top++]=p->id;
            //printf("%d ->%d \n",s,p->to);
            DFS(p->to);
        }
    }
}
void DFS2(int s){
    mark[s]=1;
    for(edge *p=vert[s];p;p=p->next){
        if(!mark[p->to]&&flag[p->id]==0){
            flag[p->id]=2;
            cnt++;
            //printf("%d ->%d \n",s,p->to);
            DFS2(p->to);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        int mm=0;top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)flag[i]=0;
        for(int i=1;i<=n;i++){
            int kk,to;
            scanf("%d",&kk);
            for(int j=0;j<kk;j++){
                scanf("%d",&to);
                add_edge(i,to,mm);
                //printf("%d -> %d %d\n",i,to,mm);
                e[mm][0]=i; e[mm][1]=to;
                mm++;
            }
        }
        memset(visit,0,sizeof(visit));
        top=0;  DFS(1);
        if(top!=n-1)puts("NONE");
        else{
            memset(mark,0,sizeof(mark));
            cnt=0;  DFS2(1);
            int ii=0,i,k;
            //printf("%d ",cnt);
            while(cnt<n-1){
                for(i=ii;i<n;i++){
                    if(mark[e[i][0]]&&!mark[e[i][1]]){
                        flag[i]=2;
                        ii=i;
                        break;
                    }
                }
                if(i==n)break;
                k=1;top=ii;
                visit[e[ii][1]]=0;
                for(i=ii+1;i<n;i++){
                    if(!visit[e[i][0]]){
                        k++;
                        flag[i]=0;
                        visit[e[i][1]]=0;
                    }
                }
                DFS2(e[ii][1]);
                stack<int>S;
                for(i=1;i<=n;i++)
                    if(visit[i])S.push(i);
                while(!S.empty()){
                    int s=S.top();S.pop();
                    for(edge *p=vert[s];p;p=p->next){
                        if(!visit[p->to]&&flag[p->id]!=2){
                            visit[p->to]=1;
                            flag[p->id]=1;
                            que[top++]=p->id;
                            S.push(p->to);
                        }
                    }
                }
                if(top-ii!=k)break;
            }
            if(cnt!=n-1)puts("NONE");
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
