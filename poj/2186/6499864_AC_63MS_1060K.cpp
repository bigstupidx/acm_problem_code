#include <cstdio>
#include <cstring>
struct edge{
    int to;
    edge *next;
}edg[100010],*vert[10002],*r_vert[10002];
int n,m,visit[10002],id[10002],order[10002],top,in[10002];
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
        if(!visit[p->to])
            DFS(p->to);
    }
    order[top++]=s;
}
void DFS_RG(int s){
    visit[s]=1;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next){
        if(!visit[p->to])
            DFS_RG(p->to);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        top=-1;
        memset(vert,0,sizeof(vert));
        memset(r_vert,0,sizeof(r_vert));
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
        memset(in,0,sizeof(in));
        for(int i=0;i<n;i++){
            for(edge *p=r_vert[i];p;p=p->next){
                if(id[i]!=id[p->to]){
                    in[id[p->to]]++;
                }
            }
        }
        int ans=0,cnt=0,k;
        for(int i=0;i<top;i++){
            if(in[i]==0){
                cnt++;
                k=i;
            }
        }
        if(cnt==1){
            for(int i=0;i<n;i++)
                if(id[i]==k)ans++;
            printf("%d\n",ans);
        }
        else
            puts("0");
    }
    return 0;
}
