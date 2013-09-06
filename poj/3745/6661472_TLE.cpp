#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int id;
    edge *next;
}edg[1000002],*vert[2002],*r_vert[2002];
int n,m,flag[1000002],cnt1,cnt2,mark[2002],visit[2002],e[1000002][2],que[1000002];
void add_edge(int x,int y,int id,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->id=id;
    p->next=vert[x];    vert[x]=p;
    
    p=&edg[++top];
    p->to=x;
    p->id=id;
    p->next=r_vert[y];  r_vert[y]=p;
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
        for(int i=1;i<=n;i++)visit[i]=0;
        cnt1=1;  DFS(1);
        if(cnt1!=n)puts("NONE");
        else{
            for(int i=1;i<=n;i++)mark[i]=0;
            cnt2=1;  DFS2(1);
            int tem=1;
            while(cnt2<n){
                int s,xx=-1,i;
                for(i=tem;i<cnt1;i++){
                    if(mark[e[que[i]][0]]&&!mark[e[que[i]][1]]){
                        s=e[que[i]][1];break;
                    }
                }
                flag[i]=2;DFS2(s);
                for(edge *p=r_vert[s];p;p=p->next){
                    if(visit[p->to]&&!flag[p->id]){
                        que[i]=p->id;
                        xx=1;
                        break;
                    }
                }
                if(xx==-1){cnt2--;break;}
                tem=i+1;
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
